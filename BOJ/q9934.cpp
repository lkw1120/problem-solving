#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<vector<int>> res;
int K,N;
void solve(int k, int l, int r) {
	if(l+1 == r) {
		res[k].push_back(v[l]);
		return ;
	}
	int mid = (l+r)/2;
	solve(k+1,l,mid);
	res[k].push_back(v[mid]);
	solve(k+1,mid+1,r);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>K;
	N = pow(2,K)-1;
	v.resize(N);
	res.resize(K);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	solve(0,0,N);
	for(auto node: res) {
		for(auto item: node) {
			cout<<item<<" ";
		}
		cout<<"\n";
	}
	return 0;	
}