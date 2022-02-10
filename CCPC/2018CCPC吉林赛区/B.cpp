#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
int h, m;
char temp[10];
string s, s1, s2;
map<string, int> p;
int main(){
    scanf("%d", &t);
    p["Beijing"] = 8, p["Washington"] = -5, p["London"] = 0, p["Moscow"] = 3;
    for(int k = 1; k <= t; ++ k){
        scanf("%d:%d", &h, &m);
        cin >> s >> s1 >> s2;
        if(s == "PM"){
            //转换成24小时。
            if(h != 12)h += 12;
        }
        else{
            if(h == 12)h = 0;
        }
        //转换成london。
        h = h - p[s1] + p[s2];
        printf("Case %d: ", k);
        if(h >= 0 && h <= 11){
            if(h == 0)h = 12;
            printf("Today %d:%02d AM\n", h, m);
        }
        else if(h >= 12 && h <= 23){
            if(h == 12)h = 24;
            printf("Today %d:%02d PM\n", h - 12, m);
        }
        else if(h >= 24 && h <= 35){
            if(h == 24)h = 36;
            printf("Tomorrow %d:%02d AM\n", h - 24, m);
        }
        else if(h >= 36 && h <= 47){
            if(h == 36)h = 48;
            printf("Tomorrow %d:%02d PM\n", h - 36, m);
        }
        else if(h >= -12 && h <= -1){
            if(h == -12)h = 0;
            printf("Yesterday %d:%02d PM\n", h + 12, m);
        }
        else{
            if(h == -24)h = -12;
            printf("Yesterday %d:%02d AM\n", h + 24, m);
        }
    }
    return 0;
}