#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int INF = 1e9;
int arr1[1001] = {0};
int arr2[1001] = {0};
ll N,M,ans;
ll gcd(ll a, ll b) {
	return b == 0? a: gcd(b,a%b);	
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr1[i];	
	}
	cin>>M;
	for(int j=1;j<=M;j++) {
		cin>>arr2[j];	
	}
	ans = 1;
	bool flag = false;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			ll tmp = gcd(arr1[i],arr2[j]);
			ans*=tmp;
			arr1[i]/=tmp;
			arr2[j]/=tmp;
			if(ans/INF) {
				ans%=INF;
				flag = true;
			}
		}
	}
	if(flag) {
		cout.width(9);
		cout.fill('0');
	}
	cout<<ans<<"\n";
	return 0;
}