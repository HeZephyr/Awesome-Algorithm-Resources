#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

int n,m;
int c[maxn];//树状数组。
//我们发现1^1=0,1^0=1，所以其实修改只要对每个位置上的进行异或即可。
//而这道题是区间修改，单点查询，所以我们可以用异或差分数组来做。即：
//d[i]=a[i]^a[i-1],那么a[i]=d[1]^d[2]...^d[i]，所以题目易解。
int lowbit(int x){
    return x&(-x);
}
void update(int pos){
    for(int i=pos;i<=n;i+=lowbit(i)){
        c[i]^=1;
    }
}
int getPos(int pos){
    int ans=0;
    for(int i=pos;i>=1;i-=lowbit(i)){
        ans^=c[i];
    }
    return ans;
}
int main(){
    cin>>n>>m;//数组长度和指令条数。
    int op,l,r;
    while(m--){
        cin>>op;
        if(op==1){
            cin>>l>>r;
            update(l);
            update(r+1);
        }
        else{
            cin>>l;
            cout<<getPos(l)<<endl;
        }
    }
    return 0;
}