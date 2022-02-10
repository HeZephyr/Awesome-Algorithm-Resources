#include<bits/stdc++.h>
using namespace std;
int a[5], b[5], c[5], l, r;
int calc(int i, int op){
    if(op == 1){
        return (10 + b[i] - a[i]) % 10;
    }
    else{
        return -((10 + a[i] - b[i]) % 10);
    }
}
int sol(){
    int res = 0;
    while(1){
        int pos = -1, val = 20, tem = 20;
        for(int i = 0;i < 4;i++){
            if(c[i]==0) continue;
            if(abs(c[i])<val){
                val = abs(c[i]);
                tem = c[i];
                pos = i;
            }
        }
        for(l = pos;l-1 >= 0;l--){
            if(c[l-1]*c[pos]<=0) break;
        }
        for(r = pos;r+1 < 4;r++){
            if(c[r+1]*c[pos]<=0) break;
        }
        for(int i = l;i <= r;i++){
            if(tem>0) c[i]-=val;
            else c[i] += val;
        }
        res += val;
        int cnt = 0;
        //printf("pos = %d,  l = %d, r = %d, val = %d\n", pos, l, r, val);
        for(int i = 0;i < 4;i++){
            //printf("%d ", c[i]);
            if(!c[i]) cnt++;
        }
        //printf("\n");
        if(cnt==4){
            //printf("--------res = %d\n", res);
            return res;
        }
    }
}
int main(){
    //freopen("J.txt", "r", stdin);
    //freopen("JJ.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--){
        int x, y;
        scanf("%d %d", &x, &y);
        for(int i = 0; i <= 3; ++i){
            a[i] = x % 10;
            b[i] = y % 10;
            x/=10; y/=10;
        }
        int ans = 200;
        vector<int> v[5];
        for(int i = 0;i < 4;i++){
            if(a[i]==b[i]){
                v[i].push_back(0),v[i].push_back(10),v[i].push_back(-10);
            } else {
                v[i].push_back((10 + b[i] - a[i]) % 10);
                v[i].push_back(-((10 + a[i] - b[i]) % 10));
            }
        }
        for(auto i1:v[0]){
            for(auto i2:v[1]){
                for(auto i3:v[2]){
                    for(auto i4:v[3]){
                        c[0]=i1,c[1]=i2,c[2]=i3,c[3]=i4;
                        int fff = 0;
                        //printf("!!!!!!!!!! ");
                        for(int j = 0; j <= 3; ++j){
                        //    printf("%d ", c[j]);
                            if(!c[j]) fff++;
                        }
                        //printf("\n");
                        if(fff==4){
                            ans = 0;
                            break;
                        }
                        ans = min(ans, sol());
                    }
                }
            }
        }
        printf("%d\n", ans); 
    }
    return 0;
}