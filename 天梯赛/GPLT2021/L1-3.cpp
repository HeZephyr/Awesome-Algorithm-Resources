#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e5+10;

int n,m,k;
string h;
string s[maxn];
ll a[maxn];
int pos[maxn];
bool cmp(int i,int j){
    return a[i]<a[j];
}
int main(){
    cin>>n;
    getchar();
    getline(cin,h);
    cin>>m;
    for(int i=1;i<=m;i++){
        pos[i]=i;
        cin>>k;
        getline(cin,s[i]);
        a[i]=h.find(s[i]);
    }
    sort(pos+1,pos+1+m,cmp);
    for(int i=1;i<=m;i++){
        cout<<pos[i];
        i==m?cout<<endl:cout<<" ";
    }
    return 0;
}