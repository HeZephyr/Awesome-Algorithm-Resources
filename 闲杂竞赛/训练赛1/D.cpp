/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-08 19:05
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,k,a[N];
void solve(){
    sort(a + 1,a + 1 + n);
    int x = 1;
    int cnt = 0;
    bool flag = true;
    for(int i = 1; i <= n; ++ i){
        if(a[i] <= x){
            cnt ++;
        }
        else{
            if(cnt == k){
                if(i == n || (i < n && a[i + 1] != x)){
                    printf("%d\n", x);
                    return;
                }
                else{
                    flag = false;
                    break;
                }
            }
            else if(cnt > k){
                flag = false;
                break;
            }
            else{
                x = a[i];
                cnt ++;
            }
        }
    }
    if(!flag || cnt != k){
        printf("-1\n");
    }
    else{
        printf("%d\n", x);
    }
}
int main(){	
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}