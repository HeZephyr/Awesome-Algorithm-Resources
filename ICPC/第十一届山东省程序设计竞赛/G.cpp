#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
char s[505][505], a[505][505], b[505][505];
int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++){
        scanf("%s", s[i]+1);
        for(int j = 1;j <= m;j++){
            a[i][j] = b[i][j] = s[i][j];
        }
    }

    for(int j = 1;j <= m;j++){
        a[1][j] = '1';
    }
    for(int j = 2;j <= m;j+=2){
        for(int i = 2;i < n;i++)
            a[i][j] = '1';
    }
    for(int j = 1;j <= m;j++){
        b[n][j] = '1';
    }
    for(int j = 1;j <= m;j+=2){
        for(int i = 2;i < n;i++)
            b[i][j] = '1';
    }
//    for(int i = 1;i <= n;i++){
//        for(int j = 1;j <= m;j++){
//            if((a[i][j]-'0') & (b[i][j]-'0') != s[i][j]-'0')
//                printf("NO\n");
//        }
//    }
    //输出
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++)
            printf("%c", a[i][j]);
        printf("\n");
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++)
            printf("%c", b[i][j]);
        printf("\n");
    }
    return 0;
}
