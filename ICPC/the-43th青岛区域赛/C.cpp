#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = 1e14;
const int N = 1e6 + 10;
int t, n;
char s1[N], s2[N];
int main(){
    scanf("%d", &t);
    while(t -- ){
        vector<int> v;
        scanf("%d%s%s", &n, s1+1, s2+1);
        for(int i = 1;i <= n;i++){
            if(s1[i] != s2[i]) s1[i] = '1';
            else s1[i] = '0';
        }
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(s1[i]=='1'){
                cnt++;
            } else{
                if(cnt){
                    v.push_back(cnt);
                    cnt = 0;
                    if(v.size()>2) break;
                }
            }
        }
        if(cnt) v.push_back(cnt);
        //printf("cnt = %d\n", cnt);
        if(v.empty()){
            ll ans = n;
            printf("%lld\n", (1+ans)*ans/2);
            continue;
        }
        int m = v.size();
        if(m==1){
            printf("%d\n", (v[0]-1 + n-v[0])*2);
        }
        else if(m==2){
            printf("6\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}