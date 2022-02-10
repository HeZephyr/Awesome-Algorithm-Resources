#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 1e7 + 100;
int mark[maxn], prime[maxn];
int sum[maxn];
void orl(int n){
    mark[1] = 1;
    sum[1] = 1;
    for(int i = 2; i <= n; ++i){
        sum[i] = sum[i - 1];
        if(!mark[i]){
            prime[++prime[0]] = i;
            sum[i]++;
        }
        for(int j = 1; j <= prime[0]; ++j){
            ll x = prime[j] * i;
            if(x > n)break;
            mark[x] = 1;
            if(i % prime[j] == 0)break;
        }
    }
    //cout << sum[2];
}
bool judge(int n){
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0)return false;
    }
    return true;
}
int main(){
    int M = 1e7;
    orl(M);
    int T;
    scanf("%d", &T);
    while(T--){
        int l, r;
        scanf("%d %d", &l, &r);
        if(r > M){
            if(r - l + 1 > 50)printf("Yes\n");
            else {
                int flag = 1;
                int cnt = 0;
                for(int i = l; i <= r; ++i){
                    if(judge(i))cnt++;
                }
                if(cnt * 3 < r - l + 1)printf("Yes\n");
                else printf("No\n");
            }
        }
        else {
            int cnt = sum[r] - sum[l - 1];
            if(cnt * 3 < r - l + 1)printf("Yes\n");
            else printf("No\n");
        }
    }

}
