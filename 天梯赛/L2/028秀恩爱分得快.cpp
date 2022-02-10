/**
  *@filename:028秀恩爱分得快
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-21 21:16
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1000 + 5;
const int mod = 1e9+7;

int n,m,k,sex[maxn],love[3];//n为总人数，m为照片总数，k为照片中出现的人数，sex确定性别，love存储
vector<vector<int> > pic;//存储图片。
vector<int> ans[3];//存储最亲密异性id。
double sum[maxn],maxx[3];//存储异性亲密度。maxn维护男主女主的最亲密值。
int a[maxn];
bool cmp(int a,int b){
    if(abs(a)==1000)return true;
    if(abs(b)==1000)return false;
    return abs(a)<abs(b);
}
void solve(){
    for(int t=1;t<=2;t++){
        for(int i=0;i<m;i++){
            bool flag=false;//判断主角是否在照片里。
            for(int j=0;j<pic[i].size();j++){
                if(pic[i][j]==love[t]){
                    flag=true;
                    break;
                }
            }
            if(flag){
                for(int j=0;j<pic[i].size();j++){
                    if(pic[i][j]*love[t]<0){
                        //说明是异性。统计异性对其的亲密度。
                        sum[abs(pic[i][j])]+=1.0/pic[i].size();
                    }
                }
            }
        }
    }
    maxx[1]=maxx[2]=-1;
    //cout<<maxx[1]<<maxx[2]<<endl;
    for(int t=1;t<=2;t++){
        for(int i=1;i<=1000;i++){
            if(love[t]*sex[i]<0){
                if(sum[i]>maxx[t]){
                    maxx[t]=sum[i];
                    ans[t].clear();
                    ans[t].push_back(sex[i]);
                }
                else if(sum[i]==maxx[t]){
                    ans[t].push_back(sex[i]);
                }
            }
        }
    }
    //判断是否相等。
    if(maxx[1]==sum[love[2]]&&maxx[2]==sum[love[1]]){
        string s1=to_string(love[1]),s2=to_string(love[2]);
        if(s1=="1000")s1="0";
        if(s1=="-1000")s1="-0";
        if(s2=="1000")s2="0";
        if(s2=="-1000")s2="-0";
        cout<<s1<<" "<<s2<<endl;
        return;
    }
    for(int t=1;t<=2;t++){
        sort(ans[t].begin(),ans[t].end(),cmp);
        for(int i=0;i<ans[t].size();i++){
            string s1=to_string(love[t]),s2=to_string(ans[t][i]);
            if(s1=="1000")s1="0";
            if(s1=="-1000")s1="-0";
            if(s2=="1000")s2="0";
            if(s2=="-1000")s2="-0";
            cout<<s1<<" "<<s2<<endl;
        }
    }
}
int main(){
    cin>>n>>m;
    pic.resize(m);
    int u;
    string op;
    for(int i=0;i<m;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>op;
            if(op=="0")op="1000";
            if(op=="-0")op="-1000";
            int temp=stoi(op);
            sex[abs(temp)]=temp;
            pic[i].push_back(temp);    
        }
    }
    for(int i=1;i<=2;i++){
        cin>>op;
        if(op=="0")op="1000";
        if(op=="-0")op="-1000";
        int temp=stoi(op);
        love[i]=temp;
    }
    //cout<<love[1]<<" "<<love[2]<<endl;
    solve();
    return 0;
}