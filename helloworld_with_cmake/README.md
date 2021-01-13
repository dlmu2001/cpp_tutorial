
# 用cmake组织的最简单的一个c++ helloworld, 代码在mac和linux验证过

# 使用方式
  * mkdir build
  * cd build
  * cmake ..
    如果是要编译debug版本（带-g参数），则
    `cmake .. -DCMAKE_BUILD_TYPE=Debug`
  * make

# 说明
  * `set(CMAKE_TOOLCHAIN_FILE ./toolchain.cmake)`设置了toolchain设置文件，注意要放在PROJECT声明前面
  * 源代码放在专门的src目录
  * 使用C++ 14 `set(CMAKE_CXX_STANDARD 14)`
  * cmake使用MESSAGE打log

