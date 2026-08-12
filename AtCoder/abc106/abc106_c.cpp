#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string str;
ll K,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>str>>K;
	int k = 0;
	int size = str.size();
	for(int i=0;i<size;i++) {
		if(str[i] == '1') {
			k++;
		}
		else {
			break;
		}
	}
	if(K <= k) {
		ans = 1;
	}
	else {
		ans = str[k]-'0';
	}
	cout<<ans<<"\n";
	return 0;
}