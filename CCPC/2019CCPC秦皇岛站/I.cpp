#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int t, n;
char s[N];
string res;
map<char, vector<string>> p;
vector<int> a[N];
void init(){
    p['Y'].push_back("QQQ");
    p['V'].push_back("QQW"), p['V'].push_back("QWQ"), p['V'].push_back("WQQ"); 
    p['G'].push_back("QQE"), p['G'].push_back("QEQ"), p['G'].push_back("EQQ");
    p['C'].push_back("WWW");
    p['X'].push_back("QWW"), p['X'].push_back("WQW"), p['X'].push_back("WWQ");
    p['Z'].push_back("WWE"), p['Z'].push_back("WEW"), p['Z'].push_back("EWW");
    p['T'].push_back("EEE");
    p['F'].push_back("QEE"), p['F'].push_back("EQE"), p['F'].push_back("EEQ");
    p['D'].push_back("WEE"), p['D'].push_back("EWE"), p['D'].push_back("EEW");
    p['B'].push_back("QWE"), p['B'].push_back("QEW");
    p['B'].push_back("WEQ"), p['B'].push_back("WQE");
    p['B'].push_back("EQW"), p['B'].push_back("EWQ");
}
int main(){
    init();
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for(int i = 0; i < p[s[1]].size(); ++ i){
        a[1].push_back(4);
    }
    for(int i = 2; i <= n; ++ i){
        //从i - 1到i。
        for(int j = 0; j < p[s[i]].size(); ++ j){
            int minn = 1e9;
            for(int k = 0; k < p[s[i - 1]].size(); ++ k){
                int cnt = a[i - 1][k], cnt1 = 0;
                string cur = p[s[i - 1]][k];
                string op = p[s[i]][j];
                for(int len = 3; len >= 1; -- len){
                    if(cur.substr(3 - len, len) == op.substr(0, len)){
                        cnt1 = len;
                        break;
                    }
                }
                cnt = cnt + 4 - cnt1;
                minn = min(cnt, minn);
            }
            a[i].push_back(minn);
        }
    }
    int minn = 1e9;
    for(int j = 0; j < a[n].size(); ++ j){
        minn = min(minn, a[n][j]);
    }
    printf("%d\n", minn);
    return 0;
}