#include<bits/stdc++.h>

using namespace std;

int t;
long long g,l;
void solve(){
    if(l%g)cout<<-1<<endl;
    else cout<<g<<" "<<l<<endl;
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>g>>l;
            solve();
        }
    }
    return 0;
}