/**
 * Author: Fuwad Hasan
 * Date: 2024-12-03
 * License: CC0
 * Source: USACO Guide
 * Description: Disjoint-set-union data structure with rollback feature.
 * Time: $O(\alpha(N))$
 */
struct DSU {
	vector<int> p, sz;
	vector<pair<int, int>> p_history, sz_history;
	DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
	int get(int x) { return x == p[x] ? x : get(p[x]); }
	bool sameset(int a, int b) { return get(a) == get(b); }
	void unite(int a, int b) {
		a = get(a);
		b = get(b);
		if (a == b) { return; }
		if (sz[a] < sz[b]) { swap(a, b); }
		p_history.push_back({b, p[b]});
		sz_history.push_back({a, sz[a]});
		p[b] = a;
		sz[a] += sz[b];
	}
	void rollback() {
		p[p_history.back().first] = p_history.back().second;
		sz[sz_history.back().first] = sz_history.back().second;
		p_history.pop_back();
		sz_history.pop_back();
	}
};