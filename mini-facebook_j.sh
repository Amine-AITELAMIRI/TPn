#!/bin/bash

pipe="mini-facebook.pipe"

[ ! -p $pipe ] && mkfifo $pipe

exec 3<>"$pipe"

trap 'rm -f $pipe; exit 0' INT

while true; do 
    if read line <&3; then # Lecture depuis mini-facebook.pipe
        req=$(echo $line | awk '{print $1}')
        id=$(echo $line | awk '{print $2}')
        args=$(echo $line | cut -d ' ' -f3-)

        case $req in 
            create)
                ./P.sh "$id.lock"
                ./create.sh "$id" &
                ./V.sh "$id.lock" ;;
            add)
                ./P.sh "$id.lock"
                ./add-friend.sh "$id" $args &
                ./V.sh "$id.lock" ;;
            post)
                receiver=$(echo $args | awk '{print $1}')
                ./P.sh "$receiver.lock"
                ./post-message.sh "$id" $args &
                ./V.sh "$receiver.lock" ;;
            display)
                ./P.sh "$id.lock"
                ./display-wall.sh "$id" &
                ./V.sh "$id.lock" ;;
            *)
                echo "nok bad request";;
        esac
    fi 
done