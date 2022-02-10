/**
  *@filename:B_Card_Deck
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-19 19:43
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n,p[N];
int pos[N];
bool cmp(int i,int j){
    return p[i] > p[j];
}
void solve(){
    sort(pos + 1,pos + 1 + n,cmp);
    int idx = 1,last = n + 1;
    while(pos[idx] > 1){
        for(int i = pos[idx]; i < last; ++ i){
            cout << p[i] << " ";
        }
        last = pos[idx];
        while(pos[idx] >= last){
            idx ++;
        }
    }
    for(int i = 1; i < last ; ++ i){
        cout << p[i] << " ";
    }
    cout << endl;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &p[i]);
            pos[i] = i;
        }
        solve();
    }
    return 0;
}