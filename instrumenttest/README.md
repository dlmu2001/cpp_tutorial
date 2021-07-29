
# 测试gcc -finstument-functions的使用 

# 使用方式
  * mkdir build
  * cd build
  * `cmake .. -DCMAKE_BUILD_TYPE=Debug`
  * make
  * `./bin/hello` 生成mydbug.log
  * `../tran.sh bin/hello mydebug.log mydebug.txt` 生成函数名调用log 

# 说明
  * cmake使用debug编译，自动-g
  * gcc 编译选项加入 -finstrument-functions
  * 实现__cyg_profile_func_enter和__cyg_profile_func_exit函数，获取函数指针地址和caller指针地址,注意__attribute__((no_instrument_function))
  * addr2line将函数指针地址转化为函数名
  * 参考https://www.freesion.com/article/267559829/

