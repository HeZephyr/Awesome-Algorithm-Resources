#include <bits/stdc++.h>

using namespace std;

int t, a, p;
int main(){	
    cin >> t;
    while(t -- ){
        cin >> a >> p;
        if(p >= 16 && p <= 20){
            printf("%d\n", a);
        }
        else if(p < 16){
            printf("%d\n", max(0, a - 10));
        }
        else{
            printf("%d\n", max(0, a - (p - 20)));
        }
    }
    return 0;
}