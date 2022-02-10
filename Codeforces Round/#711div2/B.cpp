/**
  *@filename:B
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-03-30 15:17
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n,w;
bool cmp(int a,int b){
    return a>b;
}
void solve(vector<int> &a){
    sort(a.begin(),a.end(),cmp);
    priority_queue<int> q;//优先队列，存放剩余空间。
    q.push(w);//放入一块初始空间。
    for(int i=0;i<n;i++){
        //接下来开始判断剩余空间是否够用。
        if(q.top()<a[i]){
            q.push(w-a[i]);//不够用就要再加入一层。
        }
        else{
            //够用就更新剩余空间大小。
            int temp=q.top()-a[i];
            q.pop();
            q.push(temp);
        }
    }
    cout<<q.size()<<endl;
}
int main() {
    while(cin>>t){
        while(t--){
            cin>>n>>w;
            vector<int> a(n);
            for(int i=0;i<n;i++){
                cin>>a[i];
            }
            solve(a);
        }
    }
    return 0;
}