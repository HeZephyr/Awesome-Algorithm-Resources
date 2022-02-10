/**
  *@filename:C
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-26 12:01
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,a,b,c;
string s1,s2,s3;
void solve(){
    int minn = min(a,min(b,c));
    //判断情况。
    if(a + b - minn > n || a + c - minn > n || b + c - minn > n){
        cout << "NO" << endl;
    }
    else{
        for(int i = 0; i < minn; ++ i){
            s1 += "a";
            s2 += "a";
            s3 += "a";
        }
        for(int i = 0; i < a - minn; ++ i){
            s1 += "b";
            s2 += "b";
        }
        for(int i = 0; i < b - minn; ++ i){
            s2 += "c";
            s3 += "c";
        }
        for(int i = 0; i < c - minn; ++ i){
            s1 += "d";
            s3 += "d";
        }
        while(s1.size() < n)s1 += "e";
        while(s2.size() < n)s2 += "f";
        while(s3.size() < n)s3 += "g";
        cout << s1 << endl;
        cout << s2 << endl;
        cout << s3 << endl;
    }
}
int main(){
    cin >> a >> b >> c >> n;
    solve();
    return 0;
}