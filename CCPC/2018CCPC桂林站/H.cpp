#include<bits/stdc++.h>

using namespace std;

int t;
string s1, s2;
int main(){
    cin >> t;
    for(int k = 1; k <= t; ++ k){
        cin >> s1 >> s2;
        int n = s1.size();
        string s = string(n, 'a');
        int cnt = 0;
        char c = 'a';
        for(int i = 0; i < n; ++ i){
            if(s1[i] == s2[i]){
            }
            else if(s1[i] == c){
                //s2[i] != c。
                -- cnt;
            }
            else if(s2[i] == c){
                ++ cnt;
            }
        }
        int pos1 = -1, pos2 = -1;
        for(int i = n - 1; i >= 0; -- i){
            if(cnt == 0)break;
            if(s1[i] == s2[i])continue;
            if(s1[i] != s[i] && s2[i] != s[i]){
                //两边都不相等。都得到了贡献。
                if(cnt > 0){
                    s[i] = s1[i];
                    -- cnt;
                }
                else if(cnt < 0){
                    s[i] = s2[i];
                    ++ cnt;
                }
            }
            else if(s1[i] != s[i]){
                //s2[i] = s[i];
                if(cnt > 1){
                    s[i] = s1[i];
                    cnt -= 2;
                }
                else if(cnt > 0){
                    if(s1[i] == 'b' && s2[i] == 'a' && pos2 != -1){
                        s[i] = 'b';
                        s[pos2] = 'c';
                    }
                    else{
                        for(char c = 'a'; c <= 'z'; ++ c){
                            if(s1[i] != c && s2[i] != c){
                                s[i] = c;
                                break;
                            }
                        }
                    }
                    -- cnt;
                }
                else if(cnt < 0){
                    if(s1[i] == 'b' && s2[i] == 'a'){
                        pos1 = i;
                    }
                }
            }
            else{
                //s1[i] = s[i];
                if(cnt < - 1){
                    s[i] = s2[i];
                    cnt += 2;
                }
                else if(cnt < 0){
                    if(s1[i] == 'a' && s2[i] == 'b' && pos1 != -1){
                        s[i] = 'b';
                        s[pos1] = 'c';
                    }
                    else{
                        for(char c = 'a'; c <= 'z'; ++ c){
                            if(s1[i] != c && s2[i] != c){
                                s[i] = c;
                                break;
                            }
                        }
                    }
                    ++ cnt;
                }
                else if(cnt > 0){
                    if(s1[i] == 'a' && s2[i] == 'b'){
                        pos2 = i;
                    }
                }
            }
        }
        vector<int> a, b;
        vector<char> e, d;
        for(int i = 0; i < n; ++ i){
            if(s1[i] == 'a' && s2[i] == 'b'){
                a.push_back(i);
                e.push_back((char)s[i]);
            }
            else if(s1[i] == 'b' && s2[i] == 'a'){
                b.push_back(i);
                d.push_back((char)s[i]);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(e.begin(), e.end());
        sort(d.begin(), d.end());
        for(int i = 0; i < a.size(); ++ i){
            s[a[i]] = e[i];
        }
        for(int i = 0; i < b.size(); ++ i){
            s[b[i]] = d[i];
        }
        cout << "Case " << k << ": " << s << endl;
    }
    return 0;
}