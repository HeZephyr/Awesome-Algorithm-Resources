/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-20 19:14
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,x,k,a[N],idx;
vector<int> v;
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(a[i] < x){
            v.push_back(i);
        }
    }
    if(v.size() < k - 1){
        puts("0");
    }
    else{
        int l = 0,r = k - 2;
        ll ans = 0;
        while(true){
            //考虑l 和 r包不包含idx。
            ll temp1 = 0,temp2 = 0;
            if(v[r] < idx){
                //此时判断下一位是不是超过了idx。
                if(r + 1 == v.size() || (r + 1 < v.size() && v[r + 1] > idx)){
                    //说明[idx, v[r + 1])都是可行的。
                    if(r + 1 == v.size()){
                        temp1 = n - v[r] + 1;
                    }
                    else{
                        temp1 = v[r + 1] - idx;
                    }
                }
                l ++,r ++;
            }
            if(v[l] > idx){
                //说明此时只能够依次。左移到了那边。
                if(l == 0 || v[l - 1] > idx){
                    if(l == 0){
                        temp2 = 
                    }
                }
            }
        }
    }
    printf("%lld\n", ans);
}
int main(){	
    scanf("%d%d%d", &n, &x, &k);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
        if(a[i] == x)idx = i;
    }
    solve();
    return 0;
}