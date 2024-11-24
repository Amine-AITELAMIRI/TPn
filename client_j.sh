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
        echo "$req $id $args" > mini-facebook.pipe # Envoi au serveur via mini-facebook.pipe
    fi 
done 