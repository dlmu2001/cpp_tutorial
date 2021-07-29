
# sequence container使用的demo 

# 使用方式
  * mkdir build
  * cd build
  * cmake ..
    如果是要编译debug版本（带-g参数），则
    `cmake .. -DCMAKE_BUILD_TYPE=Debug`

    如果是交叉编译环境，则
    `CROSS_COMPILE=1 TOOLCHAIN=~/toochain/build/sysroots/x86_64-pokysdk-linux/usr/bin/aarch64-poky-linux TOOLCHAIN_ROOT=~/toolchain/build/sysroots/aarch64-poky-linux SYSROOT_PATH=~/project/symbols cmake -DTOOLCHAIN_PREFIX=aarch64-poky-linux ..`
  * make

# 说明
  * `set(CMAKE_TOOLCHAIN_FILE ./toolchain.cmake)`设置了toolchain设置文件，注意要放在PROJECT声明前面
  * 源代码放在专门的src目录
  * 使用C++ 14 `set(CMAKE_CXX_STANDARD 14)`
  * cmake使用MESSAGE打log
  * 交叉编译环境，要设置环境变量CROSS_COMPILE=1，设置TOOLCHAIN，也就是交叉编译器所在的位置，设置TOOLCHAIN_ROOT，就是c++内置的一些头文件(比如stdio.h）路径，设置rootfs路径(系统路径，会有一些runtime lib的头文件和so会访问到), 设置CMAKE变量TOOLCHAIN_PREFIX，也就是交叉编译器的前缀

