#include<bits/stdc++.h>

using namespace std;

const int N=410,INF=0x3f3f3f;
int n,a[N];
int dpmax[N][N],dpmin[N][N];
int pre[N];
void solve(){
    //初始化。
    for(int i=1;i<=2*n;i++){
        dpmax[i][i]=dpmin[i][i]=0;
        pre[i]=pre[i-1]+a[i];
    }
    for(int len=2;len<=n;len++){
        for(int l=1;l+len-1<=2*n;l++){
            int r=l+len-1;
            dpmax[l][r]=-INF,dpmin[l][r]=INF;
            //枚举分割点。
            for(int k=l;k<r;k++){
                dpmax[l][r]=max(dpmax[l][r],dpmax[l][k]+dpmax[k+1][r]+pre[r]-pre[l-1]);
                dpmin[l][r]=min(dpmin[l][r],dpmin[l][k]+dpmin[k+1][r]+pre[r]-pre[l-1]);
            }
        }
    }
    int maxx=-INF,minn=INF;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,dpmax[i][i+n-1]);
        minn=min(minn,dpmin[i][i+n-1]);
    }
    cout<<minn<<endl;
    cout<<maxx<<endl;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    solve();
    return 0;
}