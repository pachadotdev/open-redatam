#!/bin/bash

# adapted from https://xerces.apache.org/xerces-c/install-3.html

mkdir -p downloads

wget https://dlcdn.apache.org/xerces/c/3/sources/xerces-c-3.2.5.tar.gz -O downloads/xerces-c-3.2.5.tar.gz

wget https://dlcdn.apache.org/xerces/c/3/sources/xerces-c-3.2.5.tar.gz.sha256 -O downloads/xerces-c-3.2.5.tar.gz.sha256

# Check the hash
echo "Checking the hash..."

CHECKSUM=$(cat downloads/xerces-c-3.2.5.tar.gz.sha256 | awk '{print $1}')
echo "$CHECKSUM  downloads/xerces-c-3.2.5.tar.gz" | sha256sum -c -

if [ $? -eq 0 ]; then
  echo "Hash matched!"
else
  echo "Hash mismatched!"
  exit 1
fi

tar -xf downloads/xerces-c-3.2.5.tar.gz

mkdir -p build/xerces

cd xerces-c-3.2.5

./configure --prefix=$(pwd)/../build/xerces

make -j8

make install

cd ..

rm -rf xerces-c-3.2.5
