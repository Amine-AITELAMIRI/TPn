#!/bin/bash

if [ -z "$1" ]; then
    echo "nok please provide an identifier"
    exit 1
fi

id="$1"
pipe="$id.pipe"

# Création du tube nommé pour le client
[ ! -p $pipe ] && mkfifo $pipe

# Redirection avancée pour éviter les blocages intempestifs
exec 3<>"$pipe"

trap 'rm -f $pipe; exit 0' INT # Suppression du tube à la fermeture

while true; do 
    read req args
    if [ ! -z "$req" ]; then 
        echo "$req $args"
    fi 
done