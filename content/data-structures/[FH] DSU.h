/**
 * Author: Fuwad Hasan
 * Date: 2024-12-03
 * License: CC0
 * Source: USACO Guide
 * Description: Disjoint-set-union data structure.
 * Time: $O(\alpha(N))$
 */
struct DSU {
	vector<int> rep; // store negation of size of representative
	int cc;
	DSU(int sz) { rep = vector<int>(sz, -1); cc = sz -1; } // get representive component (uses path compression)
	int get(int x) { return rep[x] < 0 ? x : rep[x] = get(rep[x]); }
	bool same_set(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -rep[get(x)]; }
	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		cc--;
		if (rep[x] > rep[y]) swap(x, y); // rep[x] less means bigger size
		rep[x] += rep[y];
		rep[y] = x;
		return true;
	}
};