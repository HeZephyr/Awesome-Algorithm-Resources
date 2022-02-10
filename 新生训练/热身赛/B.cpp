#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n,m;
void solve(){
    //题目中给定的是一个公差为1的等差数列，我们可以直接利用求和公式来判断。
    //即na1+n*(n-1)/2=m。
    //所以我们只要枚举n就可以得到a1，然后反过来判断式子是否成立。
    //这时候就可以由求和公式确定n的上界：为sqrt(2*m);
    ll temp=min(ll(sqrt(2*m)),n),a1;
    for(ll len=temp;len>=1;len--){
        a1=(2*m-(len)*(len-1))/(2*len);
        if(len*a1+(len)*(len-1)/2==m){
            cout<<"["<<a1<<","<<a1+len-1<<"]"<<endl;
        }
    }
    cout<<endl;
}
int main(){
    while(cin>>n>>m&&(n||m)){
        solve();
    }
    return 0;
}