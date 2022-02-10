#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 510;

int t, n;
char s[N];
int ans1[2], ans2[2];
bool check(int cnt, int op){
    //cout << cnt << " " << ans1[op] + ans2[op] << " " << ans1[op ^ 1] << endl;
    int ans = ans1[op] + ans2[op] - ans1[op ^ 1];
    int temp = (op ^ 1) ? (9 - cnt + 1) / 2 : (9 - cnt) / 2;
    if(ans > temp)return true;
    else return false;
}
void solve(){
    memset(ans1, 0, sizeof(ans1)); 
    memset(ans2, 0, sizeof(ans2));

    for(int i = 0; i < 10; ++ i){
        if(s[i] == '1')++ ans1[i & 1];
        if(s[i] == '?')++ ans2[i & 1];
        if(check(i, 0) || check(i, 1) || i == 9){
            printf("%d\n", i + 1);
            break;
        }
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%s", s);
        solve();
    }
    return 0;
}