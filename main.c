#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include "replaceSpace.h"


typedef int (*fun_ptr)(int,int); 
typedef int (*atoi_ptr)(const char*);

int add(int a, int b){
    return a+b;
}

int computeWithString (const char* x, const char* y, atoi_ptr toInteger, fun_ptr add){
    return add(toInteger(x), toInteger(y));
}

int compute(int x, int y, fun_ptr add){
    return add(x, y);
}

int toInteger (const char* nptr){
    int c;
    int total;
    int sign;

    /*跳过空格*/
    while(isspace((int)(unsigned char)*nptr))
        nptr++;

    c = (int)(unsigned char)*nptr++;
    sign = c;
    if(sign == '-' || sign == '+')
        c = (int)(unsigned char)*nptr++;

    total = 0;
    while (isdigit(c))
    {
        /* code */
        total = total*10 + (c-'0');
        c = (int)(unsigned char)*nptr++;
    }

    if (sign == '-')
    {
        /* code */
        return -total;
    }else{
        return total;
    }
    
    
}

/* ANSI标准形式的声明方式，括号内的省略号表示可选参数 */  
int demo(char *msg, ... )  
{  
    va_list argp;                    /* 定义保存函数参数的结构 */  
    int argno = 0;                    /* 纪录参数个数 */  
    char *para;                        /* 存放取出的字符串参数 */                                      
    va_start( argp, msg );          /* argp指向传入的第一个可选参数，      msg是最后一个确定的参数 */  
    printf("Parameter #0 is: %s\n",  msg); 
    while (1) 
    {  
        para = va_arg( argp, char *);                 /*      取出当前的参数，类型为char *. */  
        if ( strcmp( para, "/0") == 0 )  
                                                      /* 采用空串指示参数输入结束 */  
            break;  
        printf("Parameter #%d is: %s\n", ++argno, para);   
    }  
    va_end( argp );                                   /* 将argp置为NULL */  
    return 0;  
}



int main(int argc, char const *argv[])
{
    /* 函数调用 */
    
    // printf("参数个数=%d\n",argc);
    // for(int i=0;i<argc;i++){
    //     printf("%s ",argv[i]);
    // }

    // extern int count;
    // printf("count is: %d", count);

    // int  a[5]={ 1,2,3,4,5 };    //定义一个一维数组 a
    // int  (*prt)[5];      // 步长为 5 的数组指针，即 prt 指向的数组里有 5 个元素  
    // prt=&a;    // 把数组 a 的地址付给 prt，则 prt 为数组 a 的地址，*prt 表示数组 a 本身
    // prt[0];   //表示数组首元素的地址
    // *prt[0];     //表示数组的首元素的值，即为数组 a 的 1
    // **prt;         //表示数组的首元素的值，即为数组 a 的 1
    // *prt[1] ;   //表示指向数组的下一行元素的首元素的值，但是a是一维数组，只有一行，所以指向的地址中的值不确定
    // for (int i = 0; i < 5; i++)
    // {
    //     /* code */
    //     printf("%d\n", (*prt)[i]);
    // }

    // if(argc==3){
    //     printf("%d\n", computeWithString(argv[1], argv[2], toInteger, add));
    // }
    
    // if(argc == 1){
    //     printf("File :%s\n", __FILE__ );
    //     printf("Date :%s\n", __DATE__ );
    //     printf("Time :%s\n", __TIME__ );
    //     printf("Line :%d\n", __LINE__ );
    //     printf("ANSI :%d\n", __STDC__ );
    // }
    
    // FILE * pf;
    // int errnum;
    // pf = fopen ("unexist.txt", "rb");
    // if (pf == NULL)
    // {
    //     errnum = errno;
    //     fprintf(stderr, "错误: %d\n", errno);
    //     perror("通过 perror 输出错误");
    //     fprintf(stderr, "打开文件错误: %s\n", strerror( errnum ));
    // }
    // else
    // {
    //     fclose (pf);
    // }

    demo("DEMO", "This", "is", "a", "demo!" ,"333333", "/0");  

    return 0;
}
