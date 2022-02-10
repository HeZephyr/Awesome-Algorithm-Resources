/**
  *@filename:D
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-27 21:23
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,cnt[3];
string s;
void solve(){
    for(int i = 0; i < n; ++ i){
        cnt[s[i] - '0'] ++;
    }
    int maxx = 0,idx;
    for(int i = 0; i < 3; ++ i){
        if(cnt[i] > maxx){
            maxx = cnt[i];
            idx = i;
        }
    }
    int avg = n / 3;
    if(idx == 2){
        if(cnt[0] < avg){
            for(int i = 0; i < n && cnt[0] < avg && cnt[2] > avg; ++ i){
                if(s[i] == '2'){
                    s[i] = '0';
                    cnt[0] ++;
                    cnt[2] --;
                }
            }
            //再判断cnt[1]的情况。
            if(cnt[1] >= avg){
                for(int i = 0; i < n && cnt[0] < avg && cnt[1] > avg; ++ i){
                    if(s[i] == '1'){
                        s[i] = '0';
                        cnt[1] --;
                        cnt[0] ++;
                    }
                }
            }
            else{
                for(int i = 0; i < n && cnt[2] > avg && cnt[1] < avg; ++ i){
                    if(s[i] == '2'){
                        s[i] = '1';
                        cnt[1] ++;
                        cnt[2] --;
                    }
                }
            }
        }
        else{
            //说明0和2比1都多。
            for(int i = n - 1; i >= 0 && cnt[0] > avg && cnt[1] < avg; -- i){
                if(s[i] == '0'){
                    s[i] = '1';
                    cnt[1] ++;
                    cnt[0] --;
                }
            }
            for(int i = 0; i < n && cnt[2] > avg && cnt[1] < avg; ++ i){
                if(s[i] == '2'){
                    s[i] = '1';
                    cnt[1] ++;
                    cnt[2] --;
                }
            }
        }
    }
    else if(idx == 1){
        if(cnt[0] < avg){
            for(int i = 0; i < n && cnt[0] < avg && cnt[1] > avg; ++ i){
                if(s[i] == '1'){
                    s[i] = '0';
                    cnt[0] ++;
                    cnt[1] --;
                }
            }
            //再判断cnt[2]的情况。
            if(cnt[2] >= avg){
                for(int i = 0; i < n && cnt[0] < avg && cnt[2] > avg; ++ i){
                    if(s[i] == '2'){
                        s[i] = '0';
                        cnt[2] --;
                        cnt[0] ++;
                    }
                }
            }
            else{
                for(int i = n - 1; i >= 0 && cnt[1] > avg && cnt[2] < avg; -- i){
                    if(s[i] == '1'){
                        s[i] = '2';
                        cnt[2] ++;
                        cnt[1] --;
                    }
                }
            }
        }
        else{
            //说明0和1比2都多。
            for(int i = n - 1; i >= 0 && cnt[0] > avg && cnt[2] < avg; -- i){
                if(s[i] == '0'){
                    s[i] = '2';
                    cnt[2] ++;
                    cnt[0] --;
                }
            }
            for(int i = n - 1; i >= 0 && cnt[1] > avg && cnt[2] < avg; -- i){
                if(s[i] == '1'){
                    s[i] = '2';
                    cnt[2] ++;
                    cnt[1] --;
                }
            }
        }
    }
    else{
        //idx为0的情况。这个时候我们从后面替换1和2
        if(cnt[2] < avg){
            for(int i = n - 1; i >= 0 && cnt[0] > avg && cnt[2] < avg; -- i){
                if(s[i] == '0'){
                    s[i] = '2';
                    cnt[2] ++;
                    cnt[0] --;
                }
            }
            //再判断cnt[1]的情况。
            if(cnt[1] > avg){
                //说明要将1变成2.
                for(int i = n - 1; i >= 0 && cnt[1] > avg && cnt[2] < avg; -- i){
                    if(s[i] == '1'){
                        s[i] = '2';
                        cnt[2] ++;
                        cnt[1] --;
                    }
                }
            }
            else{
                //要将0变成1.
                for(int i = n - 1; i >= 0 && cnt[0] > avg && cnt[1] < avg; -- i){
                    if(s[i] == '0'){
                        s[i] = '1';
                        cnt[1] ++;
                        cnt[0] --;
                    }
                }
            }
        }
        else{
            //0和2都比cnt多。替换2从前面开始，替换0从后面开始。
            for(int i = 0; i < n && cnt[2] > avg && cnt[1] < avg; ++ i){
                if(s[i] == '2'){
                    s[i] = '1';
                    cnt[1] ++;
                    cnt[2] --;
                }
            }
            for(int i = n - 1; i >= 0 && cnt[0] > avg && cnt[1] < avg; -- i){
                if(s[i] == '0'){
                    s[i] = '1';
                    cnt[1] ++;
                    cnt[2] --;
                }
            }
        }
    }
    cout << s << endl;
}
int main(){
    cin >> n >> s;
    solve();
    return 0;
}