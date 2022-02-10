/**
  *@filename:C_Phoenix_and_Towers
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-05 16:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii; 
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,m,n,x;
int h[maxn];
priority_queue<pii,vector<pii>,greater<pii> > q;
void solve(){
    //我们每次取高度最小的放置即可。最后由于题目一定有解，那么这种做法必然正确。
    sort(h,h+n);
    pii head;
    cout<<"YES"<<endl;
    for(int i=0;i<n;i++){
        head=q.top();
        cout<<head.second<<" ";
        q.pop();
        q.push({head.first+h[i],head.second});//每加入一个就放入x置其中。
    }
    cout<<endl;
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>x;
        for(int i=0;i<n;i++)cin>>h[i];
        while(!q.empty())q.pop();
        for(int i=1;i<=m;i++)q.push({0,i});//将这i个容器放入。
        solve();
    }
    return 0;
}