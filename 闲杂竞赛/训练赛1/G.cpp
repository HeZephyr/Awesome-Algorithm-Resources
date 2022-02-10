/**
  *@filename:G
  *@author: pursuit
  *@created: 2021-08-08 20:14
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,a[N],dp[N];
vector<int> result;
void solve(){
    result.push_back(a[1]);
    int len = 1;
    for(int i = 2; i <= n; ++ i){
        if(a[i] > result[len - 1]){
            result.push_back(a[i]);
            len ++;
        }
        else{
            int idx = lower_bound(result.begin(),result.end(),a[i]) - result.begin();
            result[idx] = a[i];
        }
    }
    printf("%d\n", len);
    for(int i = 0; i < len; ++ i){
        printf("%d ", result[i]);
    }
    puts("");
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}