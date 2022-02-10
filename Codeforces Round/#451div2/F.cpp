/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-12 15:55
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
int base = 10;//base为基底，其代表了为几进制数。
ll Hash[N],p[N];
string s;  
//字符串hash，写法有很多种。
//不过思路都是一样的，就是要用唯一的数值确定一段字符串。所以也跟mod有关。
void init(){
    n = s.size();
    for(int i = 0; i < n; ++ i){
        Hash[i + 1] = (Hash[i] * base % P + s[i] - '0') % P;
    }
    p[0] = 1;//base ^ i
    for(int i = 0; i < n; ++ i){
        p[i + 1] = p[i] * base % P;
    }
}
int get(int l,int r){
    //获取[l,r]子串。
    if(r < 0 || l - 1 < 0 || r - l + 1 < 0)return 0;
    return (Hash[r] - Hash[l - 1] * p[r - l + 1] % P + P) % P;
}
bool check(int lenA,int lenB,int lenC){
    if(lenA > lenC || lenB > lenC)return false;
    if(lenA < 0 || lenB < 0)return false;
    if(s[lenA] == '0' && lenB != 1)return false;
    if(s[0] == '0' && lenA != 1)return false;
    if((get(1,lenA) + get(lenA + 1,lenA + lenB)) % P != get(lenA + lenB + 1,n)){
        return false;
    }
    return true;
}
void print(int lenA,int lenB,int lenC){
    for(int i = 0; i < lenA; ++ i){
        putchar(s[i]);
    }
    putchar('+');
    for(int i = lenA; i < lenA + lenB; ++ i){
        putchar(s[i]);
    }
    putchar('=');
    for(int i = lenA + lenB; i < n; ++ i){
        putchar(s[i]);
    }
}
void solve(){
    for(int lenC = 1; lenC < n; ++ lenC){
        if(s[n - lenC] == '0' && lenC > 1)continue;//排除前导0的情况。
        //cout << lenC << endl;
        if(check(lenC,n - 2 * lenC,lenC)){
            print(lenC,n - 2 * lenC,lenC);
            break;
        }
        else if(check(n - 2 * lenC,lenC,lenC)){
            print(n - 2 * lenC,lenC,lenC);
            break;
        }
        else if(check(lenC - 1,n - 2 * lenC + 1,lenC)){
            print(lenC - 1,n - 2 * lenC + 1,lenC);
            break;
        }
        else if(check(n - 2 * lenC + 1,lenC - 1,lenC)){
            print(n - 2 * lenC + 1,lenC - 1,lenC);
            break;
        }
    }
}
int main(){
    cin >> s;
    init();
    solve();
    return 0;
}