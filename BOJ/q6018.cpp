#include<bits/stdc++.h>
using namespace std;
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
int N,M,Q,A,B;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>Q;
	UnionFind uf(N+1);
	for(int i=0;i<M;i++) {
		cin>>A>>B;
		uf.merge(A,B);
	}
	for(int i=0;i<Q;i++) {
		cin>>A>>B;
		if(uf.issame(A,B)) {
			cout<<"Y"<<"\n";
		}
		else {
			cout<<"N"<<"\n";	
		}
	}
	return 0;
}