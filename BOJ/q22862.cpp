#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,K,L,R,cnt,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	L = 0;
	R = 1;
	cnt = v[0]%2? 1:0;
	while(true) {
		while(R < N) {
			if(v[R]%2) {
				if(cnt < K) cnt++;
				else break;
			}
			R++;
		}
		if(N <= L || N < R) break;
		ans = max(ans,R-L-cnt);
		if(v[L]%2) cnt--;
		L++;
	}
	cout<<ans<<"\n";
	return 0;	
}