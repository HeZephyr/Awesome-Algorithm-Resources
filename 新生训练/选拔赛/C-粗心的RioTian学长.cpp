#include<bits/stdc++.h>

using namespace std;

const int maxn=105;
int n,a[maxn];

bool cmp(int a,int b){
    return abs(a)>abs(b);
}
int main(){
    while(cin>>n&&n>0){
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++){
            cout<<a[i];
            i==n-1?cout<<endl:cout<<" ";
        }
    }
    return 0;
}