#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll arr[2];
ll N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		cin>>str;
		ll cnt = 0;
		for(int j=0;j<M;j++) {
			if(str[j] == '1') cnt++;
		}
		arr[cnt%2]++;
	}
	ans = arr[0]*arr[1];
	cout<<ans<<"\n";
	return 0;
}