#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	int n = 0;
	ans = -1;
	for(int i=0;i<N;i++) {
		if(v[i] == n+1) {
			n++;
		}
	}
	if(n) {
		ans = N-n;
	}
	cout<<ans<<"\n";
	return 0;
}