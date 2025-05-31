#include <bits/stdc++.h>
using namespace std;

int n, m;
double p;
vector<int> h;

// 状态压缩，将每个怪物的HP拼成一个整数key
long long encode(const vector<int>& h) {
    long long key = 0;
    for (int x : h) {
        key = key * 21 + x; // 假设每个h_i最大不超过20
    }
    return key;
}

// 用 pair<key, t> 作为记忆化 key
unordered_map<long long, unordered_map<int, double>> memo;

double dp(vector<int>& h, int t) {
    long long key = encode(h);
    if (memo[key].count(t)) return memo[key][t];
    if (t == 0) {
        for (int x : h) if (x != 1) return 0.0;
        return 1.0;
    }
    // 剑闪耀
    double res1 = dp(h, t-1);
    bool all_gt1 = true;
    for (int x : h) if (x <= 1) all_gt1 = false;
    if (all_gt1) {
        for (int i = 0; i < n; ++i) h[i]--;
        res1 = max(res1, dp(h, t-1));
        for (int i = 0; i < n; ++i) h[i]++; // 恢复
    }
    // 剑不闪耀
    double res2 = dp(h, t-1);
    for (int i = 0; i < n; ++i) {
        if (h[i] > 1) {
            h[i]--;
            res2 = max(res2, dp(h, t-1));
            h[i]++;
        }
    }
    double ans = p * res1 + (1-p) * res2;
    memo[key][t] = ans;
    return ans;
}

int main() {
    cin >> n >> m >> p;
    h.resize(n);
    for (int i = 0; i < n; ++i) cin >> h[i];
    printf("%.10f\n", dp(h, m));
    return 0;
}