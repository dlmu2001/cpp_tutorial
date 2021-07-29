
# 熟悉gcc -pg选项和gprof的使用 

# 使用方式
  * mkdir build
  * cd build
  * `cmake .. 
  * make
  * `./bin/hello` 生成gmon.out
  * `gprof bin/hello gmon.out > report.txt` 可以生成报告

# 说明
  * 编译选项加`-pg`
  * 参考https://www.cnblogs.com/Robotke1/archive/2013/05/11/3072888.html

