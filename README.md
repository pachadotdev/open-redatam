# REDATAM CONVERTER

## About

Program for extracting raw information from REDATAM databases.
This program is a CLI adaptation of the original [redatam-converter](https://github.com/discontinuos/redatam-converter).

Redatam Converter is an open source project that lets you read Redatam databases in order to export their microdata. It was created to recover information of REDATAM databases for statistical analysis using standard tools such as SPSS, STATA, R, etc.

## Compatibility

The converter was tested with REDATAM databases of different versions.
The current version exports to comma separated files (CSV).

## Prerequisites

This program uses **Xerces-C++ XML Parser** and requires C++17 or higher to compile.
See [here](https://xerces.apache.org/xerces-c/) for download and installation guide.

We provide a script for Ubuntu users to install Xerces-C++ XML Parser. Run the following command:

```bash
bash dev/01-install-xerces.sh
```

## Installation

To install the program, run the following commands:

```bash
make
```

## Usage

To use the program, run the following command:

```bash
redatam input.dic(x) output-csv/
```

For the [Chilean Census 2017](https://redatam.org/cdr/descargas/censos/poblacion/CP2017CHL.zip), this would be `redatam downloads/CP2017CHL/BaseOrg16/CPV2017-16.dicx Chile_2017/`.

## Testing

Tested on Ubuntu 22.04.

Ticked = Passed; Blank = Failed

DIC files

- [ ] Argentina 2010 (`downloads/CP2010ARG/BASE_AMP_DPTO/CPV2010Ampliado.dic) *CORRUPT FILE*
- [ ] Bolivia 2001 CELADE (`downloads/CP2001BOL/Cp2001BOL/Celade/CPV2001BOL_Celade.dic`) *CORRUPT FILE*
- [x] Bolivia 2012 (`downloads/CP2012BOL/BaseMunicipio_V3/CPV2012Municipio.dic`)
- [x] Chile 2017 (`downloads/CP2017CHL/BaseOrg16/CPV2017-16.dic`)
- [x] Dominican Republic 2002 (`downloads/CP2002DOM/Cp2002DOM/BaseOriginal/CPV2002DOM.dic`)
- [x] Ecuador 2010 (`downloads/CP2010ECU/Base/CE11.dic`)
- [x] El Salvador 2007 (`downloads/CP2007SLV/CP2007SLV/BaseTotal/CPV2007ES.dic`)
- [x] Guatemala 2018 (`downloads/CP2018GTM/BasePub/CPV2018GT_BasePublica.dic`)
- [x] Mexico 2000 (`downloads/CP2000MEX/Cp2000MEX/BaseOriginal/cpmx2000.dic`)
- [x] Mexico 2010 (`downloads/CP2010MEX/BasePubM/MC10.dic`)
- [x] Myanmar 2014 (`downloads/CP2014MMR/Union.dic`)
- [ ] Peru 2010 (`downloads/CP2010PER/CP2007PER/BasePub/CPV2007PER_PUB.dic`) *CORRUPT FILE*
- [ ] Peru 2010 (`downloads/CP2010PER/CP2007PER/BasePub/CPV2007PER_PUB.dic`) *CORRUPT FILE*
- [ ] Peru 2017 (`downloads/CP2017PER/BaseD/BaseR/CPVPER2017D.dic`) *CORRUPT FILE*
- [ ] Uruguay 2011 (`downloads/CP2011URY/BaseRPub/CPV2011_uruguay_publica.dic`) *CORRUPT FILE*

DICX files

- [x] Argentina 2010 (`downloads/CP2010ARG/BASE_AMP_DPTO/CPV2010Ampliado.dicx`)
- [ ] Bolivia 2001 (`downloads/CP2001BOL/Cp2001BOL/BaseOriginal/CPV2001.dicx`)
- [ ] Bolivia 2001 CELADE (`downloads/CP2001BOL/Cp2001BOL/Celade/CPV2001BOL_Celade.dicx`)
- [x] Bolivia 2012 (`downloads/CP2012BOL/BaseMunicipio_V3/CPV2012Comunidad.dicx`)
- [x] Chile 2017 (`downloads/CP2017CHL/BaseOrg16/CPV2017-16.dicx`)
- [x] Dominican Republic 2002 (`downloads/CP2002DOM/Cp2002DOM/BaseOriginal/CPV2002DOM.dicx`)
- [x] Ecuador 2010 (`downloads/CP2010ECU/Base/cpv2010ecu.dicx`)
- [x] El Salvador 2007 (`downloads/CP2007SLV/CP2007SLV/BaseTotal/CPV2007ES.dicx`)
- [x] Mexico 2000 (`downloads/CP2000MEX/Cp2000MEX/BaseOriginal/cpmx2000.dicx`)
- [x] Mexico 2010 (`downloads/CP2010MEX/BasePubM/MC10.dicx`)
- [ ] Mexico 2010 CELADE (`downloads/CP2000MEX/Cp2000MEX/Celade/CPV2000MEX_Celade.dicx`)
- [x] Peru 2010 (`downloads/CP2010PER/CP2007PER/BasePub/CPV2007PER_PUB.dicx`)

## Credits

This Redatam Converter was created and is supported by Lital Barkai (barkailital@gmail.com) and Mauricio "Pacha" Vargas Sepulveda (m.sepulveda@mail.utoronto.ca).

The original converter was created by [Pablo De Grande](https://github.com/discontinuos). See [here](https://www.scielo.org.mx/scielo.php?script=sci_arttext&pid=S0186-72102016000300811) for more information.
