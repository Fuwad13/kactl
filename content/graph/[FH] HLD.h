/**
 * Author: Fuwad Hasan
 * Date: 2024-12-03
 * License: CC0
 * Source: Amar Matha
 * Description: Heavy Light Decomposition. Bounds are inclusive.must include segment tree.
 * useful for path queries and updates. can be used for subtree queries and updates too.
 * call decompose with the necessary functions and identities.
 * Time: O((\log N)^2)
 * Status: stress-tested against old HLD
 */

template <class T>
struct HLD{
    vector<int> in, out, ssz, depth, parent, head;
    vector<T> val, euler;
    int n, timer;
    vector<vector<int>> adj;
    segment_tree<T> st;
    HLD(int n): n(n), timer(-1), in(n+1), out(n+1), ssz(n+1), depth(n+1), parent(n+1), head(n+1), val(n+1), euler(n+1){
        adj.resize(n+1);
    }
    void add_edge(int u, int v){
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void assign_val(int v, T x){
        val[v] = x;
    }
    void dfs_ssz(int v, int p){
        ssz[v]=1, parent[v]=p;
        int mx = 0;
        for(auto &c: adj[v]){
            if(c!=p){
                depth[c]=1+depth[v];
                dfs_ssz(c, v);
                ssz[v]+=ssz[c];
                if(mx < ssz[c]){
                    mx = ssz[c];
                    swap(adj[v][0], c);
                }
            }
        }
    }
    void dfs_hld(int v, int p){
        in[v]=++timer;
        euler[timer]=val[v];
        head[v] = (p and adj[p][0]==v) ? head[p] : v;
        for(auto c: adj[v]){
            if(c^p){
                dfs_hld(c, v);
            }
        }
        out[v]=timer;
    }
    void decompose(function<T(const T&, const T&)> merge, T identity, T add_identity, T set_identity){
        dfs_ssz(1, 0);
        dfs_hld(1, 0);
        st = segment_tree<T>(euler, merge, identity, add_identity, set_identity);
    }

    int lca(int a, int b){
        for(; head[a]!=head[b]; b = parent[head[b]]){
            if(depth[head[a]] > depth[head[b]]) swap(a, b);
        }
        if(depth[a]>depth[b]) swap(a, b);
        return a;
    }
    T query(int a, int b){
        T ret = st.identity;
        for(; head[a]!=head[b]; b = parent[head[b]]){
            if(depth[head[a]] > depth[head[b]]) swap(a, b);
            ret = st.merge(ret ,st.query(in[head[b]], in[b]));
        }
        if(depth[a]>depth[b]) swap(a, b);
        ret = st.merge(ret, st.query(in[a], in[b]));
        return ret;
    }
    void update(int a, int b, T val){
        for(; head[a]!=head[b]; b = parent[head[b]]){
            if(depth[head[a]] > depth[head[b]]) swap(a, b);
            st.update(in[head[b]], in[b], val);
        }
        if(depth[a]>depth[b]) swap(a, b);
        st.update(in[a], in[b], val);
    }
    void set(int a, int b, T val){
        for(; head[a]!=head[b]; b = parent[head[b]]){
            if(depth[head[a]] > depth[head[b]]) swap(a, b);
            st.set(in[head[b]], in[b], val);
        }
        if(depth[a]>depth[b]) swap(a, b);
        st.set(in[a], in[b], val);
    }
};