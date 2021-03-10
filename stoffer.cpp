#include "stoffer.h"

/**请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
 * 路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
 * 如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
 * 例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。
 * [["a","b","c","e"],
 * ["s","f","c","s"],
 * ["a","d","e","e"]]
 * 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子
 */
//i,j表示矩阵坐标，k表示单词下标，true表示有通路，false表示不通
bool Solution::dfs(vector<vector<char>>& board,string word,int i,int j,int k){
    //先判断是否越界或者当前字符不匹配
    if(i<0||i>=rows||j<0||j>=cols||word[k]!=board[i][j]) return false;
    //判断是否到达word末尾
    if(k==word.size()-1) return true;
    //使用空格表示被访问状态
    board[i][j] = ' ';
    //继续深度判断是否有通路
    bool res = dfs(board,word,i-1,j,k+1)|dfs(board,word,i+1,j,k+1)|dfs(board,word,i,j-1,k+1)|dfs(board,word,i,j+1,k+1);
    //如果没有通路需要回溯，并且恢复这个节点的值
    if(res==false) board[i][j] = word[k];
    return res;
}
//判断循环内是否满足
bool Solution::exist(vector<vector<char>>& board, string word){
    rows = board.size();
    cols = board[0].size();
    int i,j;

    for(i=0;i<rows;i++)
        for(j=0;j<cols;j++)
            if(dfs(board,word,i,j,0)) return true;
    
    return false;
}

/**地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标
 *  [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
 * 也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 
 * [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
 * 请问该机器人能够到达多少个格子？
*/
//判断位数和是否大于k
bool Solution::sum_compare(int i,int j,int k){
    
}
int Solution::movingCount(int m, int n, int k){
    int i,j;
    while(){

    }
}