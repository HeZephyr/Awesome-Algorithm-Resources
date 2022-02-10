#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
string s;
//一般地，如果以masu结尾，则说这是masu形式的verbs。
//一般地，如果以te结尾，则说这是te形式的verbs。
//如果是masu形式且以imasu或chimasu或rimasu结尾，则将这些删除并添加tte。
//如果是masu形式且以mimasu或bimasu或nimasu结尾，则将这些删除并添加nde。
//如果是masu形式且以kimasu结尾，则将这些删除并添加ite。
//如果是masu形式且以gimasu结尾，将这些删除并添加ide。
//如果是masu形式且以shimasu结尾，将这些删除并添加shite。
void solve(){
    if(s == "ikimasu"){
        cout << "itte" << endl;
        return;
    }
    int pos = s.find("shimasu");
    if(pos != -1){
        cout << s.substr(0, s.size() - 7) + "shite" << endl;
        return;
    }
    pos = s.find("gimasu");
    if(pos != -1){
        cout << s.substr(0, s.size() - 6) + "ide" << endl;
        return;
    }
    pos = s.find("kimasu");
    if(pos != -1){
        cout << s.substr(0, s.size() - 6) + "ite" << endl;
        return;
    }
    if(s.find("mimasu") != -1 || s.find("bimasu") != -1 || s.find("nimasu") != -1){
        cout << s.substr(0, s.size() - 6) + "nde" << endl;
        return;
    }
    if(s.find("chimasu") != -1){
        cout << s.substr(0, s.size() - 7) + "tte" << endl;
        return;
    }
    if(s.find("rimasu") != -1){
        cout << s.substr(0, s.size() - 6) + "tte" << endl;
        return;
    }
    if(s.find("imasu") != -1){
        cout << s.substr(0, s.size() - 5) + "tte" << endl;
        return;
    }
    cout << s << endl;
}
int main(){
    int t;
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}