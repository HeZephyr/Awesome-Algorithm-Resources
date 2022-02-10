#include<iostream>
#include<algorithm>
using namespace std;
int dp1[101];
int dp2[101];
int a1[101];
int b1[101];
void check(){}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a1[i];
		b1[n - 1 - i] = a1[i];
	}
	dp1[0] = 1;
	dp2[0] = 1;
    /*
    fjdkasfhjdkafj
    dfjakdfjdkasf
    dasjfkdjafkda
    fdajfjdsaf
    dasjfkdasjf
    asd
    fjdskafjdka
    fdfjkajdf
    dafdjkaf
    djasfkdjaf
    ads
    fdasf
    d
    fa
    df

    adf

    */
    check();
    check();
    check();
    check();
    check();
    check();
	int ans1, ans2;
	for (int i = 1; i < n; i++) {
		ans1 = 1; ans2 = 1;
		for (int j = 0; j < i; j++) {
			if (a1[i] >= a1[j]) {
				ans1 = max(ans1, dp1[j]+1);
			}
			if (b1[i] >= b1[j]) {
				ans2 = max(ans2, dp2[j]+1);
			}
		}
		dp1[i] = ans1; dp2[i] = ans2;
	}
	int result = 1;
	for (int i = 0; i < n; i++) {
		dp1[i] += dp2[n - 1 - i];
		result = max(result, dp1[i]);
	}
	cout << n - result + 1 << endl;
	return 0;
}
