/**
  *@filename:034口罩发放
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-22 20:32
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 300000 + 5;
const int mod = 1e9+7;

//做题要细心。
struct Person{
    string name,id,time;
    bool state;//身体状态。 
    int num;//序号。  
    bool operator<(const Person A){
        if(time==A.time)return num<A.num;
        return time<A.time;
    }
}person1[maxn],person2[maxn/10];
map<string,int> person,flag;//标记判断。flag记录什么时候领取的口罩。
int cnt;//统计人数。
int d,p,s,t;
bool check_id(string s){
    if(s.size()!=18)return false;
    for(int i=0;i<s.size();i++){
        if(!isdigit(s[i]))return false;
    }
    return true;
}
void solve(){
}
int main(){
    cin>>d>>p;
    cnt=0;
    for(int i=1;i<=d;i++){
        cin>>t>>s;
        for(int j=0;j<t;j++){
            cin>>person1[j].name>>person1[j].id>>person1[j].state>>person1[j].time;
            person1[j].num=j;
            //判断是否合格。
            if(!check_id(person1[j].id))continue;
            if(person1[j].state==1&&person.find(person1[j].id)==person.end()){
                person[person1[j].id]=1;
                person2[cnt].id=person1[j].id,person2[cnt].name=person1[j].name;
                cnt++;
            }
        }
        sort(person1,person1+t);
        for(int j=0;j<t;j++){
            if(!check_id(person1[j].id))continue;
            if(s>0&&(flag.find(person1[j].id)==flag.end()||flag[person1[j].id]+p+1<=i)){
                flag[person1[j].id]=i;//记录时间。
                s--;
                cout<<person1[j].name<<" "<<person1[j].id<<endl;
            }
        }
    }
    for(int i=0;i<cnt;i++){
            cout<<person2[i].name<<" "<<person2[i].id<<endl;
        }
    solve();
    return 0;
}