#!/bin/bash

if [ -z "$1" ]; then
    echo "nok please provide an identifier" >"$2.pipe"
    exit 1
fi

id="$1"

./P.sh "$id.lock"

if [ -d "$id" ]; then
    if [ -f "$id/friends" ]; then
        echo "nok user '$id' already exists" >"$2.pipe"
    else
        echo "nok user '$id' is in creation" >"$2.pipe"
    fi
else
    mkdir "$id"
    touch "$id/wall" "$id/friends"
    echo "ok" >"$2.pipe"
fi

./V.sh "$id.lock"