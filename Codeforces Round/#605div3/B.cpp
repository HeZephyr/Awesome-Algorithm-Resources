/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-21 15:05
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int q,u,r,l,d;
string s;
/*
访问了除(0,0)单元格两次，就会中断。
有多少个R就要有多少个L，同理有多少个U就要有多少个D。
*/
void solve(){
    for(int i = 0; i < s.size(); ++ i){
        if(s[i] == 'U')u ++;
        else if(s[i] == 'R')r ++;
        else if(s[i] == 'L')l ++;
        else d ++;
    }
    int minn1 = min(u,d),minn2 = min(l,r);
    if(minn1 == 0 || minn2 == 0){
        if(minn1 >= 1 || minn2 >= 1){
            if(minn1 >= 1){
                cout << 2 << '\n' << "UD" << endl; 
            }
            else{
                cout << 2 << '\n' << "LR" << endl;
            }
        }
        else{
            cout << 0 << endl;
        }
    }
    else{
        u = d = minn1,l = r = minn2;
        cout << 2 * minn1 + 2 * minn2 << endl;
        //绕个正方形。
        for(int i = 0; i < u; ++ i){
            cout << 'U';
        }
        for(int i = 0; i < l; ++ i){
            cout << 'R';
        }
        for(int i = 0; i < d; ++ i){
            cout << 'D';
        }
        for(int i = 0; i < r; ++ i){
            cout << 'L';
        }
        cout << endl;
    }
}
int main(){	
    cin >> q;
    while(q -- ){
        u = r = l = d = 0;
        cin >> s;
        solve();
    }
    return 0;
}