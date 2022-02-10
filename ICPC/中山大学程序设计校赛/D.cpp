#include<bits/stdc++.h>
using namespace std;

int a, b, c, d;
int x[4];
int sgn(int x){
    if(x > 0)return 1;
    else return -1;
}
int main(){
    int t;
    scanf("%d", &t);
    string s[4];
    while(t--){
        for(int i = 0; i < 4; ++ i){
            cin >> s[i];
            if(s[i] == "x"){
                x[i] = 'x';
            }
            else{
                x[i] = stoll(s[i]);
            }
        }
        a = x[0], b = x[1], c = x[2], d = x[3];
        if(a == 'x' || d == 'x'){
            //puts("1");
            // d = 'd'
            if(a == 'x')swap(a, d);
            b = b * c;
            if(a == 0){
                if(b >= 0){
                    puts("E");
                }
                else{
                    puts("R");
                }
            }
            else{
                int gcd = abs(__gcd(b, a));
                if(gcd != 0)a /= gcd, b /= gcd;
                if(abs(a) == 1){
                    if(a > 0)printf("x>%d\n", b);
                    else printf("x<%d\n", b * -1);
                }
                else{
                    if(a > 0)
                        printf("x>%d/%d\n", b, abs(a));
                    else{
                        printf("x<%d/%d\n", b * -1, abs(a));
                    }
                }
            }
        }
        else{
            //puts("2");
            a = a * d;
            if(b == 'x')swap(b, c);
            if(b == 0){
                if(a > 0){
                    puts("R");
                }
                else{
                    puts("E");
                }
            }
            else{
                int gcd = abs(__gcd(b, a));
                if(gcd != 0)a /= gcd, b /= gcd;
                if(abs(b) == 1){
                    if(b > 0)printf("x<%d\n", a);
                    else printf("x>%d\n", a * -1);
                }
                else{
                    if(b > 0)
                        printf("x<%d/%d\n", a, abs(b));
                    else{
                        printf("x>%d/%d\n", a * -1, abs(b));
                    }
                }
            }
        }
    }
    return 0;
}