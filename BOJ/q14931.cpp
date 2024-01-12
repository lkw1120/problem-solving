#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e6+1;
ll arr[MAX];
ll N,d,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	ans = LONG_MIN;
	for(int i=N;i>0;i--) {
		ll sum = 0;
		for(int j=1;j*i<=N;j++) {
			sum+=arr[i*j];
		}
		if(ans <= sum) {
			ans = sum;
			d = i;
		}
	}
	if(ans < 0) {
		d = ans = 0;	
	}
	cout<<d<<" "<<ans<<"\n";
	return 0;
}