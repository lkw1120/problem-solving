#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> tree(1000000);
int N,M;
void preOrder(int n, int m) {
	if(m < n) {
		if(tree[n].first != 0) {
			preOrder(tree[n].first,m);
		}
		else {
			tree[n].first = m;
		}
	}
	else {
		if(tree[n].second != 0) {
			preOrder(tree[n].second,m);
		}
		else {
			tree[n].second = m;
		}
	}
}
void postfix(int n) {
	if(n != 0) {
		if(tree[n].first != 0) {
			postfix(tree[n].first);
		}
		if(tree[n].second != 0) {
			postfix(tree[n].second);
		}
		cout<<n<<"\n";
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	while(cin>>M) {
		preOrder(N,M);
	}
	postfix(N);
	return 0;	
}