[![Version](https://img.shields.io/pypi/v/cbxp?label=alpha)](https://pypi.org/project/cbxp/#history)
[![Python Versions](https://img.shields.io/pypi/pyversions/cbxp)](https://pypi.org/project/cbxp/)
[![Downloads](https://img.shields.io/pypi/dm/cbxp)](https://pypistats.org/packages/cbxp)

![CBXP Logo](https://raw.githubusercontent.com/ambitus/cbxp/refs/heads/main/logo.svg)

# CBXP (Control Block EXPlorer) 

A unified and standardized interface for extracting z/OS control block data.

## Description

z/OS Control Blocks are in-memory data structures that describe and control countless process, operating system components, and subsystems. Control blocks are unbiquitous, but not very straight forward to access and extract information from. The mission of CBXP *(Control Block EXPlorer)* is to make extracting z/OS control block data straight forward and easy. CBXP accomplishes this by implementing a C/C++ XPLINK ASCII interface for extracting control blocks and post processing them into JSON. This makes it straight forward to integrate with industry standard programming languages and tools, which generally have well documented and understood foreign language intefaces for C/C++, and native and or third party JSON support that makes working with JSON data easy.

CBXP is the successor to the existing [cbxplorer](https://github.com/ambitus/cbexplorer) project. CBXP mainly improves upon this existing work by being implementing in C/C++ so that it is not limited to a specific programming language or tool. CBXP also focuses heavily on providing an interface that is simple and straight forward to use.

You can find information about system level control blocks in the [z/OS MVS Data Areas](https://www.ibm.com/docs/en/zos/3.1.0?topic=zos-mvs) documentation.

## Getting Started

### Minimum z/OS & Language Versions
Currently, CBXP is being developed on **z/OS 3.1**. We hope to eventually support all z/OS versions that are fully supported by IBM.
* [z/OS Product Lifecycle](https://www.ibm.com/support/pages/lifecycle/search/?q=5655-ZOS,%205650-ZOS)

All versions of the **IBM Open Enterprise SDK for Python** that are fully supported by IBM are supported by CBXP.
* [IBM Open Enterprise SDK for Python Product Lifecycle](https://www.ibm.com/support/pages/lifecycle/search?q=5655-PYT)

### Dependencies
* **z/OS Language Environment Runtime Support**: CBXP is compiled using the **IBM Open XL C/C++ 2.1** compiler, which is still fairly new and requires **z/OS Language Environment** service updates for runtime support.
  * More information can be found in section **5.2.2.2 Operational Requisites** on page **9** in the [Program Directory for IBM Open XL C/C++ 2.1 for z/OS](https://publibfp.dhe.ibm.com/epubs/pdf/i1357012.pdf).

### Supported Control Blocks
Currently, CBXP supports the following system level control blocks. CBXP also currently only supports extracting control blocks from memory *(storage)*. We plan on adding support for extracting control blocks from data sets/files and extracting control blocks based on a user defined JSON schema. We also plan on continuously expanding upon the following list of natively supported control blocks. The community is encouraged to assist in these efforts. See the [Contribution Guidelines](https://github.com/ambitus/cbxp/blob/main/CONTRIBUTING.md) for more details.

* `psa`
* `cvt`
* `ecvt`
* `asvt`
* `ascb`

### Python Interface
A python binding for CBXP is available for installation via [PyPi](https://pypi.org/project/cbxp/) or download via [GitHub](https://github.com/ambitus/cbxp/releases).

#### Python Installation *(PyPi)*
```shell
python3 -m pip install cbxp
```

#### Python Usage
```python3
from cbxp import cbxp
psa = cbxp("psa")
```

### Shell Interface
A shell-based CLI for CBXP is available for download via [GitHub](https://github.com/ambitus/cbxp/releases).

#### Installation *(GitHub)*
Wherever you install/extract the CBXP pax file, make sure to add the path to the `bin` directory where the `cbxp` executable resides to `PATH` in `/etc/profile` *(global)* or `~/.profile`/`~/.bashrc` *(local/individual)*.

#### Shell Usage
```shell
cbxp psa
```

## Help
* [GitHub Discussions](https://github.com/ambitus/cbxp/discussions)

## Authors
* Leonard J. Carcaramo Jr: lcarcaramo@ibm.com
* Elijah Swift: elijah.swift@ibm.com
* Varun Chennamadhava: varunchennamadhava@ibm.com

## Maintainers
* Leonard J. Carcaramo Jr: lcarcaramo@ibm.com
* Elijah Swift: elijah.swift@ibm.com
* Varun Chennamadhava: varunchennamadhava@ibm.com
