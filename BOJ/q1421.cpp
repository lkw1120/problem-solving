#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e5+1;
ll arr[51] = {0};
ll N,C,W,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>C>>W;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
	}
	ans = 0;
	for(int i=1;i<MAX;i++) {
		ll sum = 0;
		for(int j=1;j<=N;j++) {
			int cnt = arr[j]/i;
			if(cnt) {
				if(arr[j]%i) {
					sum = max(sum,sum+cnt*i*W-(cnt*C));	
				}
				else {
					sum = max(sum,sum+cnt*i*W-(cnt-1)*C);
				}
			}
		}
		ans = max(sum,ans);
	}
	cout<<ans<<"\n";
	return 0;
}