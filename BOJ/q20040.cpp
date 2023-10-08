#include<bits/stdc++.h>
using namespace std;
const int INF = 987654321;
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
int N,M,A,B,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	UnionFind uf(N);
	ans = INF;
	for(int i=1;i<=M;i++) {
		cin>>A>>B;
		if(uf.issame(A,B)) {
			ans = min(i,ans);
		}
		uf.merge(A,B);
	}
	if(ans == INF) {
		ans = 0;
	}
	cout<<ans<<"\n";
	return 0;
}