#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int maxn=1e4+5;
int n;
string s[maxn];
void solve(){
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i].find("@wyk")!=s[i].npos){
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    while(cin>>n){
        getchar();
        for(int i=0;i<n;i++){
            getline(cin,s[i]);
        }
        solve();
    }
    return 0;
}