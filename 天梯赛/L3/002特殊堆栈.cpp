/**
  *@filename:002特殊堆栈
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-23 17:01
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n;//指令数。
vector<int> v1,v2;
char s[15];
//lower_bound二分查找第一个大于等于x的位置。
void solve(){
}
int main(){
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        if(s[1]=='u'){
            int x;
            scanf("%d",&x);
            v1.push_back(x);
            auto iter=lower_bound(v2.begin(),v2.end(),x);//找到需要插入的位置。
            v2.insert(iter,x);
        }
        else if(s[1]=='o'){
            if(v1.size()==0){
                puts("Invalid");
            }
            else{
                auto iter=lower_bound(v2.begin(),v2.end(),v1[v1.size()-1]);//找到需要删除的位置。
                v2.erase(iter);
                printf("%d\n",v1.back());
                v1.pop_back();
            }
        }
        else{
            //查找中值。
            if(v1.size()==0){
                puts("Invalid");
            }
            else{
                //获取位置。
                if(v1.size()%2){
                    //由于下标从0开始，故需要作此处理。
                    printf("%d\n",v2[v1.size()/2]);
                }
                else{
                    printf("%d\n",v2[v1.size()/2-1]);
                }
            }
        }
    }
    solve();
    return 0;
}