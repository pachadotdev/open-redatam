#!/bin/bash

# adapted from https://xerces.apache.org/xerces-c/install-3.html

if [ -d "xerces" ]; then
  echo "Xerces directory already exists. Skipping the installation."
  exit 0
fi

mkdir -p downloads

wget https://dlcdn.apache.org/xerces/c/3/sources/xerces-c-3.2.5.tar.gz -O downloads/xerces-c-3.2.5.tar.gz

wget https://dlcdn.apache.org/xerces/c/3/sources/xerces-c-3.2.5.tar.gz.sha256 -O downloads/xerces-c-3.2.5.tar.gz.sha256

# Check the hash
echo "Checking the hash..."

CHECKSUM=$(cat downloads/xerces-c-3.2.5.tar.gz.sha256 | awk '{print $1}')

if [[ "$OSTYPE" == "darwin"* ]]; then
  echo "$CHECKSUM  downloads/xerces-c-3.2.5.tar.gz" | shasum -a 256 -c -
else
  echo "$CHECKSUM  downloads/xerces-c-3.2.5.tar.gz" | sha256sum -c -
fi

if [ $? -eq 0 ]; then
  echo "Hash matched!"
else
  echo "Hash mismatched!"
  exit 1
fi

tar -xf downloads/xerces-c-3.2.5.tar.gz

cd xerces-c-3.2.5

./configure --prefix=$(pwd)/../xerces

make -j8

make install

cd ..
