/**
  *@filename:030冰岛人
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-22 16:56
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//先输入名再输入姓
struct Person{
    char sex;//类型。
    string father;//存储父亲。
};
map<string,Person> people;//存储人。
int n,m;
string a,b,str;
bool judge(){
    int i=1,j;
    for(string A=a;!A.empty();A=people[A].father,i++){
        j=1;
        for(string B=b;!B.empty();B=people[B].father,j++){
            if(i>=5&&j>=5){
                //说明都超过了五代，那么是可以的。
                return true;
            }
            if(A==B&&(i<5||j<5))return false;
        }
    }
    return true;//没有共同祖先。
}
void solve(){
    if(people.find(a)==people.end()||people.find(b)==people.end())puts("NA");
    else{
        if(people[a].sex==people[b].sex)puts("Whatever");
        else{
            if(judge())puts("Yes");
            else puts("No");
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;//名 姓 带性别后缀。
        if(b.back()=='n'){
            //说明是儿子。
            people[a]={'m',b.substr(0,b.size()-4)};
        }
        else if(b.back()=='r'){
            //说明是女儿。
            people[a]={'f',b.substr(0,b.size()-7)};
        }
        else{
            //说明是其他人，我们只需要记录性别即可。
            people[a].sex=b.back();
        }
    }
    cin>>m;
    while(m--){
        cin>>a>>str>>b>>str;//姓氏没有用。
        solve();
    }
    return 0;
}