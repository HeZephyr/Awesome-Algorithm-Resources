#include<bits/stdc++.h>

using namespace std;

int t, a[5];
int main(){
    scanf("%d", &t);
    while(t -- ){
        int cnt = 0;
        for(int i = 1; i <= 4; ++ i){
            scanf("%d", &a[i]);
            if(a[i])++ cnt;
        }
        if(cnt == 0){
            puts("Typically Otaku");
        }
        else if(cnt == 1){
            puts("Eye-opener");
        }
        else if(cnt == 2){
            puts("Young Traveller");
        }
        else if(cnt == 3){
            puts("Excellent Traveller");
        }
        else{
            puts("Contemporary Xu Xiake");
        }
    }
    return 0;
}