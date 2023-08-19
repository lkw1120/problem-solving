#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e5+1;
ll arr[MAX] = {0};
ll cache[MAX] = {0};
ll N,P,M,A,B,C,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		cin>>arr[i];
	}
	for(int i=1;i<M;i++) {
		if(arr[i] < arr[i+1]) {
			cache[arr[i]]++;
			cache[arr[i+1]]--;
		}
		else {
			cache[arr[i]]--;
			cache[arr[i+1]]++;
		}
	}
	for(int i=1;i<=N;i++) {
		cache[i]+=cache[i-1];	
	}
	ans = 0;
	for(int i=1;i<N;i++) {
		cin>>A>>B>>C;
		ans+=min(A*cache[i],B*cache[i]+C);
	}
	cout<<ans<<"\n";
	return 0;
}