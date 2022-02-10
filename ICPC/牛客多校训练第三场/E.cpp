/**
  *@filename:E
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-29 10:37
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

template<typename T>void write(T x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9){
        write(x / 10);
    }
    putchar(x % 10 + '0');
}
 
template<typename T> void read(T &x)
{
    x = 0;
    char ch = getchar();
    ll f = 1;
    while(!isdigit(ch)){
        if(ch == '-')
            f *= -1;
        ch = getchar();
    }
    while(isdigit(ch)){
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    x *= f;
}
vector<__int128> result;
int t;
__int128 n;
void init(){
    result.push_back(1);//x = 1,y = 1，只有一种情况。
    //注意，这里long long存不下。要使用__int128
    for(__int128 a = 2; a <= 1e6; ++ a){
        //先列出构造的解，再不断递推。
        __int128 x = a, y = a * a * a, k = a * a;
        while(y <= 1e18){
            result.push_back(y);
            __int128 temp = k * y - x;
            x = y;
            y = temp;
        }
    }
    sort(result.begin(),result.end());
}
void solve(){
    write(upper_bound(result.begin(),result.end(),n) - result.begin());
    putchar('\n');
}
int main(){
    init();
    read(t);
    while(t -- ){
        read(n);
        solve();
    }
    return 0;
}