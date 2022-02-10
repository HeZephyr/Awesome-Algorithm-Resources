#include<bits/stdc++.h>

using namespace std;
using ll = long long;
int t, x, k;
int main(){
    cin >> t;
    for(int i = 1; i <= t; ++ i){
        cin >> x >> k;
        if(k >= 31 || k == 1){
            printf("Case #%d: %d\n", i, x);
        }
        else{
            int cnt = 0;
            for(int i = 1, temp1, temp2; pow(i, k) <= x; ++ i){
                temp1 = pow(i, k), temp2 = pow(i + 1, k) - 1;
                temp2 = min(temp2, x);
                cnt += (temp2-temp1+1 + i-1) / i ;
                //cout << temp1 << " " << temp2 << endl;
                //cout << cnt << endl;
            }
            printf("Case #%d: %d\n", i, cnt);
        }
    }
    return 0;
}