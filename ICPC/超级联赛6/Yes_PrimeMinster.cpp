/**
  *@filename:Yes_PrimeMinster
  *@author: pursuit
  *@created: 2021-08-05 12:03
**/
#include <bits/stdc++.h>
#define debug(a) cout << (#a)<< ":" << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e7 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,x;
int prime[N];//保存素数 
bool vis[N];//初始化 
int ans;
void init(){
	int cnt = 0;
	memset(vis,0,sizeof(vis));
    vis[1] = true;
	for(int i = 2; i < N; ++ i){
		if(!vis[i])
		prime[cnt ++ ]=i;
		for(int j = 0; j < cnt && i * prime[j] < N; ++ j){
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0)//关键 
			break;
		}
	}
}
void solve(){
    if(x > 0){
        if(!vis[x]){
            cout << 1 << endl;
            return;
        }
        else if(!vis[2 * x + 1] || !vis[2 * x - 1]){
            //debug(ans);
            cout << 2 << endl;
            return;
        }
    }
    x = abs(x) + 1;
    while(true){
        if(!vis[x]){
            cout << 2 * x << endl;
            //debug(x);
            break;
        }
        else if(!vis[2 * x + 1]){
            cout << 2 * x + 1 << endl;
            break;
        }
        x ++;
    }
}
int main(){
    scanf("%d", &t);
    init();
    while(t -- ){
        scanf("%d", &x);
        solve();
    }	
    return 0;
}