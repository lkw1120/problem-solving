#include<bits/stdc++.h>
using namespace std;
const int MAX = 50001;
int parent[MAX];
int ranks[MAX];
int N,M,A,B,ans;
int find(int x) {
	if(parent[x] != x) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
	if(x == y) return ;
	ans--;
	if(ranks[x] < ranks[y]) {
		parent[x] = y;
	}
	else if(ranks[y] < ranks[x]) {
		parent[y] = x;
	}
	else {
    	parent[y] = x;
		ranks[x]++;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int t=1;;t++) {
		cin>>N>>M;
		if(N == 0) break;
		for(int i=0;i<MAX;i++) {
			parent[i] = i;
			ranks[i] = 0;
		}
		ans = N;
		for(int i=0;i<M;i++) {
			cin>>A>>B;
			merge(A,B);
		}
		cout<<"Case "<<t<<": "<<ans<<"\n";
	}
	return 0;
}