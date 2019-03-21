/**
 * 编译方法gcc <filename>
 * 1. ./a.out 1 2 3 444查看对于命令行参数的解析
 * 2. getenv获取环境变量值（stdlib.h）
 * 3、直接通过environ获取环境变量表(unistd.h),命令export可以查看环境变量
 * 4. putenv设置环境变量（stdlib.h）强制覆盖
 * 5. setenv设置环境变量，第三个参数可选择是否overwrite(stdlib.h)
 * 6. unsetenv删除指定的环境变量(stdlib.h)
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>//for memcpy

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
    //4.
    char env_arr[] = "OLDPWD=/home";
    char *envp = (char *)malloc(sizeof(env_arr));//don't free, please!
    memcpy(envp, env_arr, sizeof(env_arr));
    putenv(envp);//see man putenv,不同版本，有的复制，有的直接使用
    printf("env OLDPWD = %s\n", getenv("OLDPWD"));
    //5.
    setenv("OLDPWD", "/", 0);
    printf("env OLDPWD = %s\n", getenv("OLDPWD"));
    setenv("OLDPWD", "/", 1);
    printf("env OLDPWD = %s\n", getenv("OLDPWD"));
    //6.
    unsetenv("OLDPWD");
    printf("env OLDPWD = %s\n", getenv("OLDPWD"));
    return 0;
}
