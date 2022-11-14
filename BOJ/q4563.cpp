#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll A,B,C,N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(true) {
		cin>>A;
		if(A == 0) break;
		ans = 0;
		N = A*A;
		for(int i=1;i<=A;i++) {
			if(N%i == 0) {
				B = (N/i-i)/2;
				C = (N/i+i)/2;
				if(!((N/i-i)%2) && !((N/i+i)%2) && A < B) {
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;	
}