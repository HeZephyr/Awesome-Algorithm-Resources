#include<bits/stdc++.h>

using namespace std;

const int maxn=105;
int n;
struct node{
    int st,ed;
    //贪心，将节目排满即可。
    bool operator<(const node a){
        return ed<a.ed;//我们只关心什么时候结束，越早结束越好。
    }
};
node times[maxn];
void solve(){
    sort(times,times+n);
    int ans=0,ed=0;
    for(int i=0;i<n;i++){
        if(times[i].st>=ed){
            ans++;
            ed=times[i].ed;
        }
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n&&n){
        for(int i=0;i<n;i++){
            cin>>times[i].st>>times[i].ed;
        }
        solve();
    }
    return 0;
}