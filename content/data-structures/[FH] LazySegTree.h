/**
 * Author: Fuwad Hasan
 * Date: 2024-12-03
 * License: CC0
 * Source: Amar Matha
 * Description: Recursive Lazy Segment Tree. Bounds are inclusive. Can be used for both range update and range set. 
 * Can be used for various operations , just need to change the merge function. Must change the propagation function accordingly.
 * Usage: segment_tree<int> st(arr, [](int a, int b){return a+b;}, 0, 0, -1);
 * Time: O(\log N)
 * Status: stress-tested
 */

template <class T>
struct segment_tree{
	int n;
	vector<T> stree, lzadd, lzset;
	function<T(const T&, const T&)> merge;
	T id = T(); T aid = T(); T sid = T();
	segment_tree(): n(0), merge(nullptr), identity(0), add_identity(0), set_identity(0){}
	segment_tree(int n, function<T(const T&, const T&)> merge, T id, T aid, T sid):
	n(n), merge(merge), id(id), aid(aid), sid(sid){
		stree.resize(4*n+5);lzadd.resize(4*n+5, aid);lzset.resize(4*n+5, sid);
	}
	void build(const vector<T>& arr, int node, int b, int e){
		if(b==e)return void(stree[node] = arr[b]); int mid = (b+e)>>1;
		build(arr, 2*node, b, mid);build(arr, 2*node+1, mid+1, e);
		stree[node] = merge(stree[2*node],stree[2*node+1]);
	}
	segment_tree(const vector<T>& arr, function<T(const T&, const T&)> merge, T id, T aid, T sid):
	n(arr.size()), merge(merge), id(id), aid(aid), sid(sid){
		stree.resize(4*n+5);lzadd.resize(4*n+5, aid);lzset.resize(4*n+5, sid);
		build(arr, 1, 0, n-1);
	}
	void propagate(int node, int b, int e){
		if(lzset[node]!=sid){
			lzadd[node]=aid;
			stree[node] = lzset[node]*(e-b+1);
			if(b!=e){
				lzset[2*node]=lzset[node]; lzset[2*node+1]=lzset[node];
			}
			lzset[node]=sid;
		}
		else{
			if(lzadd[node]==aid) return;
			stree[node]+=lzadd[node]*(e-b+1);
			if(b!=e){
				if(lzset[2*node]==sid){
					lzadd[2*node]+=lzadd[node];
				}
				else{
					lzset[2*node]+=lzadd[node]; lzadd[2*node]=0;
				}
				if(lzset[2*node+1]==sid){
					lzadd[2*node+1]+=lzadd[node];
				}
				else{
					lzset[2*node+1]+=lzadd[node]; lzadd[2*node+1]=0;
				}
			}
			lzadd[node]=aid;
		}
	}
	void update(int node, int b, int e, int l, int r, T val){
		propagate(node, b, e);
		if(l > e or r < b) return;
		if(l<=b and r>=e){
			lzadd[node]+=val; // apply to lazy
			propagate(node, b, e); return;
		}
		int mid = (b+e)>>1;
		update(2*node, b, mid, l, r, val); update(2*node+1, mid+1, e, l, r, val);
		stree[node]=merge(stree[2*node],stree[2*node+1]); return;
	}
	void update(int l, int r, T val){ update(1, 0, n-1, l, r, val); }
	void set(int node, int b, int e, int l, int r, T val){
		propagate(node, b, e);
		if(l > e or r < b) return;
		if(l<=b and r>=e){
			lzset[node]=val; // apply to lazy
			propagate(node, b, e); return;
		}
		int mid = (b+e)>>1;
		set(2*node, b, mid, l, r, val); set(2*node+1, mid+1, e, l, r, val);
		stree[node]=merge(stree[2*node],stree[2*node+1]); return;
	}
	void set(int l, int r, T val){ set(1, 0, n-1, l, r, val); }
	T query(int node, int b, int e, int l, int r){
		propagate(node, b, e);
		if(l > e or r < b) return id;
		if(l<=b and r>=e) return stree[node];
		int mid = (b+e)>>1;
		T c1 = query(2*node, b, mid, l, r); T c2 = query(2*node+1, mid+1, e, l, r);
		return merge(c1,c2);
	}
	T query(int l, int r){return query(1, 0, n-1, l, r);}
};