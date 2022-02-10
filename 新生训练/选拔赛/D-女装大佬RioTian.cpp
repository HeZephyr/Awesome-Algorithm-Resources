#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

int t,n,s,min_len;
int a[maxn];
int main(){
    cin>>t;
    while(t--){
        cin>>n>>s;
        for(int i=0;i<n;i++)cin>>a[i];
        min_len=maxn;
        int sum=0,cur=0,last=0;//双指针。
        while(cur<n){
            sum+=a[cur];
            while(sum>=s){
                min_len=min(min_len,cur-last+1);
                sum-=a[last++];
            }
            cur++;
        }
        if(min_len==maxn){
            cout<<"0"<<endl;
        }
        else{
            cout<<min_len<<endl;
        }
    }
    return 0;
}