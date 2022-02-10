#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 5e4;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, x;
bool vis[N];
int primer[N], tot;
void getPrime(){
	for(int i=2;i<N;i++){
        if(!vis[i]) primer[tot ++] = i;
        for(int j = 0; primer[j] <= N/i; ++ j){
            vis[primer[j]*i] = true;
            if(i%primer[j]==0) break;
        }
    }
}
int main(){
    scanf("%d", &t);
    getPrime();
    while(t -- ){
        scanf("%d", &x);
        int cnt = 0;
        for(int i = 0; i < tot; ++ i){
            if((primer[i] ^ x) < x)++ cnt;
        }
        cout << cnt << endl;
    }	
    return 0;
}