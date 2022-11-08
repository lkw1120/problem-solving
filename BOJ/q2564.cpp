#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M,K,A,B,X,dist,ans;
int distance(int a, int b) {
	int res = 0;
	if(a == 1) res = b;
	if(a == 2) res = N+M+(N-b);
	if(a == 3) res = N+M+N+(M-B);
	if(a == 4) res = N+B;
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	cin>>K;
	for(int i=0;i<K;i++) {
		cin>>A>>B;
		v.push_back(distance(A,B));
	}
	cin>>A>>B;
	X = distance(A,B);
	dist = ans = 0;
	for(int i=0;i<K;i++) {
		if(0 < X-v[i]) {
			dist = min(X-v[i],2*N+2*M-X+v[i]);
		}
		else {
			dist = min(v[i]-X,2*N+2*M-v[i]+X);
		}
		ans+=dist;
	}
	cout<<ans<<"\n";
	return 0;	
}