#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
ll a, b, x;
int main(){
    cin >> t;
    while(t -- ){
        cin >> a >> b >> x;
        bool flag = false;
        while(a && b){
            if(a < b)swap(a, b);
            if(x <= a && (a - x) % b == 0)flag = true;
            a %= b;
        }
        if(flag)puts("YES");
        else puts("NO");
    }
    return 0;
}