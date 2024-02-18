#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 1e5+1;
ll arr[MAX];
ll memo[MAX];
ll N,K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;i++) {
		cin>>arr[i];
		memo[i] = memo[i-1]+arr[i];
	}
	cin>>K;
	ans = 0;
	for(int i=1;i<=N;i++) {
		for(int j=0;j<i;j++) {
			if(memo[i]-memo[j] <= K) break;
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}