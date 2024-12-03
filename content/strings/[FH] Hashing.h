/**
 * Author: Fuwad Hasan
 * Date: 2024-12-03
 * License: CC0
 * Source: Usaco guide
 * Description: Self-explanatory methods for string hashing.
 * Status: stress-tested
 */
class HashedString {
  private:
    // use randomized base for safeguarding anti hash tests
    static const ll M = 1e9 + 9;
    static const ll B = 9973;
    static vector<ll> pow; // pow[i] contains B^i % M
    // p_hash[i] is the hash of the first i characters of the given string
    vector<ll> p_hash;
  public:
    HashedString(const string &s) : p_hash(s.size() + 1) {
        while (pow.size() < s.size()) { pow.push_back((pow.back() * B) % M); }
        p_hash[0] = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            p_hash[i + 1] = ((p_hash[i] * B) % M + s[i]) % M;
        }
    }
    ll getHash(int start, int end) {
        ll raw_val =
            (p_hash[end + 1] - (p_hash[start] * pow[end - start + 1]));
        return (raw_val % M + M) % M;
    }
};
vector<ll> HashedString::pow = {1};
// for randomised base (anti hack)
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);