/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-10-15 19:12
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e7 + 1;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, s, tot;
int primer[N];
bool check[N];
void init(){
    for(int i = 2; i < N; ++ i){
        if(!check[i]){
            primer[++ tot] = i;
        }
        for(int j = 1; j <= tot; ++ j){
            if(i * primer[j] >= N)break;
            check[i * primer[j]] = true;
            if(i % primer[j] == 0)break;
        }
    }
    //cout << tot << endl;
}
void solve(){
    if(!s){
        puts("1\n0 = 0");
    }
    else{
        int cnt = 0;
        int idx = lower_bound(primer + 1, primer + tot + 1, s) - primer;
        if(idx <= tot && primer[idx] == s){
            printf("1\n%d = %d\n", s, s);
            return;
        }
        if(s > 1 && (s % 2)){
            int idx = lower_bound(primer + 1, primer + tot + 1, s - 2) - primer;
            if(primer[idx] + 2 == s){
                printf("2\n2 + %d = %d\n", primer[idx], s);
                return;
            }
        }
        vector<int> res;
        ll temp = s;
        if(s & 1)res.push_back(1), -- s;
        if(s == 2){
            res.push_back(2);
            s = 0;
        }
        for(int i = 1; i <= tot; ++ i){
            if(primer[i] > s)break;
            int idx = lower_bound(primer + 1, primer + tot + 1, s - primer[i]) - primer;
            if(primer[i] + primer[idx] == s){
                res.push_back(primer[i]);
                res.push_back(primer[idx]);
                break;
            }
        }
        cout << res.size() << endl;
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); ++ i){
            cout << res[i];
            if(i == res.size() - 1){
                cout << " = ";
            }
            else{
                cout << " + ";
            }
        }
        cout << temp << endl;
    }
}
int main(){	
    scanf("%d", &t);
    init();
    while(t -- ){
        scanf("%d", &s);
        solve();
    }
    return 0;
}