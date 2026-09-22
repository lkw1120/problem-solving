#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e5+1;
ll arr[MAX];
ll N,W,S,T,P;
string ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>W;
	for(int i=0;i<N;i++) {
		cin>>S>>T>>P;
		arr[S]+=P;
		arr[T]-=P;
	}
	ll now = 0;
	ll top = 0;
	for(int i=0;i<MAX;i++) {
		now+=arr[i];
		arr[i] = now;
		top = max(top,arr[i]);
	}
	ans = (top <= W)? "Yes":"No";
	cout<<ans<<"\n";
	return 0;
}