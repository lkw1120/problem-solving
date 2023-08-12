#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 2e5+1;
map<ll,ll> mp;
ll arr[MAX] = {0};
ll N,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	ans = 0;
	for(int i=1;i<=N;i++) {
		if(arr[i] == K) ans++;
		ans+=mp[arr[i]-K];
		mp[arr[i]]++;
	}
	cout<<ans<<"\n";
	return 0;
}