#include<bits/stdc++.h>

using namespace std;

const int maxn=5e5+10;

int n,m;//该数列中的数字和操作个数。
int d[maxn];//树状数组
//区间修改，单点查询BIT。原理是通过差分把这个区间修改、单点查询的问题转化为单点修改区间查询的问题。
//d[i]=a[i]-a[i-1],且d[1]=a[1].则a[i]=d[1]+d[2]+...+d[i].所以我们在BIT中存储的实际上是
//数组d[1:n]，准确来说是d数组的树状数组。
//对于修改部分，我们是给a[l:r]全部加上x，那么我们不难发现，其实d[l+1]...d[r]都没有发生变化。
//变化的只有d[l]增加了x，d[r+1]减少了x。
//而对于单点查询a[pos]，实际上就是a[pos]=d[1]+..+d[pos]。故此题可解。
//要注意输入的时候是单点修改。
int lowbit(int x){
    return x&(-x);
}
void update(int idx,int value){
    //单点修改。
    for(int i=idx;i<=n;i+=lowbit(i)){
        d[i]+=value;
    }
}
void range_add(int l,int r,int x){
    //区间修改。
    update(l,x),update(r+1,-x);
}
int getPos(int pos){
    int ans=0;
    for(int i=pos;i>=1;i-=lowbit(i)){
        ans+=d[i];
    }
    return ans;
}
int main(){
    int op,x,y,z;
    cin>>n>>m;
    int last=0,now;
    for(int i=1;i<=n;i++){
        cin>>now;
        //单点修改。
        update(i,now-last);
        last=now;
    }
    while(m--){
        cin>>op;
        if(op==1){
            cin>>x>>y>>z;
            range_add(x,y,z);
        }
        else{
            cin>>x;
            cout<<getPos(x)<<endl;
        }
    }
    return 0;
}