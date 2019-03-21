/**
 * 1. 进程结束exit函数和_exit函数
 * exit函数，stdlib.h，执行注册的进程终止处理函数，执行文件IO善后，保证数据被更新到设备，返回内核
 * _exit函数，unistd.h，直接返回内核
 * 2. atexit函数，注册终止处理函数，无参
 * 3. on_exit函数，注册终止处理函数，带参数的，第一个参数是退出状态，第二个是自定义参数
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int func() {
    exit(1);
    //_exit(1);//使用_exit，而不是exit时，不会调用注册的终止处理函数
}

void func1() {
    printf("func1\n");
}

void func2() {
    printf("func2\n");
}

void func3(int status, void *arg) {
    printf("func3 status = %d\n", status);
    printf("func3 arg = %d\n", *((int *)arg));
}

int main(int argc, char **argv) {
    atexit(func1);
    atexit(func2);
    int i = 3;
    on_exit(func3, (void *)&i);
    func();
    return 0;
}

