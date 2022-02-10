/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-09-01 10:55
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, s, k;
/*
n个整数， 数组的元素总和为s。Petya选择一个整数k。
找到一个非空子数组，使得总和为s或者k - s。
*/
void solve(){
    if(2 * n > s){
        puts("NO");
    }
    else{
        puts("YES");
        for(int i = 0; i < n - 1; ++ i){
            printf("2 ");
        }
        printf("%d\n", s - (n - 1) * 2);
        puts("1");
    }
}
int main(){	
    scanf("%d%d", &n, &s);
    solve();
    return 0;
}