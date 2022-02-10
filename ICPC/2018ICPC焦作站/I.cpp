#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn = 1e6 + 7;
int a[maxn];
ll c[maxn];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        c[1] = 1;
        for(int i = 2; i <= n; ++i){
            scanf("%d", &a[i]);
            c[i] = c[i - 1] + a[i];
        }
        long long  sum = 0;
        printf("0");
        if(n != 1)printf(" ");
        ll pre = 0, last = 0;
        int cnt1 = 0, cnt2 = 0;
        int L = 1, R = n;
        if(n >= 2){
            cnt1++;cnt2++;
            L++, R--;
            pre += c[1]; last += c[n];
            sum += c[n] - c[1];
            printf("%lld", sum);
            if(n != 2)printf(" ");
        }
        for(int i = 3; i <= n; ++i){
            int tmp;
            if(i % 2){
                tmp = L,L++;
            }   else tmp = R, R--;
            sum += c[tmp] * cnt1 - pre + last - c[tmp] * cnt2;
            if(i % 2)pre += c[tmp], cnt1++;
            else last += c[tmp], cnt2++;
            printf("%lld", sum);
            if(i != n)printf(" ");
        }
        printf("\n");
    }
}