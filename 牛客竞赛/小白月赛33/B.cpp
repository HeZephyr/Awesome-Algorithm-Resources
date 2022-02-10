/**
  *@filename:B
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-17 19:57
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,p,q;
void solve(){
    vector<int> result;
    printf("%d/%d = ",p,q);
    if(p==0){
        //一定要特判。
        cout<<"0"<<endl;
        return;
    }
    while(p){
        int temp=p/q;
        p-=temp*q;
        result.push_back(temp);
        if(p!=0)swap(p,q);
    }
    cout<<result[0];
    int len=result.size();
    for(int i=1;i<len;i++){
        if(i==len-1){
            printf("+1/%d",result[i]);
        }
        else{
            printf("+1/{%d",result[i]);
        }
    }
    for(int i=2;i<len;i++){
        printf("}");
    }
    printf("\n");
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>p>>q;
            solve();
        }
    } 
    return 0;
}