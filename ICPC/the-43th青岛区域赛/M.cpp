#include<bits/stdc++.h>

using namespace std;

int t, x, k;
int cnt[10];
void init(){
    cnt[0] = 1, cnt[4] = 1, cnt[6] = 1, cnt[8] = 2, cnt[9] = 1;
}
int change(int x){
    int ans = 0;
    while(x){
        ans += cnt[x % 10];
        x /= 10;
    }
    return ans;
}
int main(){
    init();
    cin >> t;
    while(t -- ){
        cin >> x >> k;
        while(k){
            if(x >= 10){
                x = change(x);
            }
            else if(x > 1){
                x = cnt[x];
            }
            else{
                if(x == 0){
                    x = k % 2;
                }  
                else{
                    x = !(k % 2);
                }
                break;           
            }
            -- k;
        }
        cout << x << endl;
    }
    return 0;
}