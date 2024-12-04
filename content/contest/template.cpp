/**
 * Author:
 * Description:
 */
#include <bits/stdc++.h> /** keep-include */
using namespace std;
using ll = long long;
#define all(v) begin(v),end(v)
#define len(v) int(size(v))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template<typename... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
    os << '('; apply([&os](const Args&... args) {
        size_t n = 0;
        ((os << args << (++n != sizeof...(Args) ? ", " : "")), ...);
    }, t);
    return os << ')';
}

template<typename C, typename T = typename enable_if<!is_same<C, string>::value, typename C::value_type>::type>
ostream& operator<<(ostream& os, const C& v) {
    os << '{';
    string sep;
    for (const T& x : v) os << sep << x, sep = ", ";
    return os << "}#" << v.size();
}

void dbg_out() { cerr << endl; }

template<typename First, typename... Rest> void dbg_out(First first, Rest... rest) {
    cerr << ' ' << first;
    dbg_out(rest...);
}

#ifdef LOCAL
#   define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#   define dbg(...)
#   define cerr if (false) cerr
#endif


constexpr ll inf = int(1e9);
constexpr int mod = int(1e9)+7; // 998244353;
constexpr int N = int(2e5);


void run_case() {
}


int32_t main() {
    ios_base::sync_with_stdio(false);

#ifdef LOCAL
    auto tbegin = std::chrono::high_resolution_clock::now();
#else
    cin.tie(nullptr);
#endif

    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        run_case();
    }

#ifdef LOCAL
    auto tend = std::chrono::high_resolution_clock::now();
    cerr << setprecision(4) << fixed;
    cerr << "Time: " << std::chrono::duration_cast<std::chrono::duration<double>>(tend - tbegin).count() << " seconds" << endl;
#endif
}
