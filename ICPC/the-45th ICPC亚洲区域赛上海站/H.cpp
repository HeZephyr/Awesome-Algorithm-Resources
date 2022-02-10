#include<bits/stdc++.h>
using ll = long long;
using namespace std;
int main(){
    ll n;
    cin>>n;
    ll ans = (n%3+n-3)*(n-3) + (n/3+1)*(n/3)*2;
    cout<<ans<<endl;
    return 0;
}
