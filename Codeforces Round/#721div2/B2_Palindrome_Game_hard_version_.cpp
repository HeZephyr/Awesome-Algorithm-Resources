/**
  *@filename:B2_Palindrome_Game_hard_version_
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-24 09:41
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

//如初始s为回文串的时候，倘若其中有偶数个0，那么先手必须选择操作1，后手就可以镜像选择，使得整个串
//保持一个回文状态，而当只剩下一个0的时候，后手进行反转，先手只能选择操作1。此时先手花费多2.这个时候后手就可以继续这样结束比赛。
//倘若其中有奇数个0的时候，先手先将中间的0修改为1.保持回文性质。然后状态回到偶数个0.这样按照结论后手花费多1.先手必赢。
//但需要注意只有一个0的情况，先手必输。
//而如果不是回文
//对于Alice，最有利的情况就是一直不是回文串，这样Alice每次都可以进行反转操作。
//而对于Bob，必须进行操作1，所以他想尽快让字符串变回回文串。
//所以串长为奇数，且中间某个位置为0，那么无论怎么下都是平局。
//否则的话，Alice填堆成位置，Bob紧接着堆成位置，串还是非回文。而且双方消耗先沟通，情况无变化。所以堆成0.
//但先手可以让后手吧所有非堆成的全下了。故贡献大于1，先手胜。
void solve(){
}
int main(){
    int t,n;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> s;
        int flag = 0;
        for(int i = 0;i <= n / 2 - 1; i++){
            flag += (s[i] != s[n - i - 1]);
        }
        int cnt = 0;
        for(int i = 0;i < n; i++){
            cnt += (s[i] == '0');
        }
        if(!flag){
            if(cnt == 0){
                puts("DRAW");
            }
            else if(cnt % 2 == 0 || cnt == 1){
                puts("BOB");
            }
            else{
                puts("ALICE");
            }
        }
        else if(flag == 1 && cnt == 2){
            puts("DRAW");
        }
        else{
            puts("ALICE");
        }
    }
    solve();
    return 0;
}