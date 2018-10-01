# MATH-X Library

Math-x library comes with various maths functions out of the box.


## Install Instruction

### Dependencies

We require the following packages before you try installing the package.

 - A c++ compiler (g++/clang++/msvc++)
 - Cmake (upwards of version 3.4)
 - pkg-config (optional)

### Instructions

 - Create a build folder inside of main directory.

 ```
 $ mkdir build && cd build
 ```

 - Use the cmake command with CMAKE_INSTALL_PREFIX to select the directory to install to (not using this command will defaul to install directories)
 We do not support in tree builds.

 ```
 $ cmake .. -DCMAKE_INSTALL_PREFIX=/path/to/install
 ```

 For example, one can type:

 ```
 $ cmake -DCMAKE_INSTALL_PREFIX=/home/user/opt/build
 ```

 - If cmake runs successfully, you should now be able to see a `Makefile` in the build directory. We currently support `clean` and `all` only. We will add more targets with future upgrades to cmake. Run:

 ```
 $ make
 ```

 This should build the library successfully. To install the library to the specified directory run:

 ```
 $ make install
 ```

 - To build mathx based applications using terminal/makefile, we highly recommend using pkg-config. To use pkg-config, you will have
 to `export` pkg-config path. Run:

 ```
 $ export PKG_CONFIG_PATH=${PKG_CONFIG_PATH}:/path/to/install/lib/pkgconfig
 ```

 __NOTE__: If you fail to provide the CMAKE_INSTALL_PREFIX, install location will be set to default (For example: /usr/local/ in case of Linux users.)

## Usage Instructions

The user can simply build applications using pkg-config. A simple example is given as:

```
(CXX_COMPILER) -o exec_name (CXX_FILES) `pkg-config --cflags --libs mathx`
```