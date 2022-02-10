#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6 + 7;
char a[N];
int b[N];
int vis[N];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        scanf("%s", a + 1);
        int tot = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] == '1')b[i] = i;
            else b[i] = b[i - 1];
            vis[i] = 0; 
        }
        b[n + 1] = b[n];
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] =='1' && i == 1)continue;
            if(a[i] == '1' && i == n)continue;
            if(a[i] == '1' && a[i - 1] == '0' && a[i + 1] == '0'){
                int cnt1 = b[i] - b[i - 1] + 1, cnt2 = b[i + 1] - b[i] - 1;
                vis[i] = 1;
                if(cnt1%2 && cnt2%2){
                    if(cnt1 > cnt2)a[i - 1] = '1', vis[i - 1] = 1;
                    else a[i + 1] = '1', vis[i + 1] = 1;
                }
                else {
                    if(cnt1%2)a[i - 1] = '1', vis[i - 1] = 1;
                    else a[i + 1] = '1', vis[i + 1] = 1;
                }
                if(ans == 0)ans++;
            }
        }
        int sum = 0, id = 1;
        int sum1 = 0;
        int maxx = 0;
        //cout << ans << endl;
        //cout << a + 1 << endl;
        for(int i = 1; i <= n; ++i){
            if(a[i] == '0'){
                ++ sum;
            }
            else{
                if(!vis[i])sum--;
                if(id == 1){sum1 = sum,id =0;sum = 0; continue;}
                maxx = max(maxx, sum);
                sum = 0;
            }
        }
        for(int i = n; i >= 1; --i)
            if(a[i] == '1'){
                if(!vis[i])sum--;
                break;
            }
        ans += max((maxx + 1)/2, max(sum, sum1));

        printf("%d\n", ans);
    }
}