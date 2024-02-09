#include<bits/stdc++.h>
using namespace std;
int dp[37];
string str;
int N,S,G,P,D,ans;
int solve(int n, char ch) {
	if (n == 0) {
		switch(ch) {
			case 'B':
				return S-1;
			case 'S':
				return G-1;
			case 'G':
				return P-1;
			case 'P':
				return D-1;
			default:
				return D;
		}
	}
	else {
		switch(ch) {
			case 'B':
				return S-1-dp[n-1];
			case 'S':
				return G-1-dp[n-1];
			case 'G':
				return P-1-dp[n-1];
			case 'P':
				return D-1-dp[n-1];
			default:
				return D;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>S>>G>>P>>D;
	cin>>str;
	for(int i=0;i<N;i++) {
		dp[i] = solve(i,str[i]);
	}
	for(int i=0;i<N;i++) {
		ans+=dp[i];	
	}
	cout<<ans<<"\n";
	return 0;
}