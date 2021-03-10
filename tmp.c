#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

/**快速排序*/
void quick_sort(int arr[], int start, int end){
    if(start<end){
        //划分
        int pivotpos = partition(arr, start, end);
        quick_sort(arr, start, pivotpos-1);
        quick_sort(arr, pivotpos+1, end);
    }
}
//根据pivot值划分arr
int partition(int arr[], int start, int end){
    int pivot = arr[start]; //把第一个值作为枢纽
    //根据pivot划分值到两边
    while(start<end){
        while(arr[end]>=pivot && start<end) --end;
        arr[start] = arr[end];
        while(arr[start<=pivot && start<end]) ++start;
        arr[end] = arr[start];
    }
    arr[start] = pivot;
    return start;
}

/**快排找第k个小 -- 解法一*/
int findKthByQuickSort(int arr[], int start, int end, int Kth){
    if(start>end || start>Kth-1 || end<Kth-1) return -1;
    int pivotpos = partition(arr,start,end);
    //三种情况，一是刚好找到返回，二是位置小于Kth返回后半部分，三是位置大于Kth返回前半部分
    if(pivotpos == (Kth-1)) return arr[Kth-1];
    if(pivotpos < (Kth-1)) return findKthByQuickSort(arr,pivotpos+1,end, Kth);
    if(pivotpos > (Kth-1)) return findKthByQuickSort(arr,start,pivotpos-1, Kth);
}

/**快排找第k个小 -- 解法二*/
int findKthByQuickSort2(int arr[], int start, int end, int Kth){
    quick_sort(arr,start,end);//先完全排列好
    return arr[Kth-1];
}

/**100 个人围成圈，从第一个人开始，1~3 报数，数到 3 的人退出，问剩下来的 人编号是多少？*/
int f(int n, int m){
    /**
     * 使用递归解法
     * 当对长度为n跨度为m的序列求解最后一个数时，首先排除掉m%n得到长度为n-1的序列。
     * 此时n-1长度的序列可以理解为长度为n的序列取走m%n后前后两部分互换后得到的序列。
     * 因此当n-1长度的序列最后一个数的坐标为x时，n长度的序列的目标数坐标为(m%n+x)%n即(m+x)%n
     * 同理对长度为n-1跨度为m的序列进行操作
     */
    if(n==1) return 0;
    int x = f(n-1,m);
    return (m+x)%n;
}
//求最后剩下及非递归版本,将递归用栈模拟出来即可得到当前循环
int lastRemaning(int n, int m, int isRecursive){
    if(isRecursive) return f(n,m);
    int f = 0;
    for (int i = 2; i != n + 1; ++i) {
            f = (m + f) % i;
        }
    return f;
}

