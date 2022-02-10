#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e3 + 10;

char s[N];
int main(){
    scanf("%s", &s);
    int len = strlen(s);
    bool flag = false;
    for(int i = 0; i < len; ++ i){
        if(s[i] >= 'a' && s[i] <= 'z' && i != 0){
            flag = true;
            break;
        }
    }
    if(!flag){
        for(int i = 0; i < len; ++ i){
            if(s[i] >= 'a' && s[i] <= 'z')s[i] -= 32;
            else s[i] += 32;
        }
    }
    printf("%s", s);
    return 0;
}