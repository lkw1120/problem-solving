#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e5+1;
ll arr[MAX];
ll sum[MAX];
ll N,Q,total,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>Q;
	for(int i=0;i<N;i++) {
		cin>>arr[i];
	}
	total = 0;
	for(int i=0;i<N;i++) {
		sum[i] = arr[i]*arr[(i+1)%N]*arr[(i+2)%N]*arr[(i+3)%N];
		total+=sum[i];
	}
	while(Q--) {
		int q;
		cin>>q;
		ans = total;
		for(int i=q-4;i<q;i++) {
			ans-=sum[(i+N)%N]*2;
			sum[(i+N)%N]*=-1;
		}
		cout<<ans<<"\n";
		total = ans;
	}
	return 0;
}