/**
  *@filename:三体攻击
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-07 16:43
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//暴力枚举时间复杂度高达O(abcm)，为10^12，肯定会超时，大概只能过30%的数据，水一些分。
int a,b,c,m;//m轮攻击。
int main(){
    while(cin>>a>>b>>c>>m){
        vector<vector<vector<int> > > planes(a+1,vector<vector<int> >(b+1,vector<int>(c+1)));
        vector<vector<int> > hitInfo(m,vector<int>(7));
        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                for(int k=1;k<=c;k++){
                    cin>>planes[i][j][k];
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<7;j++){
                cin>>hitInfo[i][j];
            }
        }
        //开始暴力枚举攻击。
        int lat,rat,lbt,rbt,lct,rct,ht;
        for(int t=0;t<m;t++){
            lat=hitInfo[t][0],rat=hitInfo[t][1],lbt=hitInfo[t][2],rbt=hitInfo[t][3],
            lct=hitInfo[t][4],rct=hitInfo[t][5],ht=hitInfo[t][6];
            for(int i=lat;i<=rat;i++){
                for(int j=lbt;j<=rbt;j++){
                    for(int k=lct;k<=lct;k++){
                        planes[i][j][k]-=ht;
                        if(planes[i][j][k]<0){
                            cout<<t+1<<endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return 0;
}