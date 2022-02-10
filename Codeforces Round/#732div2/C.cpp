/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-12 10:32
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N];
int odd[N],even[N];
void solve(){
    sort(a + 1, a + n + 1);
    bool flag = true;
    for(int i = 1; i <= n; ++ i){
        if(i & 1){
            if(odd[a[i]] == 0){
                flag = false;
                break;
            }
            else{
                odd[a[i]] --;
            }
        }
        else{
            if(even[a[i]] == 0){
                flag = false;
                break;
            }
            else{
                even[a[i]] --;
            }
        }
    }
    if(flag){
        puts("YES");
    }
    else{
        puts("NO");
    }
    memset(odd,0,sizeof(odd));
    memset(even,0,sizeof(even));
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]); 
            if(i & 1)odd[a[i]] ++;
            else even[a[i]] ++;
        }
        solve();
    }
    return 0;
}