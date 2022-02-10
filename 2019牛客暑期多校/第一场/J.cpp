#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll x, y, a, b;
int main(){
    while(cin >> x >> a >> y >> b){
        ll res1 = x / a, res2 = x % a, res3 = y / b, res4 = y % b;
        if(res1 == res3){
            if(res2 * b == res4 * a){
                puts("=");
            }
            else if(res2 * b > res4 * a){
                puts(">");
            }
            else{
                puts("<");
            }
        }
        else if(res1 > res3){
            puts(">");
        }
        else{
            puts("<");
        }
    }
    return 0;
}