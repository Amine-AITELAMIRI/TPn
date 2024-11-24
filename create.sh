#!/bin/bash

if [ -z "$1" ]; then
    echo "nok please provide an identifier"
    exit 1
fi

id="$1"

if [ -d "$id" ]; then
    if [ -f "$id/friends" ]; then
        echo "nok user '$id' already exists"
    else
        echo "nok user '$id' is in creation"
    fi
else
    mkdir "$id"
    touch "$id/wall" "$id/friends"
    echo "ok"
fi