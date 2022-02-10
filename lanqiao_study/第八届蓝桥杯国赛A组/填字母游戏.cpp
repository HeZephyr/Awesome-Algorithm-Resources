/**
  *@filename:填字母游戏
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-02 15:57
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

string ss;
map<string,int> p;//记录计算过的确定局，避免重复计算。
char op[]={'L','O'};//定义我们的选择项。
int play(){
    //我们的策略就是赢>平局>输。
    //模拟游戏。
    if(p.find(ss)!=p.end()){
        //如果这个已经出现过，那么我们直接返回就可以。
        return p[ss];
    }
    bool flag=false;//判断是否可能出现平局。
    if(ss.size()<3){
        //说明长度为3，说明不能组成LOL，双方只能平局。
        p[ss]=0;
        return 0;
    }
    //如果出现必胜局。
    if(ss.find("LO*")!=ss.npos||ss.find("L*L")!=ss.npos||ss.find("*OL")!=ss.npos){
        p[ss]=1;
        return 1;
    }
    //如果空格已经填完了且还没出现LOL。
    if(ss.find("*")==ss.npos&&ss.find("LOL")==ss.npos){
        //说明这种局势为平局。
        p[ss]=0;
        return 0;
    }
    //特判完之后我们就需要模拟操作了。
    for(int i=0;i<ss.size();i++){
        if(ss[i]=='*'){
            //我们则有两种选择。
            for(int j=0;j<2;j++){
                ss[i]=op[j];
                //递归去判断。
                if(ss.find("LO*")!=ss.npos||ss.find("L*L")!=ss.npos||ss.find("*OL")!=ss.npos){
                    //说明必输，我们直接恢复局面。
                    ss[i]='*';
                    continue;
                }
                int result=play();
                //判断是否可行。
                ss[i]='*';//还原状态。
                if(result==-1){
                    //这个结果说明对方先手必输，我们必赢。
                    p[ss]=1;
                    return 1;
                }
                else if(result==0){
                    //说明平局，我们标记出现了平局，但目前我们还不能选择这个决策。
                    flag=true;
                    continue;
                }
                else{
                    //说明对面赢了，那么就更不行了。
                    continue;
                }
            }
        }
    }
    //如果还不能赢，我们判断是否出现过平局输出即可。
    if(flag){
        p[ss]=0;
        return 0;
    }
    else{
        p[ss]=-1;
        return -1;
    }
}
int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>ss;
            cout<<play()<<endl;
        }
    }
    return 0;
}