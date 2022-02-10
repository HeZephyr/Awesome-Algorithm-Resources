/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-20 15:24
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 200 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N],b[N];
bool vis[N];
void solve(){
    for(int i = 1; i <= n; ++ i){
        a[2 * i - 1] = b[i];
        vis[b[i]] = true;
    }
    bool flag = false;
    for(int i = 1; i <= 2 * n; i += 2){
        int temp = a[i];
        //找到最小的一个。
        while(vis[temp])temp ++;
        if(temp > 2 * n){
            flag = true;
            break;
        }
        a[i + 1] = temp;
        vis[temp] = true;
    }
    if(flag){
        puts("-1");
    }
    else{
        for(int i = 1; i <= 2 * n; ++ i){
            printf("%d ", a[i]);
        }
        puts("");
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        memset(vis,false,sizeof(vis));
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &b[i]);
        }
        solve();
    }
    return 0;
}