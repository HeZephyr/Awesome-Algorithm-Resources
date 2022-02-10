/**
  *@filename:E
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-26 01:09
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 200000 + 5;
const int mod = 1e9+7;

int t,n;
void solve(vector<int> &a){
    queue<int> q;//先进先出，存储待用的数字，构造字典序小的。
    stack<int> s;//先进后厨，存储待用的数字，构造字典序大的。
    vector<int> minn,maxx;
    int low=1;//该变量表示当前可用数字的最小值。
    for(int i=1;i<=n;i++){
        //开始遍历根据最大值确定。
        if(a[i-1]!=a[i]){
            //说明该位置的数会比之前的大，则该位置的数就为最大值，同样，之间的数都可以功供我们枚举。
            for(int j=low;j<a[i];j++){
                s.push(j),q.push(j);
            }
            //这样这些数都被用光了，我们需要更改low的值。
            low=a[i]+1;
            minn.push_back(a[i]);
            maxx.push_back(a[i]);
        }
        else{
            minn.push_back(q.front()),q.pop();
            maxx.push_back(s.top()),s.pop();
        }
    }
    for(int i=0;i<minn.size();i++){
        cout<<minn[i];
        i==minn.size()-1?cout<<endl:cout<<" ";
    }
    for(int i=0;i<maxx.size();i++){
        cout<<maxx[i];
        i==maxx.size()-1?cout<<endl:cout<<" ";
    }
}
int main() {
    while(cin>>t){
        while(t--){
            cin>>n;
            vector<int> a(n+1);
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            solve(a);
        }
    }
    return 0;
}