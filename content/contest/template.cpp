#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(v) (v).begin(), (v).end()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll oo = 1e17;
const int mod = 1e9+7; // 998244353;
const int N = 2e5;
// kactl macros
// #define rep(i, a, b) for(int i = a; i < (b); ++i)
// #define all(x) begin(x), end(x)
// #define sz(x) (int)(x).size()
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef vector<int> vi;
void solve(){
    
}
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int i = 1; i <=t; i++){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
    return 0;
}
