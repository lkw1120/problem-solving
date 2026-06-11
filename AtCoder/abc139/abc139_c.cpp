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
	int cnt = 0;
	ans = 0;
	for(int i=1;i<N;i++) {
		if(v[i] <= v[i-1]) {
			cnt++;
		}
		else {
			cnt = 0;	
		}
		ans = max(ans,cnt);
	}
	cout<<ans<<"\n";
	return 0;
}