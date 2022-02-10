/**
  *@filename:D1_Two_Hundred_Twenty_One_easy_version_
  *@author: pursuit
  *@created: 2021-08-26 23:57
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 3e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,q;
char s[N];
int sum1[N],sum2[N];
void solve(){
    for(int i = 1; i <= n; ++ i){
        if(i & 1){
            sum1[i] = sum1[i - 1] + (s[i] == '+' ? 1 : -1);
            sum2[i] = sum2[i - 1] - (s[i] == '+' ? 1 : -1);
        }
        else{
            sum1[i] = sum1[i - 1] - (s[i] == '+' ? 1 : -1);
            sum2[i] = sum2[i - 1] + (s[i] == '+' ? 1 : -1);
        }
    }
    int l,r;
    while(q -- ){
        scanf("%d%d", &l, &r);
        if((r - l + 1) & 1){
            puts("1");
        }
        else if(l & 1){
            if(sum1[r] - sum1[l - 1]){
                puts("2");
            }
            else{
                puts("0");
            }
        }
        else{
            if(sum2[r] - sum2[l - 1]){
                puts("2");
            }
            else{
                puts("0");
            }
        }
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &q);
        scanf("%s", s + 1);
        solve();
    }
    return 0;
}