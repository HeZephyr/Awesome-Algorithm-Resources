#include <bits/stdc++.h>

using namespace std;

int h, e, t;

int main(){	
    scanf("%d%d%d", &t, &h, &e);
    int temp = floor(0.2 * t + 0.3 * h + 0.5 * e);
    printf("%d\n", temp);
    return 0;
}