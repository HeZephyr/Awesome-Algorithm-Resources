/**
  *@filename:子串分值
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 15:49
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
string s;
vector<int> pos[26];
int main(){
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        int temp=s[i]-'a';
        if(!pos[temp].size())pos[temp].push_back(-1);//若为空我们就插入-1.
        pos[temp].push_back(i);
    }
    //对每一个在添加一个length
    for(int i=0;i<26;i++){
        if(pos[i].size()){
            pos[i].push_back(n);
        }
    }
    /* for(int i=0;i<26;i++){
        cout<<char(i+'a')<<" ";
        for(int j=0;j<pos[i].size();j++){
            cout<<pos[i][j]<<" ";
        }
        cout<<endl;
    } */
    //开始计算每个的贡献度。
    ll ans=n;//每个字符本身就可以贡献一次。
    for(int i=0;i<26;i++){
        if(pos[i].size()){
            for(int j=1;j<pos[i].size()-1;j++){
              ans+=(pos[i][j]-pos[i][j-1]-1)+(pos[i][j+1]-pos[i][j]-1)+
              ll((pos[i][j]-pos[i][j-1]-1))*(pos[i][j+1]-pos[i][j]-1);//注意防止结果溢出。
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}