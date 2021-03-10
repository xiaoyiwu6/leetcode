#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <stdarg.h>
#include "replaceSpace.h"
#include "linkList.h"
#ifndef _STDLIB_H_
#define _STDLIB_H_

#include <stdlib.h>

#endif


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

/**完美乘法，a*b=c,abc 中只出现 0~9 的数字，且每个数字在这个等式中只出现 一遍。*/
void perfectMultiple(){
    int count=0;//记录符合条件的式子数
    int i,j,k,y,t,key;//迭代用
    int digit[10];//0-9数字计数数组
    int x[3];//记录abc的值

    //a和b的值的循环
    for(i=1; i<99;i++){
        for(j=102; j<9876; j++){
            //置零digit
            for(k=0;k<10;k++) digit[k] = 0;
            //分析0-9数字出现次数
            x[0] = i; x[1] = j; x[2] = i*j;
            for(k=0;k<3;k++){
                y = x[k];
                while (y)
                {
                    t = y%10;
                    digit[t]++;
                    y /= 10;
                }
            }
            //判断符合完美乘法,打印输出
            key = 0;
            for(k=0;k<10;k++)if(digit[k]!=1)key++;
            if(key == 0) printf("[%2d]%d * %d = %d\n",++count,i,j,i*j);
        }
    }
}

/**汉诺塔*/
//a,b,c分别代表三个柱，该函数的意义在于借助b柱将n个盘从a柱移动到c柱
void move(int n,int a, int b, int c){
    if(n==1) printf("%c->%c\n",a,c);
    else{
        move(n-1,a,c,b);
        printf("%c->%c\n",a,c);
        move(n-1,b,a,c);
    }
}
void Hanoi(int n){
    move(n,'a','b','c');
}

void swap(char** pa, char** pb) {char* temp; temp=*pa; *pa=*pb; *pb=temp; }


struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };


struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(preorderSize==0) return NULL;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = *preorder;
    int llen,rlen;//计算左右子树序列长度
    for(llen=0;llen<inorderSize&&inorder[llen]!=*preorder;llen++);
    rlen = inorderSize-1-llen;
    node->left =  buildTree(preorder+1,llen,inorder,llen);
    node->right = buildTree(preorder+1+llen,rlen,inorder+1+llen,rlen);
    return node;
}
void preorder_display(struct TreeNode* node){
    if(node!=NULL){
        printf("%d ",node->val);
        preorder_display(node->left);
        preorder_display(node->right);
    }
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

    // demo("DEMO", "This", "is", "a", "demo!" ,"333333", "/0");  
    // MyLinkedList* obj = myLinkedListCreate();
    // myLinkedListAddAtHead(obj, 7);
    // myLinkedListAddAtHead(obj, 2);
    // myLinkedListAddAtHead(obj, 1);
    // myLinkedListAddAtIndex(obj,3,0);
    // myLinkedListDeleteAtIndex(obj,2);
    // myLinkedListAddAtHead(obj, 6);
    // myLinkedListAddAtTail(obj, 1);
    // int param_1 = myLinkedListGet(obj,0);
    // myLinkedListAddAtHead(obj,4);
    // myLinkedListAddAtIndex(obj,5,0);
    // myLinkedListAddAtHead(obj,6);
    return 0;
}
