/**
  *@filename:恨7不成妻
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-12 21:19
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 20;
const ll P = 1e9+7;

//需要满足三个性质。
//1.不含7.
//2.各位数字之和模7不为0.an-1+...+a0%7!=0. 
//3.该数模7不为0.an-1*pow(10,n-1)+...+a0+pow(10,0)%7!=0

struct F{
    ll s0,s1,s2;//s0为符合要求的数。s1为符合要求的数1次方之和，s2为符合要求的数的2次方之和。
}f[N][10][7][7];//f[i][j][k][u]表示总共有i位数且最高位是j，该数值模7为k，各位数数字之和模7为u的所有数的s0,s1,s2.
//进行初始化。
int t;//测试数。
ll l,r;
ll power7[N],power9[N];//power7[i]存储10^i余7的余数，power9[i]存储10^i余P的余数。
ll mod(ll x,ll y){
    return (x%y+y)%y;
}
void init(){
    //确定初始值，位数为1的情况。
    for(int j=0;j<10;j++){
        if(j==7)continue;
        //根据性质排除不符合要求的。
        F &v=f[1][j][j%7][j%7];//这里用引用减少代码量。
        v.s0++;
        v.s1+=j;
        v.s2+=j*j;
    }
    ll power = 10;//辅助作用，表示10的i-1次方。
    for(int i=2;i<N;i++,power*=10){
        for(int j=0;j<10;j++){
            if(j==7)continue;//排除不符合要求的数。
            for(int k=0;k<7;k++){
                for(int u=0;u<7;u++){
                    for(int q=0;q<10;q++){
                        //枚举i-1的最高位。
                        if(q==7)continue;
                        F &x=f[i][j][k][u],y=f[i-1][q][mod(k-j*(power%7),7)][mod(u-j,7)];
                        //s0,s1,s2都是通过公式就算得到。
                        x.s0=mod(x.s0+y.s0,P);
                        x.s1=mod(x.s1+1LL*j%P*(power%P)%P*y.s0%P+y.s1,P);
                        x.s2=mod(x.s2+
                            1LL*j%P*y.s0%P*(power%P)%P*j%P*(power%P)%P+
                            1LL*y.s1%P*2%P*j%P*(power%P)%P+y.s2,P);
                    }
                }
            }
        }
    }
    //这里处理为了方便以及降低时间复杂度。
    power7[0]=1,power9[0]=1;
    for(int i=1;i<N;i++){
        power7[i]=power7[i-1]*10%7;
        power9[i]=power9[i-1]*10%P;
    }
}
F get(int i,int j,int k,int u){
    //因为f[i][j][k][u]是本身模7等于k，且各位数之和模7等于u的，所以我们需要找出符合条件的集合。
    ll s0=0,s1=0,s2=0;
    for(int x=0;x<7;x++){
        for(int y=0;y<7;y++){
            if(x==k||y==u)continue;
            F v=f[i][j][x][y];
            s0=mod(s0+v.s0,P);
            s1=mod(s1+v.s1,P);
            s2=mod(s2+v.s2,P);
        }
    }
    return {s0,s1,s2};
}
ll dp(ll n){
    if(!n)return 0;//0的平方和为0.
    vector<int> a;
    ll temp=n%P;//备份一个n，供后面判断n使用。
    while(n)a.push_back(n%10),n/=10;
    ll last_a=0,last_b=0;//这里我们需要存储前缀的本身值和前缀的个位数之和。
    ll ans=0;//答案。
    for(int i=a.size()-1;i>=0;i--){
        int x=a[i];
        for(int j=0;j<x;j++){
            //走左分支。
            if(j==7)continue;
            //我们需要将符合条件的数筛出来，这里要用到一个get函数。
            //求得本身模7不等于a，并且各位数之和模7不等b的集合，此时就可以使用预处理出来的结构体
            int k=mod(-last_a*power7[i+1],7),u=mod(-last_b,7);
            F v=get(i+1,j,k,u);
            //cout<<v.s0<<" "<<v.s1<<" "<<v.s2<<endl;
            //根据公式求解s2.
            //j就是last_a.
            ans=mod(ans+
                1LL*(last_a%P)*(last_a%P)%P*(power9[i+1]%P)%P*(power9[i+1]%P)%P*v.s0%P+
                1LL*2*last_a%P*(power9[i+1]%P)%P*v.s1%P+
                v.s2,P);
            //cout<<ans<<endl;
        }
        //判断x。
        if(x==7)break;
        //走右分支更新。
        last_a=last_a*10+x;
        last_b+=x;
        //判断自己本身是否符合要求。
        if(!i&&last_a%7&&last_b%7){
            ans=mod(ans+temp*temp%P,P);
        }
    }
    return ans;
}
int main(){
    init();
    cin>>t;
    while(t--){
        cin>>l>>r;
        cout<<mod(dp(r)-dp(l-1),P)<<endl;
    }
    return 0;
}
/*
1
1 1000000000000000000
*/