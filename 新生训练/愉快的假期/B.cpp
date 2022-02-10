#include<bits/stdc++.h>

using namespace std;

int t;
long long n;
void solve(){
    cout<<2*n*n-n+1<<endl;
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n;
            solve();
        }
    }
    return 0;
}