/**
  *@filename:E1_Permutation_Minimization_by_Deque
  *@author: pursuit
  *@created: 2021-09-28 22:49
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, p[N];
void solve(){
    deque<int> q;
    q.push_back(p[1]);
    for(int i = 2; i <= n; ++ i){
        int x = q.front();
        if(p[i] < x)q.push_front(p[i]);
        else q.push_back(p[i]);
    }
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop_front();
    }
    cout << endl;
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &p[i]);
        }
        solve();
    }
    return 0;
}