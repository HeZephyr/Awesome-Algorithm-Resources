/**
  *@filename:D_Blue_Red_Permutation
  *@author: pursuit
  *@created: 2021-11-02 22:57
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N], res[N];
char s[N];
void solve(){
    bool flag = true;
    vector<int> down, up;
    for(int i = 1; i <= n; ++ i){
        if(s[i] == 'B'){
            if(a[i] > n)a[i] = n;
            if(a[i] < 0)a[i] = 0;
            if(a[i] < 1){
                flag = false;
                break;
            }
            down.push_back(a[i]);
        }
        else{
            if(a[i] > n)a[i] = n + 1;
            if(a[i] < 0)a[i] = 1;
            if(a[i] > n){
                flag = false;
                break;
            }
            up.push_back(a[i]);
        }
    }
    if(!flag){
        puts("NO");
        return;
    }
    sort(down.begin(), down.end());
    sort(up.begin(), up.end(), greater<int>() );
    int len1 = down.size(), len2 = up.size();
    int idx1 = 0, idx2 = 0;
    int l = 1, r = n;
    while(idx1 < len1 || idx2 < len2){
        if(idx1 < len1){
            if(l <= down[idx1]){
                res[l] = 1;
                ++ l, ++ idx1;
            }
            else{
                break;
            }
        }
        if(idx2 < len2){
            if(r >= up[idx2]){
                res[r] = 1;
                -- r, ++ idx2;
            }
            else{
                break;
            }
        }
    }
    if(l > r){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        scanf("%s", s + 1);
        solve();
    }
    return 0;
}