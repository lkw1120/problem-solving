#include<bits/stdc++.h>
using namespace std;
int N,K,X,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>K;
	ans = 0;
	for(int i=0;i<N;i++) {
		cin>>X;	
		ans+=min(X*2,(K-X)*2);
	}
	cout<<ans<<"\n";
	return 0;
}