/**
 * Author: Fuwad Hasan
 * Date: 2024-12-03
 * License: CC0
 * Source: USACO.guide
 * Description: Example of Centroid Decomposition of a tree. This one computes the number of paths with length k.
 * call decompose(1, 0) to start the decomposition.
 * Time: $O(N \log N )$
 * Status: stress-tested
 */
vector<int> adj[N+1];
int cnt[N], ssz[N+1];
bitset<N+1> bad; int mx; ll ans = 0;
void dfs_ssz(int v, int p){
    ssz[v]=1;
    for(auto c: adj[v]){
        if(!bad[c] and c^p){
            dfs_ssz(c, v);
            ssz[v]+=ssz[c];
        }
    }
}
int get_centroid(int v, int p, int sz){
    for(auto c: adj[v]){
        if(!bad[c] and c^p and ssz[c]*2>sz)
            return get_centroid(c, v, sz);
    }
    return v;
}
void calc(int v, int p, bool flag, int depth){
    if(depth>k)
        return;
    mx = max(mx, depth);
    if(flag)
        cnt[depth]++; // incrementing for calculation of next subtrees
    else
        ans+=cnt[k-depth]; // calculation for the current subtree
    for(auto c: adj[v]){
        if(c^p and !bad[c])
            calc(c, v, flag, depth+1);
    }
}

void decompose(int v, int p){
    dfs_ssz(v,p);
    int cen = get_centroid(v, p, ssz[v]);
    bad[cen]=1;
    mx = 0;
    for(auto c: adj[cen]){
        if(!bad[c]){
            calc(c, cen, false, 1); // calculating for this subtree
            calc(c, cen, true, 1); // updating cnt[] for upcoming subtrees calc.
        }
    }
    for(int i = 1; i <= mx; i++)
        cnt[i]=0;
    for(auto c: adj[cen]){
        if(!bad[c]){
            decompose(c, cen);
        }
    }
}




