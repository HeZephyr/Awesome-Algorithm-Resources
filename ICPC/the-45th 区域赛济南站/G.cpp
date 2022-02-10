#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll x, y;
int main(){
    cin >> x >> y;
    if((x ^ y) > x){
        puts("2");
        printf("%lld %lld", y, x);   
    }
    else{
        puts("1");
        printf("%lld\n", x ^ y);
    }
    return 0;
}