/**输入10个数（包括整数和浮点数，个数不确定），存放在一个数组中
 * 1.按照从小到大的顺序输出整数，从大到小的顺序输出浮点数
 * 2.按照输出顺序将浮点数放到一个链表中
*/
//采用插入排序的思想
void sort_int(int num[], int n){
    int i,j,temp;
    for(i=0;i<n-1;i++)
        for ( j = i+1; j < n  ; j++)
            if(num[j]<num[i]){//从小到大
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
}

void sort_float(float num[], int n){
    int i,j;
    float temp;
    for(i=0;i<n-1;i++)
        for ( j = i+1; j < n  ; j++)
            if(num[j]>num[i]){//从大到小
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
}

/**最大公约数*/
int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}

/**旋转数组*/
//3次翻转数组
void reverse(int arr[],int low,int high){
    int temp;
    for(int i=low;i<=(low+high)/2;i++){
        temp = arr[i];
        arr[i] = arr[high-low+i];
        arr[high-low+i] = temp;
    }
}
//旋转数组
void rotate(int arr[], int Kth){
    int n = strlen(arr);
    reverse(arr, 0, n-1);
    reverse(arr, 0, Kth-1);
    reverse(arr, Kth, n-1);
}

/**逆序构建双向链表*/
typedef struct DNode{
    int data;
    struct DNode* pre;
    struct DNode* next;
}DNode,*DList;

//使用头插法实现逆序
void diverse_insert(){
    //创建头节点
    DList head = (DList)malloc(sizeof(DNode));
    head->data = -1; head->next = NULL; head->pre = NULL;
    //循环输入整数，0为结束表示
    int integer;
    scanf("%d", &integer);
    while(integer!=0){
        DNode* tmp = (DNode *)malloc(sizeof(DNode));
        tmp->data = integer;
        tmp->next = head->next; tmp->pre = head;//tmp前后分别指向头节点及其后置
        if(head->next) head->next->pre = tmp;//如果head存在后置节点要修改pre指向tmp
        head->next = tmp;//头节点后置指向tmp

        scanf("%d", &integer);//输入下一个整数
    }
    //打印链表
    DNode* cur = head->next;
    while(cur!=NULL){
        printf("%d ",cur->data);
        cur = cur->next;
    } 
}

/**凯撒加密*/
void caesar_cipher(char plaintext[], int len, int Kth){
    char small_letter[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}; 
    char big_letter[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for(int i=0;i<len;i++){
        if(plaintext[i]>='a' && plaintext[i]<='z') 
            plaintext[i] = small_letter[((int)(plaintext[i]-'a')+Kth)%26];
        else plaintext[i] = big_letter[((int)(plaintext[i]-'A')+Kth)%26];
    }
}

/**编写完整的程序，构造整数集合(其实就是一个整数链表)，并实现对该集合操作的若干功能：
 * 加入一个新元素
 * 判断某元素是否在集合内
 * 输出两个集合并集
 * 输出两个集合交集
 * 删除集合中某一元素。
 * struct set{int numb; struct set *next;}
 */
typedef struct set
{
    int numb;
    struct set* next;
}set;

#define MAX 0XFFFF

//创建集合
set* setCreate(){
    set* mySet = (set*)malloc(sizeof(set));
    mySet->numb=MAX; mySet->next = NULL;
    return mySet;
}

//验证是否在集合中，在则返回1，不在返回0
int isInSet(set* mySet, int val){
    set* cur = mySet->next;
    while(cur!=NULL)
        if(cur->next == val) return 1;
    return 0;
}

//向集合中添加元素,采用头插法
void setAdd(set* mySet, int val){
    if(isInSet(mySet, val)) return;
    set* tmp = (set*)malloc(sizeof(set));
    tmp->numb = val; tmp->next = mySet->next;
    mySet->next = tmp;
}

//输出两个集合并集
void unionSet(set* A, set* B){
    set* cur = A->next;
    //先打印A
    while(cur){
        printf("%d ", cur->numb);
        cur = cur->next;
    }
    //打印B
    cur = B->next;
    while(cur){
        if(!isInSet(A, cur->numb)) printf("%d ", cur->numb);
        cur = cur->next;
    }
}

//输出两个集合交集
void intersectionSet(set* A, set* B){
    set* cur = A->next;
    while(cur){
        if(isInSet(B,cur->numb)) printf("%d ", cur->numb);
        cur = cur->next;
    }
}

//删除集合中某一元素
void deleteSetAtVal(set* mySet, int val){
    set* cur = mySet->next;
    set* pre = mySet;
    while(cur){
        if(cur->numb == val){
            pre->next = cur->next;
            free(cur);
            break;
        }
        cur = cur->next;
    }
}

/**编写一个函数，从字符串中寻找整个连续的数字字符，将其转化成整数并保存在 arr 整型 
 * 数组里，溢出以-1 作为标志。字符串以‘#’结束（如"uestc2015jsj123#"）
 */
//将字符串转换为数字
int str2int(char *str, int len){
    int num=0;
    for(int i=0;i<len;i++)
        num = num*10 + str[i]-'0';
    return num;
}
//字符串中找到数字并转换
void int_find(int arr[], char* pc){
    char *p = pc, *q;
    int i=0;
    while(*p!='#'){
        //是数字则一直往下遍历
        if(*p>='0' && *p<='9'){
            q = p+1;
            while(*p>='0' && *p<='9') q++;
            arr[i++] = str2int(p, q-p);
            p = q;
        }
        else p++;
    }
    arr[i] = -1;
}

/**有两字符数组 s 和 t，求 t 在 s 中出现第一次的开始位置，如果没有则输出“No”， 有则输出开始位置。*/
int strstr(char s[], char t[]){
    int s_length = strlen(s);
    int t_length = strlen(t);
    int i,j;

    //从第一个位置开始匹配，匹配成功则输出
    for(i=0;i<s_length-t_length+1;i++){
        for(j=0;j<t_length && s[i+j] == t[j];j++);
        if(j==t_length) return i;
    }
    printf("No\n");
    return -1;
}

/**编写一个函数，把整数序列分成两个部分，使得左边部分都不大于右边部分， 不需要排序。 （ 考察的是快速排序的部分）*/
int partition(int arr[],int n){
    int pivot = arr[0];
    int low = 0,high = n-1;//上界为0下界为n-1
    //使得所有的值左右调转
    while(low<high){
        //先将右侧的值调转到左侧
        while(low<high && arr[high]>pivot) high--;
        arr[low] = arr[high];
        //再将左侧的值调转到右侧
        while(low<high && arr[low]<pivot) low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}

/**有 n 个人围成一圈，顺序排号。从第一个人开始报数（从 1 到 3 报数），凡 
 * +报到 3 的人退出圈子，问最后留下来的是原来第几号的那位（要求用指针知识实 现）。*/
int lastRemaining(int n, int m){
    if(n==1) return 0;//只剩下一个数字，返回其坐标0
    int x = lastRemaining(n-1,m);
    return (m+x)%n;
}
//非递归版本
int f(int n, int m){
    int x=0,i;
    for(i=2;i<=n;i++) x = (m+x)%i;
    return x;
}

/**有一行电文，已按下面规律译成密码： 
 * A→Z a→z 
 * B→Y b→y 
 * C→X c→x 
 * 即第 1 个字母变成第 26 个字母，第 i 个字母变成第（26 – i + 1）个字母。非 
 * 字母符号不变。要求编程序将密码译回原文，并输出密码和原文。*/
void transfer(char *cipher_char){
    char base;
    // if(isupper(*cipher_char)) base = 'A';
    // if(islower(*cipher_char)) base = 'a';
    if(*cipher_char>='A' && *cipher_char<='Z')  base = 'A';
    else if(*cipher_char>='a' && *cipher_char<='z')  base = 'a';
    else return ;

     *cipher_char = 25-(*cipher_char-base) + base;
}

/**输出金字塔图案*/
void print_pyramid(int n){
    int i,j;
    int blank,symbal;//空白数和符号数,空白数只需要打印前半部分所以是一半
    //打印上层
    for(i=1;i<=n;i++){
        symbal = 2*i-1;//每层符号数和层数的关系为2h-1：1、3、5、7、9
        blank = n-i;
        for(j=0;j<blank;j++) printf(" ");
        for(j=0;j<symbal;j++) printf("*");
    }
    //打印下层,反过来打印即可，注意少打印一层
    for(i=n-1;i;i++){
        symbal = 2*i-1;//每层符号数和层数的关系为2h-1：1、3、5、7、9
        blank = n-i;
        for(j=0;j<blank;j++) printf(" ");
        for(j=0;j<symbal;j++) printf("*");
    }
}

/**找出一个 2 维数组中的鞍点，即该位置上的元素在该行上最大、在该列上最 小。*/
void find_saddle_point(int *arr[], int m, int n){
    int count[m][n]; memset(count,0,sizeof(count));
    int i,j;
    int max,min;//用于得出每行每列最大最小的下标

    //行
    for(i=0;i<m;i++){
        max = 0;
        //找到每行最大值的下标
        for(j=1;j<n;j++) if(arr[i][j]>arr[i][max]) max = j;
        count[i][max]++;
    }
    //列
    for(j=0;j<n;j++){
        min=0;
        //找到每列最小值的下标
        for(i=1;i<m;i++) if(arr[i][j]<arr[min][j]) min = i;
        count[min][j]++;
    }
    //打印鞍点
    for ( i = 0; i < m; i++) for ( j = 0; j < n; j++) if(count[i][j]==2) printf("arr[%d][%d] = %d\n",i,j,arr[i][j]);    
}

/**设计候选人得票统计程序，要求有 4 个侯选人（分别是 Zhang 、Wang 、Li、 Zhao），选民每次输入一个被选人的姓名，最后统计出各人的得票结果*/
//省略变量名，这里不能用typedef，因为下面命名了数组并且赋值了，不能把一个参数重定义为一个值
struct{
    char name[20];
    int vote;
}candidate[4]={"Zhang",0,"Wang",0,"Li",0,"Zhao",0};

void vote(){
    int i,max=0;
    char can_name[20]="";
    //输入stop时表示结束
    while(!strcmp(can_name,"stop"))
    {
        gets(can_name);
        for(i=0;i<4;i++) if(!strcmp(can_name,candidate[i].name)) candidate[i].vote++;
    }
    for(i=1;i<4;i++) if(candidate[i].vote>candidate[max].vote) max = i;
    printf("Winner: %s",candidate[max].name);
}

/**定义一个结构体变量（包括年、月、日）。计算当天是本年中的第几天，注 
 * 意闰年问题。*/
typedef struct{
    int year;
    int month;
    int day;
}Date;
//闰年：1、能够被4整除不能被100整除 2、能被400整除
int is_leap_year(int year){
    return ((year%4==0 && year%100) || year%400==0);
}
//判断第几天
int date2count(Date date){
    int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int count=0;

    for(int i=0;i<date.month-2;i++) count+=months[i];//当前月不能算入
    if(date.month>2 && is_leap_year(date.year)) count++;//闰年且大于2月份加一
    count+=date.day;//加上当前月的日数
    
    return count;
}

/**用选择法实现对10个整数按从小到大的顺序排序输出（要求用指针实现）。*/
//整数型交换
void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

//选择排序
void selection_sort(int arr[], int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min = i;
        //每一轮对剩下数组进行选择排序
        for(j=i+1;j<n;j++)  if(arr[j]<arr[min]) min = j;
        swap(arr[i], arr[min]);
    }
}

/**用冒泡法实现对 10 个整数按从大到小的顺序排序输出（要求用指针实现）。*/
//冒泡排序
void bubble_sort(int arr[], int n){
    int i,j;

    for(i=0;i<n-1;i++)
        for(j=i;j<n-1;j++)  
            if(arr[j]>arr[j+1])     
                swap(arr[j],arr[j+1]);
}

//辗转相除法求最小公倍数和最大公约数
int gcd(int a, int b){
    return b?gcd(b,a%10):a;
}
int common(int a,int b){
    return a*b/gcd(a,b);
}

/**求 5+55+555+5555+55555 的值。（拓展输入一个数 a，求 a+ aa + aaa + aaaa + aaaaa）*/
int mutiple_plus(int a){
    int count=0,i;
    for (i = 1; i <= a; i++) count += i*a*pow(10,a-i);
    return count;
}

/**大概的意思就是输入一个字符串，将连续相同的字符删减为一个，以“*”结尾*/
void deduplication(){
    char old_char,new_char;
    old_char = '*';
  
    do{
        scanf("%c",&new_char);
        if(new_char == old_char) continue;
        old_char = new_char;
        printf("%c",old_char);
    }while(new_char!='*');
    
}