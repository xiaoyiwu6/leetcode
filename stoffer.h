#ifndef _STDOFFER_H_
#define _STDOFFER_H_

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    //剑指 Offer 12. 矩阵中的路径
    bool exist(vector<vector<char>>&,string);
private:
    int rows,cols;
    //深度优先
    bool dfs(vector<vector<char>>&,string,int,int,int);
};

#endif 