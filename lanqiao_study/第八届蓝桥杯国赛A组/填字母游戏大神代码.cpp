#include<bits/stdc++.h>
using namespace std;
char c[2]= {'L','O'};
map<string,int>mp;
int check(string ss)
{
    bool val=0;//记录最终是否有可能平局
    if(mp.find(ss)!=mp.end()) return mp[ss];//如果找到该状态，就返回我们存储得到的结果
    if(ss.length()<3)
    {
        //特判，长度小于3，必然是无法组成的。
        mp[ss]=0;
        return 0;
    }
    //这种情况都是可以直接定胜负的。
    if(ss.find("LO*")!=ss.npos||ss.find("*OL")!=ss.npos||ss.find("L*L")!=ss.npos)
    {
        mp[ss]=1;
        return 1;
    }
    //如果空格都已经填完了，且还没有出现LOL，说明无法判断输赢。
    if(ss.find("*")==ss.npos&&ss.find("LOL")==ss.npos)//最后处理的结果无法判断输赢时
    {
        mp[ss]=0;
        return 0;
    }
    //递归模拟操作。
    for(int i=0; i<ss.length(); i++)
    {
        if(ss[i]=='*') //两种方式进行选择
        {
            for(int j=0; j<2; j++)
            {
                ss[i]=c[j];
                //抉择最优方法。
                //如果填完之后能形成对方的必胜局，那么自然是不行的。
                if(ss.find("LO*")!=-1||ss.find("*OL")!=-1||ss.find("L*L")!=-1)
                {
                    //走这一步后对方会赢，恢复局面
                    ss[i]='*';
                    continue;
                }
                int flag=check(ss);//递归去寻找判断对方的操作继而决定。
                //恢复局面。
                ss[i]='*';//先恢复局面
                //返回-1说明对方输。
                if(flag==-1) return 1;//对方走后我方赢
                if(flag==1) continue;//我方输
                //记录平局的标志。
                if(flag==0) val=1;
            }
        }
    }
    if(val)
    {
        //记忆
        mp[ss]=0;
        return 0;
    }
    mp[ss]=-1;//若未返回0和1，则其输
    return -1;
}
int main()
{
    int n;
    while(cin>>n){
        string s;
        for(int i=0; i<n; i++){
            cin>>s;
            cout<<check(s)<<endl;
        }
    }
    return 0;
}