#include<bits/stdc++.h>

using namespace std;

string s1,s2;
vector<pair<int,int> > cal(string s){
    vector<pair<int,int> > v;
    pair<int,int> temp;
    for(int i = 0; i <= s.size(); ++ i){
        if(s[i] == 'c' || i == s.size()){
            temp.first = temp.first & 1;
            temp.second = temp.second & 1;
            v.push_back(temp);
            temp.first = 0,temp.second = 0;
        }
        else{
            if(s[i] == 'a')temp.first ++;
            if(s[i] == 'b')temp.second ++;
        }
    }
    return v;
}
void solve(){
}
int main(){
    while(cin >> s1 >> s2){
        if(cal(s1) == cal(s2)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}