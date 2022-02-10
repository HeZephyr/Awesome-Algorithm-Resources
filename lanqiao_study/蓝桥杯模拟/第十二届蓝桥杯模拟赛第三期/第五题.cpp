/**
  *@filename:第五题
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 14:16
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//以前省赛的一道题。
void solve(){
    int n=2021;
    vector<char> result;
    while(n>0){
        int temp1=n%26,temp2=n/26;
        if(temp1==0){
            //说明能整除26，所以我们这里要分出26。
            result.push_back('Z');
            temp2--;
        }
        else{
            result.push_back('A'+temp1-1);
        }
        n=temp2;
    }
    for(int i=result.size()-1;i>=0;i--){
        cout<<result[i];
    }
    cout<<endl;//BYS;
}
int main(){
    
    solve();
    return 0;
}