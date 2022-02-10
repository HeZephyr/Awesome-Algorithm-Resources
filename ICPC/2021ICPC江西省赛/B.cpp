#include<bits/stdc++.h>

using namespace std;

int t, x, y;
/* int gcd(int x, int y){
    if(y == 0)return x;
    return x % y ? gcd(y, x % y) : x;
} */
int main(){
    cin >> t;
    while(t -- ){
        cin >> x >> y;
        vector<int> res;
        while(true){
            if(x == 1){
                res.push_back(0);
                res.push_back(y);
                break;
            }
            int gcd = __gcd(x, y);
            x /= gcd, y /= gcd;
            if(x % y == 0){
                res.push_back(x);
                break;
            }
            res.push_back(x / y);
            int temp = x % y;
            x = y;
            y = temp;
        }
        int len = res.size();
        cout << len - 1 << " ";
        for(int i = 0; i < len; ++ i){
            cout << res[i];
            if(i == len - 1)cout << endl;
            else cout << " ";
        }
    }
    return 0;
}