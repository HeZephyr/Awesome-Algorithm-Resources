#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n;
    string s1, s2, s3;
    for (int Case = 1; Case <= t; ++Case) {
        cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; ++ i) {
            cin >> s1 >> s2;
            int idx1 = -1, idx2 = -1;
            int k;
            if (s1 == "bool" || s1 == "char") {
                k = 1;
            } else if (s1 == "int" || s1 == "float") {
                k = 4;
            } else if (s1 == "double") {
                k = 8;
            } else if (s1 == "long") {
                cin >> s3;
                if (s2 == "long") {
                    k = 8;
                } else if (s2 == "double") {
                    k = 16;
                }
            } else if (s1 == "__int128") {
                k = 16;
            }
            if (s1 == "long") {
                s2 = s3;
            }
            //判断s2是什么。
            for (int i = 0; i < s2.size(); ++ i) {
                if (s2[i] == '[') {
                    idx1 = i;
                } else if (s2[i] == ']') {
                    idx2 = i;
                }
            }
            if (idx1 == -1) {
                ans += k;
            } else {
                string temp = s2.substr(idx1 + 1, idx2 - idx1 - 1);
                // cout << temp << endl;
                // cout << temp << endl;
                // cout << atoi(temp.c_str()) << endl;
                ans += k * atoi(temp.c_str());
            }
        }
        cout << "Case #" << Case << ": " << ans / 1024 + (ans % 1024 != 0) << endl;
    }

    return 0;
}