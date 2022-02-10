#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

int n,m;//序列长度n，和m次修改操作。
char op;
int a,b;
int c[maxn];//树状数组。
int lowbit(int x){
    return x&(-x);
}
void add(int pos,int x){
    while(pos<=n){
        c[pos]+=x;
        pos+=lowbit(pos);
    }
}
int get(int l){
    int ans=0;
    while(l>0){
        ans+=c[l];
        l-=lowbit(l);
    }
    return ans;
}
int main(){
    cin>>n>>m;
    while(m--){
        cin>>op>>a>>b;
        if(op=='x'){
            add(a,b);
        }
        else if(op=='y'){
            cout<<get(b)-get(a-1)<<endl;
        }
    }
    return 0;
}