/**
  *@filename:D_Another_Problem_About_Dividing_Numbers
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-06-10 22:54
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,a,b,k;
int num,e[N],q[N];
map<int,int> p;
int get(ll x){
	int temp = x;
	if(p[x]!=0) return p[x];
    int num=0;
    int m = sqrt(x+0.5);
    for(int i = 2;i <= m; ++ i){
        if(x % i == 0){
            e[ ++ num]=0;
            while(x % i == 0)
                e[num] ++,x/=i;
        }
    }
    if(x != 1){
        e[++ num]=1;
    }
    int sum = 0;
    for(int i = 1; i <= num; ++ i){
        sum += e[i];
    }
	p[temp] = sum;//记忆化。
    return sum;
    
}
void solve(){
    if(k == 1 && a == b){
        puts("NO");
    }
    else{
        int gcd = __gcd(a,b);
        int ans = 0;
        bool flag = false;
	    if(gcd != a) ans ++;
	    if(gcd != b) ans ++;
	    if(k < ans) flag = true;
        int a1 = a / gcd,b1 = b / gcd;
	    ans = get(gcd)*2 + get(a1) + get(b1);
	    if(k > ans) flag = true;	
	    if(flag){
            puts("NO");
        }
	    else{
            puts("YES");
        }
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> a >> b >> k;
        solve();
    }
    return 0;
}