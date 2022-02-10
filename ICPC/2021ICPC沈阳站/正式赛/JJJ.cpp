#include<bits/stdc++.h>
using namespace std;

string s1, s2;
struct node{
    string s;
    int step;
};
map<string, int> p;
int go[10][4] = {
    {0, 0, 0, 1},
    {0, 0, 1, 0},
    {0, 1, 0, 0},
    {1, 0, 0, 0},
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 1, 1, 0},
    {0, 1, 1, 1},
    {1, 1, 1, 1}
};
void bfs(){
    queue<node> q;
    node head, temp;
    q.push({"0000", 0});
    p["0000"] = 0;
    while(!q.empty()){
        head = q.front();
        q.pop();
        int op;
        temp.step = head.step + 1;
        for(int i = 0; i < 2; ++ i){
            if(i == 0)op = - 1;
            else op = 1;
            for(int j = 0; j < 10; ++ j){
                string s = head.s;
                for(int k = 0; k < 4; ++ k){
                    s[k] += go[j][k] * op;
                    if(s[k] < '0')s[k] = '9';
                    if(s[k] > '9')s[k] = '0';
                }
                if(p.count(s) == 0){
                    p[s] = temp.step;
                    temp.s = s;
                    q.push(temp);
                }
            }
        }
    }
}
int main(){
    //freopen("J.txt", "r", stdin);
    //freopen("JJJ.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    bfs();
    while(T--){
        cin >> s1 >> s2;
        string res = "";
        for(int i = 0; i < 4; ++ i){
            int temp = s2[i] - s1[i];
            if(temp < 0)temp += 10;
            res += char(temp + '0');
        }
        cout << p[res] << endl;
    }
    return 0;
}