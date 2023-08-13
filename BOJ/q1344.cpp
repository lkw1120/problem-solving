#include<bits/stdc++.h>
using namespace std;
double dp[20][20][20] = {0};
double A,B,ans;
bool isPrime(int n) {
	if(n < 2) return false;
	for(int i=2;i*i<=n;i++) {
		if(n%i == 0) return false;	
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B;
	A/=100,B/=100;
	dp[0][0][0] = 1;
	for(int i=1;i<=18;i++) {
		for(int a=0;a<=i;a++) {
			for(int b=0;b<=i;b++) {
				dp[i][a][b]+=dp[i-1][a][b]*(1-A)*(1-B);
				if(0 < a) {
					dp[i][a][b]+=A*(1-B)*dp[i-1][a-1][b];
				}
				if(0 < b) {
					dp[i][a][b]+=(1-A)*B*dp[i-1][a][b-1];
				}
				if(0 < a && 0 < b) {
					dp[i][a][b]+=A*B*dp[i-1][a-1][b-1];	
				}
			}
		}
	}
	ans = 0;
	for(int i=0;i<=18;i++) {
		for(int j=0;j<=18;j++) {
			if(isPrime(i) || isPrime(j)) {
				ans+=dp[18][i][j];	
			}
		}
	}
	cout<<setprecision(10)<<ans<<"\n";
	return 0;
}#include<bits/stdc++.h>
using namespace std;
double dp[20][20][20] = {0};
double A,B,ans;
bool isPrime(int n) {
	if(n < 2) return false;
	for(int i=2;i*i<=n;i++) {
		if(n%i == 0) return false;	
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B;
	A/=100,B/=100;
	dp[0][0][0] = 1;
	for(int i=1;i<=18;i++) {
		for(int a=0;a<=i;a++) {
			for(int b=0;b<=i;b++) {
				dp[i][a][b]+=dp[i-1][a][b]*(1-A)*(1-B);
				if(0 < a) {
					dp[i][a][b]+=A*(1-B)*dp[i-1][a-1][b];
				}
				if(0 < b) {
					dp[i][a][b]+=(1-A)*B*dp[i-1][a][b-1];
				}
				if(0 < a && 0 < b) {
					dp[i][a][b]+=A*B*dp[i-1][a-1][b-1];	
				}
			}
		}
	}
	ans = 0;
	for(int i=0;i<=18;i++) {
		for(int j=0;j<=18;j++) {
			if(isPrime(i) || isPrime(j)) {
				ans+=dp[18][i][j];	
			}
		}
	}
	cout<<setprecision(10)<<ans<<"\n";
	return 0;
}