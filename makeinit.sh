#!/bin/bash

for i in {1..15}; do 
    cp ./Makefile ./var$i/ 
    echo "Creating a Makefile for: var$i"
done

echo "Deleting basic Makefile"
rm ./Makefile
echo "Done!"