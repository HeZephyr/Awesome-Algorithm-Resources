#include<bits/stdc++.h>

using namespace std;
const int N = 1e4+7;
string s1, s2;
int main(){
    int _;
    scanf("%d", &_);
    for(int t = 1;t <= _;t++){
        cin>>s1>>s2;
        int n = s1.size();
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(s1[i]==s2[i]) continue;
            if(s1[i]=='a') cnt++;
            else if(s2[i]=='a') cnt--;
        }
        if(cnt>0) swap(s1, s2);
        else cnt = -cnt;
        cout<<s1<<endl;
        string s = string(n, 'a');
        string ss = string(n, 'a');
        int f = 1, pos = 0;
        char c;
        for(int i = n-1;i >= 0;i--){
            //cout<<s<<endl;
            //printf("1cnt = %d\n", cnt);
            if(!cnt) break;
            if(s1[i]==s2[i]){
            } else {
                if(s1[i]=='a') continue;
                if(s2[i]=='a'){
                    if(cnt>=2){
                        s[i] = s1[i], ss[i] = s1[i];
                        cnt-=2;
                        char tem;
                        for(char j = 'b';j <='z';j++){
                            if(j!=s1[i] && j!=s2[i]){
                                tem = j;
                                break;
                            }
                        }
                        if(f){
                            printf("pos = %d, tem = %c", i, tem);
                            f = 0;pos = i;c = tem;
                        }
                        else if(tem<s1[i]){
                            pos = i;c = tem;
                        }
                    } else {
                        char tem;
                        for(char j = 'b';j <='z';j++){
                            if(j!=s1[i] && j!=s2[i]){
                                tem = j;
                                break;
                            }
                        }
                        s[i] = tem, ss[i] = s1[i];
                        break;
                    }
                } else {
                    s[i] = s1[i], ss[i] = s1[i];
                    cnt--;
                }
            }
        }
        printf("Case %d: ", t);
        if(f) cout<<s<<endl;
        else {
            ss[pos] = c;
            cout<<min(s, ss)<<endl;
        }
    }
    return 0;
}