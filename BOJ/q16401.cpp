#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>M>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	int l,r;
	l = 1, r = *max_element(v.begin(),v.end());
	ans = 0;
	while(l <= r) {
		int mid = (l+r)/2;
		int cnt = 0;
		for(int i=0;i<N;i++) {
			cnt+=(v[i]/mid);
		}
		if(cnt < M) {
			r = mid-1;
		}
		else if(M <= cnt) {
			l = mid+1;
			ans = mid;
		}
	}
	cout<<ans<<"\n";
	return 0;
}