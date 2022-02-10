#include<bits/stdc++.h>

using namespace std;

const int maxn=1010;

int n,m;//星球数和星际航线数M。
int a,b,father[maxn];
int find(int x){
    int r=x;
    while(r!=father[r])r=father[r];
    int i=x,j;
    while(father[i]!=r){
        j=father[i];
        father[i]=r;
        i=j;
    }
    return r;
}
int main(){
    while(cin>>n&&n){
        cin>>m;
        //初始化。
        for(int i=1;i<=n;i++)father[i]=i;
        while(m--){
            cin>>a>>b;
            a=find(a),b=find(b);
            if(a!=b)father[a]=b;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(father[i]==i)cnt++;
        }
        cout<<cnt-1<<endl;
    }
    return 0;
}