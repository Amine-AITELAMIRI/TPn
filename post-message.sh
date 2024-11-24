#!/bin/bash

sender="$1"
receiver="$2"
shift 2
message="$@"

if [ ! -f "$sender/friends" ]; then
    echo "nok user '$sender' does not exist"
    exit 1
fi

if [ ! -f "$receiver/friends" ]; then
    echo "nok user '$receiver' does not exist"
    exit 1
fi

if ! grep -q "^$sender$" "$receiver/friends"; then
    echo "nok user '$sender' is not a friend of '$receiver'"
else
    echo "$sender: $message" >> "$receiver/wall"
    echo "ok"
fi