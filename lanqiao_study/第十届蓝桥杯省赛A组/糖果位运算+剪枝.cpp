#include<bits/stdc++.h>

using namespace std;

const int N = 110, M = 1<<20;



int n, m, k;
vector<int> col[N]; //存储有几行包括第i列
int Log2[M];
int lowbit(int x)  //返回最后一个为1的位i(从0开始算)，返回值为2^i
{
    return x & -x;
}

//评估函数，计算当前状态下至少还需选多少行
int h(int state)
{
    int res = 0;
    for(int i = (1<<m)-1-state; i; i-=lowbit(i))
    {
        int c = Log2[lowbit(i)];  // c表示最后一个为1的列
        res ++;  // 选上这一列上的所有行数，但只算1行

      for(int j=0; j<col[c].size(); j++) {
            i &= ~col[c][j];    // 把这一行所有的1从i里面去掉,1位清空，0位不动（此时i里面的1位表示此行未选）
        }
    }
    return res;
}
bool dfs(int depth, int state) //在state状态下，迭代depth层，能否找到解
{

    if(depth == 0 ) // 层数为零时或者当前状态还需选的行数大于了还能选的行数
    {
        return state == (1<<m) -1; // state是否等于m个1（所有口味的糖果在二进制中表示出来），是则返回true
    }

    // 剪枝：找选择性最少的一列（优先级比可选择性多的高）
    int  t = -1; //t表示选择性最少的一列

    for(int i = (1<<m)-1-state ; i; i-=lowbit(i)) //i的二进制位1表示需要选择，0表示已经选择
    {
        int c = Log2[lowbit(i)];  // c表示最后一个为1的列
        if(t==-1 || col[t].size() > col[c].size())
        {
            t = c; //如果第c列下的行更少，则更新t为c
        }
    }
    //枚举选哪一行
    for(int i =0; i<col[t].size(); i++)
    {
        if(dfs(depth-1, state | col[t][i])) //迭代depth-1层，在选择了该行的状态下继续迭代
        {
            return true; //可以找到结果，则返回真
        }
    }
    return false;
}
int main()
{
    cin>>n>>m>>k;
    // 预处理以二为底的对数
    for(int i=0; i<m; i++)
        Log2[1<<i] = i;
    for(int i=0; i<n; i++)
    {
        int state = 0; //用二进制表示状态，其第i为1表示第i个糖果已有
        for(int j =0; j<k; j++) //读入每一行
        {
            int c;
            cin>>c;
            state |= 1<< (c-1); // 将二进制表示的糖的这一位表示成1，c-1是将糖的编号以0开始

        }

        for(int j = 0; j<m; j++) //遍历每列，如果state表示的这个状态在该列下，则加入数组中
        {
            if((state >> j) & 1)
            {
                col[j].push_back(state);
            }
        }
    }


    int depth = 1; // 迭代的层数，递归一层表示选了一包糖果
    while(depth<=m && !dfs(depth,0))   // dfs第二个参数表示state,第i位的1表示第i位已选
    {
        depth++;  //选depth包没找到符合要求的，继续选择糖果
    }

    if(depth>m) depth = -1;

    cout<<depth<<endl;

    return 0;
}