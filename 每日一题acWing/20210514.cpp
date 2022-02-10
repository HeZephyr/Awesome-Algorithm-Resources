#include<bits/stdc++.h>

using namespace std;

const int N =1e6+10;

int n;
int a[N],b[N],idx[N];
void solve(){
}
int main(){
    while(cin>>n){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            idx[a[i]]=i;
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            b[i]=idx[b[i]];//获取它们的对应位置。
        }
        vector<int> result;
        for(int i=1;i<=n;i++){
            if(b[i]==0)continue;
            if(!result.size()||b[i]>result.back())result.push_back(b[i]);
            //维护一个序列。
            int id=lower_bound(result.begin(),result.end(),b[i])-result.begin();
            result[id]=b[i];
        }
        cout<<result.size()<<endl;
    }
    return 0;
}