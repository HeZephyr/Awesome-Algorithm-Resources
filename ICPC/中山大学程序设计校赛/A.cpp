#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, t;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        if(a+b==0) printf("0\n");
        else if(a+b<=1e6) printf("%d\n", 1000000-a-b);
        else printf("%d\n", 2000000-a-b);
    }
    return 0;
}