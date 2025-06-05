#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    // 计算全局gcd
    int g = a[0];
    for (int i = 1; i < n; ++i) g = __gcd(g, a[i]);

    // 统计已经等于g的元素个数
    int cnt = 0;
    for (int x : a) if (x == g) cnt++;

    // 最少操作数
    cout << n - cnt << endl;
}
signed main(){
    long long T;scanf("%lld",&T);
    while(T--) solve();

    return 0;
}