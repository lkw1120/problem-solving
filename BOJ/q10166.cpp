#include<bits/stdc++.h>
using namespace std;
int arr[2001][2001];
int N,M,ans;
int gcd(int a, int b) {
	return b == 0? a: gcd(b,a%b);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	ans = 1;
	for(int i=N;i<=M;i++) {
		for(int j=1;j<i;j++) {
			int tmp = gcd(i,j);
			int a = i/tmp;
			int b = j/tmp;
			if(!arr[a][b]) {
				arr[a][b]++;
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}