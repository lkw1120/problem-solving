#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<set<int>> v;
vector<int> res;
int N,M,K,A,B,C,D;
struct UnionFind {
    vector<int> parent;
    UnionFind(int n) : parent(n, -1) { }

    int root(int x) {
        if (parent[x] < 0) return x;
        else return parent[x] = root(parent[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (parent[x] > parent[y]) swap(x, y);
        parent[x] += parent[y];
        parent[y] = x;
        return true;
    }
    
    int size(int x) {
        return -parent[root(x)];
    }
};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M>>K;
    UnionFind uf(N+1);
    v.resize(N+1);
    for(int i=0;i<M;i++) {
        cin>>A>>B;
        v[A].insert(B);
        v[B].insert(A);
        uf.merge(A,B);
    }
    for(int i=0;i<K;i++) {
        cin>>C>>D;
        if(uf.issame(C,D)) {
            v[C].insert(D);
            v[D].insert(C);
        }
    }
    for(int i=1;i<=N;i++) {
        res.push_back(uf.size(i)-v[i].size()-1);
    }
    for(int i=0;i<N;i++) {
        cout<<res[i]<<" ";	
    }
    cout<<"\n";
    return 0;
}