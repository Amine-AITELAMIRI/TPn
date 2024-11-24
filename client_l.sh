#!/bin/bash

if [ -z "$1" ]; then 
    echo "nok please provide an identifier"
    exit 1 
fi

id="$1"
pipe="$id.pipe"

[ ! -p $pipe ] && mkfifo $pipe

exec 3<>"$pipe"

trap 'rm -f $pipe; exit 0' INT

while true; do 
    read req args
    
    if [ ! -z "$req" ]; then 
        echo "$req $id $args" > mini-facebook.pipe
        
        # Lire la réponse depuis le tube client ($id.pipe)
        if read response <&3; then 
            case $(echo $response | awk '{print $1}') in 
                start-of-file)
                    while read line <&3 && [ "$line" != "end-of-file" ]; do 
                        echo "$line"
                    done ;;
                ok)
                    echo "Command successfully executed";;
                nok)
                    msg=$(echo "$response" | cut -d ' ' -f2-)
                    echo "Error: $msg";;
            esac 
        fi 
    fi 
done 