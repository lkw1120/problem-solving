#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int arr[101] = {0};
ll T,N,ans;
int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	else {
		return gcd(b,a%b);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>T;
	for(int t=0;t<T;t++) {
		cin>>N;
		for(int i=1;i<=N;i++) {
			cin>>arr[i];
		}
		ans = 0;
		for(int i=1;i<N;i++) {
			for(int j=i+1;j<=N;j++) {
				ans += gcd(arr[i],arr[j]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;	
}