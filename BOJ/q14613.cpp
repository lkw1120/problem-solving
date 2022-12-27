#include<bits/stdc++.h>
using namespace std;
double dp[21][3500] = {0};
double W,L,D;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>W>>L>>D;
	dp[0][2000] = 1;
	for(int i=1;i<=20;i++) {
		for(int j=1000;j<3500;j++) {
			if(dp[i-1][j]) {
				dp[i][j+50]+=dp[i-1][j]*W;
				dp[i][j-50]+=dp[i-1][j]*L;
				dp[i][j]+=dp[i-1][j]*D;
			}
		}
	}
	double b,s,g,p,d;
	b = s = g = p = d = 0;
	for(int j=1000;j<3500;j++) {
		if(1000 <= j && j < 1500) b+=dp[20][j];
		if(1500 <= j && j < 2000) s+=dp[20][j];
		if(2000 <= j && j < 2500) g+=dp[20][j];
		if(2500 <= j && j < 3000) p+=dp[20][j];
		if(3000 <= j && j < 3500) d+=dp[20][j]; 
	}
	cout<<fixed;
	cout.precision(8);
	cout<<b<<"\n";
	cout<<s<<"\n";
	cout<<g<<"\n";
	cout<<p<<"\n";
	cout<<d<<"\n";
	return 0;	
}