# REDATAM Converter (Python Package) <img src="man/figures/logo.svg" align="right" height="139" alt="" />

[![Standalone C++ app](https://github.com/pachadotdev/redatam-converter/actions/workflows/build-cpp.yml/badge.svg)](https://github.com/pachadotdev/redatam-converter/actions/workflows/build-cpp.yml)
[![R Package](https://github.com/pachadotdev/redatam-converter/actions/workflows/build-rpkg.yml/badge.svg)](https://github.com/pachadotdev/redatam-converter/actions/workflows/build-rpkg.yml)

## About

The REDATAM Converter is a software for extracting raw information from REDATAM databases.

For the standalone C++ command line application, see the [main directory](https://github.com/pachadotdev/redatam-converter/) of this repository.

Install the Python package an end user using conda (see step 1 [here](https://github.com/pachadotdev/my-python-journey/) to install miniconda):

```
git clone https://github.com/pachadotdev/redatam-converter.git
cd redatam-converter/pypkg

conda create -n "redatam" python=3.8.0 ipython
conda activate redatam
conda install pandas numpy chardet pybind11

pip install --use-pep517 .
```

As a developer, be sure to delete the previous build after doing changes and re-installing:

```bash
rm -rf build dist redatam.egg-info
pip install --use-pep517 .
```

## Usage

For the [Chilean Census 2017](https://redatam.org/cdr/descargas/censos/poblacion/CP2017CHL.zip), run the following command:

```python
import redatam
redatam.read_redatam("CP2017CHL/BaseOrg16/CPV2017-16.dicx")
```

Please read the vignette for a more detailed explanation and how this package can be used in conjunction with `dplyr` and other packages.

## Differences with the C++ standalone application

The Python package used a copy-and-paste of the C++ code to read the REDATAM databases. Then some parts were rewritten to use [pugixml](https://github.com/zeux/pugixml), which is header-only, as a replacement of Apache Xerces that requires a separate compilation. The code was refactored to use C++11 instead of C++17 with minimal variation.

These changes allow to use the Python package on multiple platforms and without a special C++17 setup, which is not supported on all systems that can run Python.

## Credits

This REDATAM Converter was created and is supported by Lital Barkai (barkailital@gmail.com).

The tests, installation instructions and Python package were created by Mauricio "Pacha" Vargas Sepulveda (m.sepulveda@mail.utoronto.ca)

The original converter was created by [Pablo De Grande](https://github.com/discontinuos). See [here](https://www.scielo.org.mx/scielo.php?script=sci_arttext&pid=S0186-72102016000300811) for more information.