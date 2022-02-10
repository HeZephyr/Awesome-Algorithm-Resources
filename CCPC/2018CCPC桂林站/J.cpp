#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int a[maxn], b[maxn];
int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
            b[i] = 0;
        }
        int cnt = 0;
        a[0] = a[n + 1] = 0;
        for(int i = 1; i <= n; ++ i){
            if(a[i] < a[i + 1]){
                b[i] = cnt ++;
            }
            else{
                b[i] = cnt;
                cnt = 0;
            }
        }
        cnt = 0;
        for(int i = n; i >= 1; -- i){
            if(a[i] < a[i - 1] && !b[i]){
                b[i] = cnt ++;
            }
            else{
                b[i] = max(b[i], cnt);
                cnt = 0;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            //cout << b[i] << " " ;
            ans += a[i] - b[i];
        }
        //cout << endl;
        //cout << ans << endl;
        if(ans % 2)printf("Case %d: Alice\n", t);
        else printf("Case %d: Bob\n", t);
    }
}