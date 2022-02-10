#include<bits/stdc++.h>

using namespace std;

int n, x;
char s[N];
int main(){
    cin >> n >> x;
    cin >> s + 1;
    int res = 0, cnt = 0;
    for(int i = 1; i <= n; ++ i){
        res = max(res, cnt);
        if(s[i] == '1')++ cnt;
        else cnt = 0;
    }
    res = max(res, cnt);
    if(res >= x){
        puts("Yes");
    }
    else{
        puts("No");
    }
    return 0;
}