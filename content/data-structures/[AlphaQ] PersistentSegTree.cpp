/**
 * Author: AlphaQ
 * Description:
 */
const int N = 200010;
const int M = 10000010;
int n, q, nodes, root[N], a[N], t[M], L[M], R[M];
void update(int p, int v, int prev_node, int cur_node, int b = 1, int e = n) {
	if (b == e) return void(t[cur_node] = v);
	int mid = b + e >> 1;
	if (p <= mid) R[cur_node] = R[prev_node], L[cur_node] = ++nodes, update(p, v, L[prev_node], L[cur_node], b, mid);
	else L[cur_node] = L[prev_node], R[cur_node] = ++nodes, update(p, v, R[prev_node], R[cur_node], mid + 1, e);
	t[cur_node] = t[L[cur_node]] + t[R[cur_node]];
}
int query(int l, int r, int u, int b = 1, int e = n) {
	if (b > r or e < l) return 0;
	if (b >= l and e <= r) return t[u];
	int mid = b + e >> 1;
	return query(l, r, L[u], b, mid) + query(l, r, R[u], mid + 1, e);
}
int main() {
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) scanf("%d", a + i);
	map<int, int> last;
	for (int i = 1; i <= n; ++i) {
		/// 1....i-1.i
		int x = a[i], pos = last[x], prev_root = root[i - 1];
		if (pos) {
			root[i] = ++nodes;
			update(pos, 0, prev_root, root[i]);
			prev_root = root[i];
		}
		root[i] = ++nodes;
		update(i, 1, prev_root, root[i]);
		last[x] = i;
	}
	while (q--) {
		int l, r;
		scanf("%d %d", &l, &r);
		/// segmentTree[r].sum(l, r)
		printf("%d\n", query(l, r, root[r]));
	}
}