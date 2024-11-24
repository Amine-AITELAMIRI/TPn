#!/bin/bash

while true; do 
    read req id args
    
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
done 