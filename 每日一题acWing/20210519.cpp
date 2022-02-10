#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 2e4+10,INF = 0x3f3f3f3f,P = 1e9+7;

int n;
void solve(int n){
    if(n==0)return;
    int p=log2(n);
    if(p==0){
        cout<<"2(0)";
    }
    else if(p==1){
        cout<<"2";
    }
    else if(p>1){
        cout<<"2(";
        solve(p);
        cout<<")";
    }
    if(n!=1<<p){
        cout<<"+";
        solve(n-(1<<p));
    }
    
}
int main(){
    while(cin>>n){
        solve(n);
        cout<<endl;
    }
    return 0;
}