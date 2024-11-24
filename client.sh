#!/bin/bash

if [ -z "$1" ]; then 
    echo "nok please provide an identifier"
    exit 1 
fi

id="$1"

while true; do 
    read req args
    
    if [ ! -z "$req" ]; then 
        echo "$req $id $args"
    fi 
done 