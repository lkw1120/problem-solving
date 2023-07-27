#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MOD = 1e9+7;
const int MAX = 100001;
ll arr[MAX] = {0};
string input;
ll ans;
void init() {
	arr[0] = 1;
	for(int i=1;i<MAX;i++) {
		arr[i] = (arr[i-1]*2)%MOD;
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin>>input;
	int size = input.size();
	ans = 0;
	for(int i=0;i<size;i++) {
		if(input[i] == 'O') {
			ans+=arr[i];
			ans%=MOD;
		}
	}
	cout<<ans<<"\n";
	return 0;
}