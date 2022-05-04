// 以下代码使用强制类型转换来访问和打印不同类型对象的字节表示
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len){
    int i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n\n");
}

void show_int(int x){
    printf("int::");
    show_bytes((byte_pointer) &x, sizeof(int));
   
}

void show_float(float x){
    printf("float::");
    show_bytes((byte_pointer) &x, sizeof(float));
    
}

void show_pointer(void *x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val){
    int ival = val;
    float fval = (float)ival;
    int *pval = &val;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}


int main(){
    test_show_bytes(12345);

    show_bytes("12345", 6);
    // 练习题2.7
    // const char *s = "abcdef";
    // show_bytes((byte_pointer)s, strlen(s));
    return 0;
}