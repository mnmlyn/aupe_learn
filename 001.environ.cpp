/**
 * 编译方法gcc <filename>
 * 1. ./a.out 1 2 3 444查看对于命令行参数的解析
 * 2. getenv获取环境变量值（stdlib.h）
 * 3、直接通过environ获取环境变量表(unistd.h),命令export可以查看环境变量
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char **argv) {
    int i;
    //1.
    for (i = 0; i < argc; ++i) {
        printf("argv[%d]=%s\n", i, argv[i]);
    }
    //2.
    printf("env path=%s\n", getenv("PATH"));
    //3.
    char **pp = environ;
    while (*pp) {
        printf("declare -x %s\n", *pp);
        ++pp;
    }
    return 0;
}
