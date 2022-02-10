/**
  *@filename:Master_of_shuangpin
  *@author: pursuit
  *@created: 2021-09-05 14:40
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

string s;
unordered_map<string, string> mp;
void init(){
    //预处理出表格中的内容。
    mp["iu"]="q";  mp["ei"]="w";  mp["uan"]="r";  mp["ue"]="t";
    mp["un"]="y";  mp["sh"]="u";  mp["ch"]="i";   mp["uo"]="o";
    mp["ie"]="p";  mp["ong"]="s"; mp["iong"]="s"; mp["ai"]="d";
    mp["en"]="f";  mp["eng"]="g"; mp["ang"]="h";  mp["an"]="j";
    mp["uai"]="k"; mp["ing"]="k"; mp["uang"]="l"; mp["iang"]="l";
    mp["ou"]="z";  mp["ia"]="x";  mp["ua"]="x";   mp["ao"]="c";
    mp["zh"]="v";  mp["ui"]="v";  mp["in"]="b";   mp["iao"]="n";
    mp["ian"]="m";
}
void solve(){
    //分解字符串。
    stringstream ss(s);
    string res = "", str;
    while(ss >> str){
        int len = str.size();
        //为一个字母复制本身输出。为两个直接输出本身。
        if(len == 1)res += (str + str);
        else if(len == 2)res += str;
        else{
            if(str[0] == 'c' || str[0] == 'z' || str[0] == 's'){
                //判断为ch，zh，sh这种类型。
                if(str[1] == 'h'){
                    res += mp[str.substr(0, 2)];
                    if(len == 3)res += str[2];
                    else res += mp[str.substr(2)];
                }
                else{
                    //若不为h。 根据表格可知一定是单个组合的。
                    res += (str[0] + mp[str.substr(1)]);
                }
            }
            else{
                //根据字母标，按下第一个键，再找映射。
                res += str[0];
                string temp = str.substr(1,len - 1);
                if(!mp.count(temp)){
                    res += mp[str];
                }
                else{
                    res += mp[temp];
                }
            }
        }
        res += " ";
    }
    cout << res << endl;
}
int main(){	
    init();
    while(getline(cin, s)){
        solve();
    }
    return 0;
}