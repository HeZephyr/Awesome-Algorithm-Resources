/**
  *@filename:B
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-18 14:37
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;
int a[10];
bool work(int x){
    while(x){
        int temp=x%10;
        x/=10;
        if(a[temp]>0){
            a[temp]--;
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    while(cin>>n){
        for(int i=0;i<=9;i++)a[i]=n;
        int cnt=1;
        while(true){
            if(work(cnt)){
                cnt++;
            }
            else{
                break;
            }
        }
        cout<<cnt-1<<endl;//注意减1.
        //3181
    }
    return 0;
}