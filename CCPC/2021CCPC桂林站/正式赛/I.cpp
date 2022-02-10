#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6 + 7;
int a[N];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        string s;
        cin >> s;
        int len = s.length();
        int fir, las;
        fir = 0, las = 0;
        s = '0' + s;
        int ans = 0;
        for(int i = 1; i < len; ++i){
            if(a[i] == '1' && i == 1)continue;
            if(a[i] == '1' && a[i - 1] == '0' && a[i + 1] == '1'){
                int q = i - 1;
                int cnt1 = 0, cnt2 = 0;
                while(a[q] == '0' && q < len)cnt1++;
                q = i + 1;
                while(a[q] == '0' && q < len)cnt2++;
                if(cnt1%2 && cnt2%2){
                    if(cnt1 > cnt2)a[i - 1] = '1';
                    else a[i + 1] = '1';
                }
                else {
                    if(cnt1%2)a[i - 1] = '1';
                    else a[i + 1] = '1';
                }
                i = q - 1;
                ans++;
            }
        }
        int sum = 0;
        for(int i = 1; i < len; ++i){
            if(a[i] == '0')sum++;
        }
        ans += (sum + 1)/2;
        printf("%d\n", ans);
    }
}