#!/bin/bash

id="$1"

if [ ! -f "$id/wall" ]; then
    echo "nok user '$id' does not exist"
    exit 1
fi

echo "start-of-file"
cat "$id/wall"
echo "end-of-file"