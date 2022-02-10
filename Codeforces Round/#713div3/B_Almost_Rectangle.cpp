/**
  *@filename:B_Almost_Rectangle
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-10 22:43
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 4000 + 5;
const int mod = 1e9+7;

int t,n;
char s[maxn][maxn];
int X1,Y1,X2,Y2;
void solve(){
    if(X2==-1){
        X2=X1,Y2=Y1;
    }
    if(X1==X2&&Y1==Y2){
        if(X1!=0&&Y1!=0){
            s[X1-1][Y1-1]=s[X1-1][Y1]=s[X1][Y1-1]='*';
        }
        else if(X1==0&&Y1==0){
            s[X1+1][Y1+1]=s[X1+1][Y1]=s[X1][Y1+1]='*';
        }
        else if(X1==0&&Y1!=0){
            s[X1+1][Y1-1]=s[X1][Y1-1]=s[X1+1][Y1]='*';
        }
        else{
            s[X1-1][Y1+1]=s[X1-1][Y1]=s[X1][Y1+1]='*';
        }
    }
    else if(X1==X2){
        //说明在同一行，那么我们可以得到边长
        int len=abs(Y2-Y1);
        if(X1+len>=n){
            s[X1-len][Y1]=s[X2-len][Y2]='*';
        }
        else{
            s[X1+len][Y1]=s[X2+len][Y2]='*';
        }
    }
    else if(Y1==Y2){
        int len=abs(X2-X1);
        if(Y1+len>=n){
            s[X1][Y1-len]=s[X2][Y2-len]='*';
        }
        else{
            s[X1][Y1+len]=s[X2][Y2+len]='*';
        }
    }
    else{
        s[X2][Y1]=s[X1][Y2]='*';
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<s[i][j];
        }
        cout<<endl;
    }
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n;
            X1=-1,X2=-1;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cin>>s[i][j];
                    if(s[i][j]=='*'&&X1==-1){
                        X1=i,Y1=j;
                    }
                    else if(s[i][j]=='*'&&X2==-1){
                        X2=i,Y2=j;
                    }
                }
            }
            solve();
        }
    }
    return 0;
}
