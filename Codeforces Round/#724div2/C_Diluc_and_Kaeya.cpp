/**
  *@filename:C_Diluc_and_Kaeya
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-06 23:21
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = 100000 + 5;
const int P = 1e9+7;

//我们知道，我们可以存储它们的比。
map<pii,int> p;//其中pii的first代表D，second代表K，则first:second即为它们的比，而int则为比例出现次数。
int t,n;
int gcd(int n,int m){
    if(m == 0){
        return n;
    }
    return n % m ? gcd(m,n % m) : m;
}
string s;
void solve(){
    p.clear();
    int d = 0,k = 0;
    for(int i = 0; i < n; ++ i){
        if(s[i] == 'D')d ++ ;
        else k ++;
        int g = gcd(d,k);
        cout << ++ p[{d / g, k / g}] << " ";
    }
    cout << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n >> s;
        solve();
    }
    return 0;
}