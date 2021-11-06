## Sample autofill plugin for pw3270.


[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

## Instalation

## Building for Linux

### Requirements

 * [lib3270](../../../lib3270)
 * [libv3270](../../../libv3270)

### Building

## Building for windows

### Cross-compiling on SuSE Linux (Native or WSL)

TODO

### Windows native with MSYS2

1. Build and install [libv3270](../../../libv3270)

2. Get sources from git

	```shell
	git clone https://github.com/PerryWerneck/pw3270-autofill-sample.git ./autofill
	```

4. Build library using the mingw shell

	```shell
	cd autofill
	./autogen.sh
	make all
	```
5. Install

	```shell
	make install
	```


