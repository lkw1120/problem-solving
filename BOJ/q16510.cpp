#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 2e5+1;
ll arr[MAX] = {0};
ll N,M,T,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	for(int i=0;i<M;i++) {
		cin>>T;
		ans = upper_bound(arr+1,arr+N+1,T)-(arr+1);
		cout<<ans<<"\n";
	}
	return 0;
}