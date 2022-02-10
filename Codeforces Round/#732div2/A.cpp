/**
  *@filename:A
  *@author: pursuit
  *@created: 2021-08-12 09:27
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 100 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N],b[N];
int sum1,sum2;
vector<pii> v1,v2;
void solve(){
    if(sum1 != sum2){
        puts("-1");
    }
    else{
        sum1 = 0;
        v1.clear(),v2.clear();
        for(int i = 1; i <= n; ++ i){
            if(a[i] < b[i]){
                sum1 += b[i] - a[i];
                v1.push_back({i,b[i] - a[i]});
            }
            else if(a[i] > b[i]){
                v2.push_back({i,a[i] - b[i]});
            }
        }
        printf("%d\n", sum1);
        int idx1 = 0,idx2 = 0;
        while(idx1 < v1.size() && idx2 < v2.size()){
            printf("%d %d\n",v2[idx2].first, v1[idx1].first);
            v2[idx2].second --,v1[idx1].second --;
            if(v2[idx2].second == 0)idx2 ++;
            if(v1[idx1].second == 0)idx1 ++;
        }
    }
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        sum1 = 0,sum2 = 0;
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            sum1 += a[i];
        }
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &b[i]);
            sum2 += b[i];
        }
        solve();
    }
    return 0;
}