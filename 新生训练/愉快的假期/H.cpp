#include<bits/stdc++.h>

using namespace std;

//一道纯粹的贪心题，这里需要借助优先队列来实现模拟贪心。
int n;
priority_queue<int,vector<int>,greater<int> > q;//优先队列。默认大顶堆，这里需要使用小顶堆。 
void solve(){
    //模拟加法。当只有一个元素的时候则退出。
    int ans=0;//计算成本。
    int temp;
    while(q.size()>1){
        temp=q.top();
        q.pop();
        temp+=q.top();
        q.pop();
        ans+=temp;
        q.push(temp);
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n&&n!=0){
        int temp;
        while(!q.empty())q.pop();
        for(int i=0;i<n;i++){
            cin>>temp;
            q.push(temp);
        }
        solve();
    }
    return 0;
}