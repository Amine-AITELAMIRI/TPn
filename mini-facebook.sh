#!/bin/bash

while true; do 
    read req id args
    
    case $req in 
        create)
            ./create.sh "$id" ;;
        add)
            ./add-friend.sh "$id" $args ;;
        post)
            ./post-message.sh "$id" $args ;;
        display)
            ./display-wall.sh "$id" ;;
        *)
            echo "nok bad request";;
    esac 
done 