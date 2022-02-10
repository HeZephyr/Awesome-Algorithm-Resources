#include<bits/stdc++.h>

using namespace std;

int t,a1,b1,a2,b2;
int main(){
    cin >> t;
    while(t -- ){
        cin >> a1 >> b1 >> a2 >> b2;
        if(a1 > b1)swap(a1,b1);
        if(a2 > b2)swap(a2,b2);
        if((a1 == 2 && b1 == 8) || (a2 == 2 && b2 == 8)){
            if((a1 == 2 && b1 == 8) && (a2 == 2 && b2 == 8)){
                cout << "tie" << endl;
            }
            else if(a1 == 2 && b1 == 8){
                cout << "first" << endl;
            }
            else{
                cout << "second" << endl;
            }
        }
        else if(a1 == b1 || a2 == b2){
            if(a1 == b1 && a2 == b2){
                if(a1 > a2){
                    cout << "first" << endl;
                }
                else if(a1 == a2){
                    cout << "tie" << endl;
                }
                else{
                    cout << "second" << endl;
                }
            }
            else if(a1 == b1){
                cout << "first" << endl;
            }
            else{
                cout << "second" << endl;
            }
        }
        else{
            int temp1 = (a1 + b1) % 10,temp2 = (a2 + b2) % 10;
            if(temp1 > temp2){
                cout << "first" << endl;
            }
            else if(temp1 < temp2){
                cout << "second" << endl;
            }
            else{
                if(b1 > b2){
                    cout << "first" << endl;
                }
                else if(b1 == b2){
                    cout << "tie" << endl;
                }
                else{
                    cout << "second" << endl;
                }
            }
        }
    }
    return 0;
}