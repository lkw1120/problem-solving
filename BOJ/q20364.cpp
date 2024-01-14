#include<bits/stdc++.h>
using namespace std;
bool check[1048576];
int N,Q,X,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>Q;
	for(int i=0;i<Q;i++) {
		cin>>X;
		int node = X;
		bool flag = true;
		ans = INT_MAX;
		while(node) {
			if(check[node]) {
				flag = false;
				ans = min(ans,node);
			}
			node/=2;
		}
		if(flag) {
			check[X] = true;
			ans = 0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}