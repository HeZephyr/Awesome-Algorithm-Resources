#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

char s[N];
int main(){
    int t;
    scanf("%d", &t);
    while(t -- ){
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        int cnt = 0;
        s[n + 1] = '0';
        for(int i = 1; i <= n; ++ i){
            if(s[i] == s[i + 1]){
                ++ cnt;
            }
        }
        printf("%d\n", cnt + n);
    }
    return 0;
}