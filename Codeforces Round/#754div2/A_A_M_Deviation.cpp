#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, a[4];
void solve(){
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> a[1] >> a[2] >> a[3];
        int temp = a[1] + a[3] - 2 * a[2];
        //一次操作可以减3.增3.
        if(temp > 0){
            temp %= 3;
            if(temp == 2)temp = 1;
            
        }
        else{
            if(abs(temp) % 3 == 2){
                temp = 1;
            }
            else{
                temp = abs(temp) % 3;
            }
        }
        cout << temp << endl;
        solve();
    }
    return 0;
}