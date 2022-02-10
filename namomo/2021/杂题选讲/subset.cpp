/**
  *@filename:subset
  *@author: pursuit
  *@created: 2021-10-26 13:40
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//给出n个数，求出两个不相交的subset，使得他们的和一样。n, a[i] <= 1e5;
//前22个数能构成2^22个数，而对于前22个数，和取值范围为[0, 22 * 10 ^ 5];所以根据鸽笼原理一定有两个数是相等的。
//如果存在相同的选取值，那么把公共部分剪掉即可。
int n, a[N];
void solve(){
}
int main(){	
    solve();
    return 0;
}