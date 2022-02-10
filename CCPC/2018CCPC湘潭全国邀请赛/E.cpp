#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int a,b,c,d;
int cal(int a,int b,int v){
    //统计区间[a,b]内v的因子个数。
    return b / v - (a - 1) / v;
}
void solve(){
    //为了避免重复
    ll s1 = cal(a,b,2), s2 = cal(a,b,1009), s3 = cal(a,b,2018);
    ll b1 = cal(c,d,2), b2 = cal(c,d,1009), b3 = cal(c,d,2018);
    ll F = (s2-s3)*b1; //左边1009奇数倍的个数乘以右边偶数个数
    ll U = s3*(d-c+1); //左边2018的倍数的个数乘以右边的所有的数
    ll C = (b2-b3)*(s1-s3); //右边1009奇数倍的个数乘以左边偶数的个数(因为2018的倍数同样是偶数,在U里面已经计算过,所以要减去)
    ll K = b3*(b-a+1-s2); //右边2018的倍数的个数乘以左边所有的数(同样要减去已经计算过的1009奇数倍的个数)
    cout<<F+U+C+K<<endl;
}
int main(){
    while(cin >> a >> b >> c >> d){
        solve();
    }
    return 0;
}