#include<bits/stdc++.h>
using namespace std;
int N,M,U,D,ans;
int solve(int u, int d) {
	int l,r;
	l = 0;
	r = N;
	int res = 0;
	while(l <= r) {
		int mid = (l+r)/2;
		int floor = u*mid-d*(N-mid);
		if(0 < floor) {
			r = mid-1;
			res = floor;
		}
		else {
			l = mid+1;
		}
	}
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	ans = INT_MAX;
	for(int i=0;i<M;i++) {
		cin>>U>>D;
		ans = min(ans,solve(U,D));
	}
	cout<<ans<<"\n";
	return 0;
}