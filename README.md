# MATH-X Library

Math-x library comes with various maths functions out of the box.


## Install Instruction

### Dependencies

We require the following packages before you try installing the package.

 - A c++ compiler (g++/clang++/msvc++)
 - Cmake (upwards of version 3.4)

### Instructions

 - Create a build folder inside of main directory.

 ```
 $ mkdir build && cd build
 ```

 - Use the cmake command with CMAKE_INSTALL_PREFIX to select the directory to install to (not using this command will defaul to install directories)

 ```
 $ cmake -DCMAKE_INSTALL_PREFIX=/path/to/install
 ```

 For example, one can type:

 ```
 $ cmake -DCMAKE_INSTALL_PREFIX=/home/user/mathx_build/
 ```

 - If cmake runs successfully, you should now be able to see a `Makefile` in the build directory. We currently support `clean` and `all` only. We will add more targets with future upgrades to cmake. Run:

 ```
 $ make
 ```

 This should build the library successfully. To install the library to the specified directory run:

 ```
 $ make install
 ```

 __NOTE__: If you fail to provide the CMAKE_INSTALL_PREFIX, install location will be set to default (For example: /usr/local/ in case of Linux users.)

## Usage Instructions

Currently we do not support pkg-config so users will have to manually add the `includes` and `lib` using their respective flags.

Manually building:

```
(CXX_COMPILER) -o exec_name (CXX_FILES) -I/path/to/include -L/path/to/lib
```

__NOTE__: You dont need to provide the last two flags if library is installed in the default location.

We are updating our CMakelists to provide more functionality to the users.
