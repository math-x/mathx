# MATH-X Library

Math-x library comes with various maths functions out of the box.


## Install Instruction

###Dependencies

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
