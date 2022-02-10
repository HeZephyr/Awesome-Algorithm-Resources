#include<bits/stdc++.h>

using namespace std;

int t, x, y;
int main(){
    cin >> t;
    while(t -- ){
        cin >> x >> y;
        if((x + y) % 2 == 0){
            int temp = (x + y) / 2;
            for(int i = 0; i <= x; ++ i){
                if(i <= x && temp - i <= y){
                    printf("%d %d\n", i, temp - i);
                    break;
                }
            }
        }
        else{
            printf("-1 -1\n");
        }
    }
    return 0;
}