#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
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
map<int,int> mp;
int N,M,U,V;
ll ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	UnionFind uf(N+1);
	for(int i=0;i<M;i++) {
		cin>>U>>V;
		uf.merge(U,V);
	}
	for(int i=1;i<=N;i++) {
		mp[uf.root(i)] = uf.size(i);
	}
	ans = 1;
	for(auto item: mp) {
		ans*=item.second;
		ans%=MOD;
	}
	cout<<ans<<"\n";
	return 0;
}