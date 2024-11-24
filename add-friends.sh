#!/bin/bash

if [ ! -f "$1/friends" ]; then
    echo "nok user '$1' does not exist"
    exit 1
fi

if [ ! -f "$2/friends" ]; then
    echo "nok user '$2' does not exist"
    exit 1
fi

if grep -q "^$2$" "$1/friends"; then
    echo "nok user '$2' is already a friend of '$1'"
else
    echo "$2" >> "$1/friends"
    echo "ok"
fi