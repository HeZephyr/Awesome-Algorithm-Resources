#include<bits/stdc++.h>

using namespace std;

unordered_map<int,int> p;
int n,result;
int main(){
    while(cin>>n){
        p.clear();
        int temp;
        for(int i=0;i<n;i++){
            cin>>temp;
            p[temp]++;
            if(p[temp]==(n+1)/2){
                result=temp;
            }
        }
        cout<<result<<endl;
    }
    return 0;
}