#include<bits/stdc++.h>

using namespace std;

const int maxn=2010;

int t,n,h[maxn];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> odd,even;//为了凑成偶数，因为奇数+奇数=偶数，偶数+偶数=偶数。根据贪心，所以先排奇数再排偶数,或者先拍偶数再排奇数。
        for(int i=0;i<n;i++){
            cin>>h[i];
            if(h[i]%2==0)even.push_back(h[i]);
            else odd.push_back(h[i]);
        }
        for(int i=0;i<odd.size();i++){
            cout<<odd[i]<<" ";
        }
        for(int i=0;i<even.size();i++){
            cout<<even[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}