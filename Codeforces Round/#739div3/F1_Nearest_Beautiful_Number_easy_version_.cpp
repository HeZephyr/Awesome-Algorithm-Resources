/**
  *@filename:F1_Nearest_Beautiful_Number_easy_version_
  *@author: pursuit
  *@created: 2021-08-19 00:58
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,k;
string s1;
void solve(){
    //先构造1beautiful的。
    string s2(s1.size(),s1[0]);
    if(s2 < s1){
        s2 = string(s1.size(),s1[0] + 1);
    }
    //判断是否为2beautiful。
    if(k == 2){
        //枚举两个数构造。
        for(char a = '0'; a <= '9'; ++ a){
            for(char b = '0'; b <= '9'; ++ b){
                bool flag = true;//判断是否构造成功。
                for(int i = 0; i < s1.size(); ++ i){
                    if(s1[i] < b){
                        //小于最大值了。此时可以构造。
                        string temp = s1;
                        //构造一位大于的，其余全填最小的a。
                        if(temp[i] < a)temp[i] = a;
                        else temp[i] = b;
                        for(int j = i + 1; j < s1.size(); ++ j){
                            temp[j] = a;
                        }
                        //更新最小值。
                        if(temp < s2){
                            s2 = temp;
                        }
                    }
                    if(s1[i] != a && s1[i] != b){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    //这个说明s1就全由a,b这个组成的
                    cout << s1 << endl;
                    return;
                }
            }
            
        }
    }
    cout << s2 << endl; 
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s1 >> k;
        solve();
    }
    return 0;
}