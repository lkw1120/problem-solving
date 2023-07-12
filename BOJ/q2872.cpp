#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	int cnt = N;
	for(int i=N-1;i>=0;i--) {
		if(v[i] == cnt) cnt--;	
	}
	ans = cnt;
	cout<<ans<<"\n";
	return 0;
}