/**
  *@filename:B_Charmed_by_the_Game
  *@author: pursuit
  *@created: 2021-08-24 22:47
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;


//Alice赢了a局，Bob赢了b局。
//轮流发球。
//如果谁发球输了，说明一定是破发。
int t,a,b;
void solve(){
    //相差大于1。破发会使发球的输。要么A比B多发一次，要么B比A多发一次。
    //要么发的球数相同。但发的球数一定是a + b。因为一把会造成输赢。
    if(a < b)swap(a,b);
    //发球数为奇。
    if(a % 2 != b % 2){
        printf("%d\n", 2 * b + 2);
        //至少要进行(a - b) / 2次破发。
        for(int i = (a - b) / 2; i <= (a - b) / 2 + 2 * b + 1; ++ i){
            printf("%d ", i);
        }
    }
    else{
        printf("%d\n", (2 * b) / 2 + 1); 
        for(int i = (a - b) / 2; i <= (a - b) / 2 + b * 2; i += 2){
            printf("%d ", i);
        }
    }
    puts("");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &a, &b);
        solve();
    }
    return 0;
}