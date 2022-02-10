/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-23 20:24
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,r,a[N];
void solve(){
    //last为上次使用加热器的位置。
    int last = 0, res = 0, i = 1, j, k;
    while(i <= n){
        j = i + r - 1, k = 0;
        //j为管理i的最右边的点。我们需要在j以内找到一个加热器。
        if(j > n)j = n;
        while(j > last){
            if(a[j]){
                k = j;
                break;
            }
            else{
                -- j;
            }
        }
        if(!k){
            //说明没有找到加热器。
            res = -1;
            break;
        }
        else{
            last = k, i = k + r;
            ++ res;
        }
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d%d", &n, &r);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}