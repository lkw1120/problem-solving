#include<bits/stdc++.h>
using namespace std;
int N,A,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N;
	ans = 0;
	for(int i=0;i<N;i++) {
		cin>>A;
		while(A%2 == 0) {
			ans++;
			A/=2;
		}
	}
	cout<<ans<<"\n";
	return 0;
}