#include<bits/stdc++.h>

using namespace std;

int t, n;
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        if(n <= 5){
            puts("-1");
        }
        else{
            if(n & 1){
                cout << 3 << " " << n - 3 << endl;
            }   
            else{
                cout << 2 << " " << n - 2 << endl;
            }
        }
    }
    return 0;
}