/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-09-26 21:13
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//转盘被分成n个部分。编号为0~n - 1。第i部分的面积为ai，则获得该数的概率为ai / (sum{aj});
//屏幕上显示的数为x，一开始x = 0，现在你需要使得x = n - 1来获得奖品。
//支付一枚硬币转动转盘一次，然后得到一个整数y。使得x = x ^ y，或者可以保持x不变。
//如果进行操作后的x值大于原来的值，则进行，否则保持不变。
void solve(){
}
int main(){	
    solve();
    return 0;
}