/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-28 15:03
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e2 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n;
char s[N][N];
bool check(int x)
{
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= x;j++){
            if(!vis[s[i][j]-'a']) cnt++;
            vis[s[i][j]-'a']++;
        }
    }
    if(cnt==x) return true;
    for(int i = 1;i+x <= m;i++){
        
    }
}
        while(l<=r){
            int mid = l+r>>1;
            if(check(mid)){
                ans = mid;
                r = mid-1;
            } else {
                l = mid+1;
            }
        }