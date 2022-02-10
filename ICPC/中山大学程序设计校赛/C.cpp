#include<bits/stdc++.h>
using namespace std;

int a[3][3];
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &a[0][0], &a[0][1], &a[1][0]);
        if((6 * a[0][0] + 3 * a[0][1] + 3 * a[1][0]) % 4 != 0)puts("-1");
        else {
            int sum = (6 * a[0][0] + 3 * a[0][1] + 3 * a[1][0]) / 4;
            a[0][2] = sum - a[0][0] - a[0][1];
            a[2][0] = sum - a[0][0] - a[1][0];
            a[1][1] = sum - a[2][0] - a[0][2];
            a[1][2] = sum - a[1][0] - a[1][1];
            a[2][1] = sum - a[1][1] - a[0][1];
            a[2][2] = sum - a[2][0] - a[2][1];
            for(int i = 0; i <= 2; ++i){
                for(int j = 0; j <= 2; ++j){
                    if(i == 0 && j == 0)continue;
                    if(i == 0 && j == 1)continue;
                    if(i == 1 && j == 0)continue;
                    printf("%d ", a[i][j]);
                }
            } 
            printf("\n");
        }
    }
    return 0;
}