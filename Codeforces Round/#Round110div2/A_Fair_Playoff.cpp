/**
  *@filename:A_Fair_Playoff
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 22:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,a[4],pos[4];
bool cmp(int i,int j){
    return a[i] < a[j];
}
void solve(){
    sort(pos,pos + 4,cmp);
    int id1,id2;
    if(a[0] > a[1]){
        id1 = 0;
    }
    else{
        id1 = 1;
    }
    if(a[2] > a[3]){
        id2 = 2;
    }
    else{
        id2 = 3;
    }
    if((id1 == pos[2] && id2 == pos[3]) || (id1 == pos[3] && id2 == pos[2])){
        puts("YES");
    }
    else{
        puts("NO");
    }
}
int main(){
    cin >> t;
    while(t -- ){
        for(int i = 0;i < 4; ++ i){
            cin >> a[i];
            pos[i] = i;
        }
        solve();
    }
    return 0;
}