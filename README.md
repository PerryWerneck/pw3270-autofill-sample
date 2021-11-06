## Sample autofill plugin for pw3270.


[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

## Instalation

## Building for Linux

### Requirements

 * [lib3270](../../../lib3270)
 * [libv3270](../../../libv3270)

### Building

 * TODO

## Building for windows

### Cross-compiling on SuSE Linux (Native or WSL)

1. Add the MinGW Repositories

	```
	sudo zypper ar obs://windows:mingw:win32 mingw32
	sudo zypper ar obs://windows:mingw:win64 mingw64
	sudo zypper ar obs://home:PerryWerneck:pw3270 pw3270
	sudo zypper ref
	```
2. Get sources from git

	```shell
	git clone https://github.com/PerryWerneck/libipc3270.git ./libipc3270
	```

3. Install 64 bits cross compilers

	```shell
	./libipc3270/win/install-cross.sh --64
	```

3. Configure 64 bits build environment

        ```shell
        ./libipc3270/win/win-configure.sh --64
        ```

4. Build

	```shell
	cd libipc3270
	make clean
	make all
	```

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


