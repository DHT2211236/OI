#include<bits/stdc++.h>
using namespace std;
void solve(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    if(min(a,c)<min(b,d))  puts("Flower");
    else  puts("Gellyfish");
}
signed main(){
    long long T;scanf("%lld",&T);
    while(T--) solve();

    return 0;
}