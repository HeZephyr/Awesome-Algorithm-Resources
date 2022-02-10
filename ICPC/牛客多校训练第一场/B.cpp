#include<bits/stdc++.h>

using namespace std;

double r,a,b,h;
int main(){
    cin >> r >> a >> b >> h;
    if(2 * r < b){
        cout << "Drop" << endl;
    }
    else{
        cout << "Stuck" << endl;
        double y = b * h / (a - b);
        double temp = 2 * r * y / b;
        temp *= temp;
        temp -= r * r;
        printf("%.10f\n",sqrt(temp));
    }
    return 0;
}