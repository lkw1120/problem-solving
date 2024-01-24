#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1001][1001];
ll row[1001];
ll col[1001];
set<ll> st;
ll N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	ans = 0;
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=M;j++) {
			cin>>arr[i][j];
			ans+=arr[i][j];
			if(row[i] < arr[i][j]) {
				row[i] = arr[i][j];
				col[j] = max(col[j],arr[i][j]);
			}
			if(col[j] < arr[i][j]) {
				col[j] = arr[i][j];
				row[i] = max(row[i],arr[i][j]);
			}
		}
	}
	for(int i=1;i<=N;i++) {
		st.insert(row[i]);
	}
	for(int i=1;i<=M;i++) {
		st.insert(col[i]);
	}
	for(auto item: st) {
		ans-=item;	
	}
	cout<<ans<<"\n";
	return 0;
}