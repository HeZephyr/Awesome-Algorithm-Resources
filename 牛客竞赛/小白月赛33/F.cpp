/**
  *@filename:F
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-17 20:20
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int t,n;
string op;
int temp;
int goInfo[266];//w a d s
int go[4][2]={{1,0},{0,-1},{0,1},{-1,0}};
int x,y;
void solve(){
    x=0,y=0;
    for(int i=0;i<n;i++){
        cin>>op>>temp;
        if(op=="r"){
            temp%=4;
            while(temp--){
                //每次顺时针旋转，就是面朝方向变了。
                swap(goInfo['a'],goInfo['w']);
                swap(goInfo['w'],goInfo['s']);
                swap(goInfo['w'],goInfo['d']);
            }
            cout<<go[goInfo['a']][0]<<" "<<go[goInfo['a']][1]<<endl;
            cout<<go[goInfo['w']][0]<<" "<<go[goInfo['w']][1]<<endl;
            cout<<go[goInfo['s']][0]<<" "<<go[goInfo['s']][1]<<endl;
            cout<<go[goInfo['d']][0]<<" "<<go[goInfo['d']][1]<<endl;
        }
        else if(op=="l"){
            temp%=4;
            while(temp--){
                swap(goInfo['w'],goInfo['d']);
                swap(goInfo['w'],goInfo['s']);
                swap(goInfo['w'],goInfo['a']);
            }
            cout<<go[goInfo['a']][0]<<" "<<go[goInfo['a']][1]<<endl;
            cout<<go[goInfo['w']][0]<<" "<<go[goInfo['w']][1]<<endl;
            cout<<go[goInfo['s']][0]<<" "<<go[goInfo['s']][1]<<endl;
            cout<<go[goInfo['d']][0]<<" "<<go[goInfo['d']][1]<<endl;
        }
        else if(op=="w"){
            x+=go[goInfo['w']][0]*temp,y+=go[goInfo['w']][1]*temp;
        }
        else if(op=="a"){
            x+=go[goInfo['a']][0]*temp,y+=go[goInfo['a']][1]*temp;
        }
        else if(op=="d"){
            x+=go[goInfo['d']][0]*temp,y+=go[goInfo['d']][1]*temp;
        }
        else{
            x+=go[goInfo['s']][0]*temp,y+=go[goInfo['s']][1]*temp;
        }
    }
    cout<<x<<" "<<y<<endl;
}
int main(){
    while(cin>>t){
        while(t--){
            cin>>n;
            goInfo['w']=0,goInfo['a']=1,goInfo['d']=2,goInfo['s']=3;
            solve();
        }
    }
    return 0;
}