/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-09-11 19:03
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, a[N];
int lMin[N], rMin[N], lMax[N], rMax[N];
void solve(){   
    //初始化这四个数组。
    for(int i = 2; i < n; ++ i){
        lMin[i] = a[i] >= a[lMin[i - 1]] ? lMin[i - 1] : i;
        lMax[i] = a[i] <= a[lMax[i - 1]] ? lMax[i - 1] : i;
    }
    for(int i = n - 1; i > 1; -- i){
        rMin[i] = a[i] >= a[rMin[i + 1]] ? rMin[i + 1] : i;
        rMax[i] = a[i] <= a[rMax[i + 1]] ? rMax[i + 1] : i;
    }
    for(int i = 2; i < n; ++ i){
        if(a[i] > a[lMin[i - 1]] && a[i] > a[rMin[i + 1]]){
            printf("3\n%d %d %d", lMin[i - 1], i, rMin[i + 1]);
            return;
        }
        if(a[i] < a[lMax[i - 1]] && a[i] < a[rMax[i + 1]]){
            printf("3\n%d %d %d", lMax[i - 1], i, rMax[i + 1]);
            return;
        }
    }
    puts("0");
}
int main(){	
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        lMin[i] = rMin[i] = lMax[i] = rMax[i] = i;
    }
    solve();
    return 0;
}