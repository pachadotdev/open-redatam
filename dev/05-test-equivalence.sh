#!/bin/bash

zip_files=(
  "downloads/CP2010ARG.zip"
  "downloads/CP2012BOL.zip"
  "downloads/CP2017CHL.zip"
  "downloads/CP2002DOM.zip"
  "downloads/CP2010ECU.zip"
  "downloads/CP2007SLV.zip"
  "downloads/CP2000MEX.zip"
  "downloads/CP2010MEX.zip"
  "downloads/CP2010PER.zip"
  "downloads/CP2011URY.zip"
)

for zip_file in "${zip_files[@]}"; do
  filename=$(basename "$zip_file" .zip)
  if [ ! -d "downloads/$filename" ]; then
    echo "Extracting $zip_file..."
    unzip "$zip_file" -d "downloads/$filename"
  else
    echo "Directory downloads/$filename already exists, skipping extraction."
  fi
done

dicx_files=(
  "downloads/CP2010ARG/BASE_AMP_DPTO/CPV2010Ampliado.dicx"
  "downloads/CP2012BOL/BaseMunicipio_V3/CPV2012Comunidad.dicx"
  "downloads/CP2017CHL/BaseOrg16/CPV2017-16.dicx"
  "downloads/CP2002DOM/Cp2002DOM/BaseOriginal/CPV2002DOM.dicx"
  "downloads/CP2010ECU/Base/cpv2010ecu.dicx"
  "downloads/CP2007SLV/CP2007SLV/BaseTotal/CPV2007ES.dicx"
  "downloads/CP2000MEX/Cp2000MEX/BaseOriginal/cpmx2000.dicx"
  "downloads/CP2010MEX/BasePubM/MC10.dicx"
  "downloads/CP2010PER/CP2007PER/BasePub/CPV2007PER_PUB.dicx"
  "downloads/CP2011URY/BaseRPub/CPV2011_uruguay_publica.dicX"
)

for dicx_file in "${dicx_files[@]}"; do
  dirname=$(dirname "$dicx_file")
  dirname=$(echo "$dirname" | cut -d'/' -f1,2)
  filenamenoext=$(basename "$dicx_file" .dicx)
  filenamenoext=$(echo "$filenamenoext" | sed 's/\.dicX//')

  dirname="$dirname/$filenamenoext-redatam-converter-cpp/"
  mkdir -p "$dirname"
  
  if [ $(ls -1 "$dirname" | wc -l) -eq 0 ]; then
    echo "Converting $dicx_file..."
    ./redatam "$dicx_file" "$dirname"
  else
    echo "Directory $dirname already has files, skipping conversion."
  fi
done
