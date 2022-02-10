/**
  *@filename:B_Sifid_and_Strange_Subsequences
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-24 22:42
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
int a[N];
//此题我们易知一定包含了所有的非正数，而若要包含正数，则必须满足之差是大于等于该正数的，
//且正数一定是只能取一个。
void solve(){
    sort(a + 1,a + 1 + n);
    int cnt = 0,minn = 0x3f3f3f3f;//minn记录选择的负数之间存在的最小值之差。
    for(int i = 1; i <= n; i++){
        if(a[i] <= 0){
            cnt ++;
        }
    }
    for(int i = 2; i <= n; i++){
        if(a[i] <= 0){
            minn = min(minn,a[i] - a[i - 1]);
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i] > 0 && minn >= a[i]){
            cnt ++;
            break;
        }
    }
    cout << cnt << endl;
}
int main(){
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}