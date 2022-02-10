/**
  *@filename:H-解谜游戏
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-04 20:35
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

string s1,s2,s3;
void solve(){
    bool flag = false;
    for(int i = 0 ; i < 4; ++ i){
        //将这个分成四块，判断每一块是不是满足即可。
        map<char,int> p;
        //内圈。
        p[s1[i]] ++;
        //中圈。
        p[s2[i]] ++;
        p[s2[i + 4]] ++;
        //外圈。
        p[s3[i]] ++;
        p[s3[i + 4]] ++;
        p[s3[i + 8]] ++;
        if(p['Y'] != 1 || p['R'] != 2 || p['G'] != 3){
            flag = true;
            break;
        }
    }
    if(flag){
        puts("NO");
    }
    else{
        puts("YES");
    }
}
int main(){
    int t;
    cin >> t;
    while(t -- ){
        cin >> s3 >> s2 >> s1;
        solve();
    }
    return 0;
}