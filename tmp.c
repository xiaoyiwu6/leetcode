#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

/**编程求 exp-x，x,n 键盘输入。（保研题附加题）*/
float exp_minus_x(int x, int n){
    float tmp = 1.0;
    float sum = tmp;

    for(int i=1;i<=n;i++){
        tmp = -tmp*x/i;
        sum += tmp;
    }
    return sum;
}

/**将输入的一个数质因分解，如 Input 90，Print:90=2*3*3*5.（保研题附加题）*/
void prime_factorization(int num){
    int i,j,k;
    //从最小的质数开始循环，出现符合的质因数时num会除以该数发生变化，每次除以质因数后，质因数的倍数就不会符合条件，因此这里只需从最小的质因数开始循环即可，不需要后面的数也是质数
    for(i=2;i<=num;i++){
        //为了打印方便这里while条件选择num!=i
        while(num!=i){
            //质因数判断
            if(num%i==0){
                printf("%d*",i);
                num/=i;
            }else break;
        }
    }
    printf("%d",num);
}


/**编写一个完整的程序，使之能完成以下功能：一段名为 file.c 的程序，该程序 中含有括号，现要检查程序中的括号是否配对，提示：利用堆栈实现。*/
int check(){
    FILE *pf;
    if(!(pf = fopen("file.c","r"))) printf("failed.");
    char p[MAX]; int cur=-1;//栈高度,-1表示栈空
    char tmp;
    //读取字符知道文件尾
    while (!feof(pf)){
        tmp = fgetc(pf);
        if(tmp == '{' || tmp == '[' || tmp == '(')
            p[++cur] = tmp;
        else if (tmp == '}' || tmp == ']' || tmp ==')'){
            //栈空或者弹出不匹配时则返回-1，表示不配对
            if(cur<0 || !judge(p[cur--],tmp)) return -1;
        }
    }
    //栈空则配对成功
    return cur==-1;
}
//判断是否匹配，匹配返回1，不匹配返回0
int judge(char left, char right){
    switch (left)
    {
    case '(':
        return right==')';
        break;
    case '{':
        return right=='}';
        break;
    case '[':
        return right==']';
        break;
    default:
        return 0;
    }
}

/**编写一个函数，使之能完成以下功能：把 file1.doc 的内容全部复制到 file2.doc 中，
 * file1.doc 中全部是字符(含空格)，要求复制时，在 file2.doc 中的每一行都要 加上行号，
 * 例如：行号*(其中“*”表示具体的数字)。最后该函数返回 file1.doc 中的字符个数(不包括空格)。
 * */
int cpy_file(){
    FILE *fp1,*fp2; char ch; int row=0; int count=0;
    if(!(fp1=fopen("file1.doc","r")) || !(fp2=fopen("file2.doc","a+")))//a+表示从文件末尾开始写，不覆盖
        return -1;

    while(!feof(fp1)){
        ch = getc(fp1);//从fp1读取
        if(ch == '\n')
            printf("行号%d", row++);
        putc(ch, fp2);//复制到fp2
        if(ch!=' ' || ch!='\n') count++;
    }
    fclose(fp1);fclose(fp2);
    return count;
}

/**编写一个函数，使之能完成以下功能：利用递归方法找出一个数组中的最大 值和最小值，要求递归调用函数的格式如下：
 *  MinMaxValue(arr,n,&max,&min)，其中 arr 是给定的数组，n 是数组的个数，max、 min 分别是最大值和最小值。*/
void MinMaxValue(int arr[], int n, int *max, int *min){
    if(n==0) return;
    if(arr[n-1]>*max) *max = arr[n-1];
    if(arr[n-1]<*min) *min = arr[n-1];
    MinMaxValue(arr,n-1,max,min);
}

/**编写一个函数，使之能完成以下功能：把一个字符串逆序排列。*/
void char_reverse(char str[]){
    int s_length = strlen(str);
    char temp;
    for(int i=0;i<s_length/2;i++){
        temp = str[i];
        str[i] = str[s_length-1-i];
        str[s_length-1-i] = temp;
    }
}

/**编写完整程序：利用 2 个函数对输入的两个分数进行加、减、乘、除四则运 
 * 算和输出用分数表示的结果。（注：输入格式为：%ld/%ld%c%ld/%ld，输出格式 
 * 为%ld/%ld），例如：输 入 1/4+1/3，输出：7/12*/

 long gcd(long a, long b){
    return b?gcd(b,a%b):a;
 }

 void compute(){
    long a,b,c,d;//example: a/b+c/d
    char opt;//操作符
    long e,f;//example: e/f
    scanf("%ld%ld%c%ld%ld",&a,&b,&opt,&c,&d);
    switch (opt)
    {
    case '+':
        e = a*d+b*c;
        f = b*d;
        break;
    case '-':
        e = a*d-b*c;
        f = b*d;
        break;
    case '*':
        e = a*c;
        f = b*d;
        break;
    case '/':
        e = a*d;
        f = b*c;
        break;
    default:
        printf("wrong operator.");
        return;
    }
    //对ef进行化简
    int gcf = gcd(e,f);
    e/=gcf; f/=gcf;
    printf("%ld/%ld",e,f);
 }

 /**编一程序，输入月份号，输出该月的英文月名。例如，输入 3，则输出 March， 要求用指针数组处理。*/
 char* int2string(int n){
    if(n>12 || n<1) return "illegal month";
    char *calendarMap[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
    return calendarMap[n-1];
 }

/**有 n 个人围成一圈，顺序排号。从第一个人开始报数（从 1 到 3 报数），凡 
 * 报到 3 的人退出圈子，问最后留下来的是原来第几号的那位（要求用指针知识实 现）。*/
int lastRemaining(int n, int Kth){//求数组下标，从0开始，而坐标从1开始，输出后要加1
    if(n==1) return 0;
    int x = lastRemaining(n-1, Kth);
    return (x+Kth)%n;
}
//printf("%d",lastRemaining(100,3)+1);


/**Eratasthenes筛选法，求出n以内的所有素数*/
void eratasthenes(int n){
    int i,j,tmp;
    int count[MAX]={0};//用count记录，素数为0，合数为1
    //从2开始直到sqrt(n)循环，从第一个素数开始筛掉它的倍数，接着如此
    for(i=2;i*i<=n;i++)//对所有可能的正因数进行循环
        if(!count[i])
            for(j=2*i;j<=n;j+=i) 
                count[j]==1;
    
    for(i=2;i<=n;i++)
        if(!count[i])
            printf("%d ",count[i]);
}

/**n阶幻方，即一个n*n的矩阵，由1到n^2数字填充，使得每行每列和每个
 * 对角线的和都相同*/
void magic_squre(int n){
    int i,j,k;
    //申请所需二维数组
    int **arr = (int **)malloc(sizeof(int *)*n);
    for(i=0;i<n;i++) arr[i] = (int *)malloc(sizeof(int)*n);

    //填充数字,将1放在第一行中间格子，此后将每个数字放在前一个数字的右上格
    i=n/2,j=0;
    for(k=1;k<=n*n;k++) arr[(i++)%n][(j--)%n]=k;

    for(i=0;i<n;i++) free(*(arr+i)); //释放
}

/**汉诺塔*/
//a,b,c分别代表三个柱，该函数的意义在于借助b柱将n个盘从a柱移动到c柱
void move(int n,int a, int b, int c){
    if(n==1) printf("%c->%c\n",a,c);
    else{
        move(n-1,a,c,b);
        printf("%c->%c",a,c);
        move(n-1,b,a,c);
    }
}
void Hanoi(int n){
    move(n,'a','b','c');
}