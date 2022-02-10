/**
  *@filename:H_War_of_Inazuma(Easy_Version)
  *@author: pursuit
  *@created: 2021-08-16 12:21
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
void solve(){
    n = pow(2,n);
    for(int i = 0; i < n; ++ i){
        int temp = i,cnt = 0;
        while(temp){
            if(temp & 1)cnt ++;
            temp >>= 1;
        }
        if(cnt & 1)printf("1");
        else printf("0");
    }
    puts("");
}
int main(){	
    cin >> n;
    solve();
    return 0;
}