#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//10:25
int n, k;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> k;
    vector<int>v;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 1; i < n; i++) {
        v[i - 1] = v[i] - v[i - 1];
    }
    v[n - 1] = 0;
    //내림차순

    sort(v.begin(), v.end());
    int ans = 0;

    //2 3 0 1 2
    // 0 1 2 2 3 - 3을 뺌
    for (int i = 0; i < n - k+1; i++)
        ans += v[i];

    cout << ans;
    return 0;
}