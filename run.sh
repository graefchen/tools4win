#!/bin/bash

cd src
files=$(find . -type f -name "*.c")

for file in $files
do
	echo "Making ${file%.c}.exe"
	clang -O3 $file -o ../bin/${file%.c}.exe
	echo "Created ${file%.c}.exe"
	echo ""
done
cd ..
