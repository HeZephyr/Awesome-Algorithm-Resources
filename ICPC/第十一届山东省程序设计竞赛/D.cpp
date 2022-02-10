#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, x, y;
int row[N], col[N];
int main(){
    scanf("%d", &n);
    int res1 = 0, res2;
    for(int i = 1; i <= n; ++ i){
        scanf("%d%d", &y, &x);
        row[x] ++, col[y] ++;
        if(row[x] == 1)res1 += 2;
        if(row[x - 1] < row[x])++ res1;
        else -- res1;
        if(row[x + 1] < row[x])++ res1;
        else -- res1;
        if(col[y] == 1)res2 += 2;
        if(col[y - 1] < col[y])++ res2;
        else -- res2;
        if(col[y + 1] < col[y])++ res2;
        else -- res2;
        printf("%d %d\n", res2, res1);
    }
    return 0;
}