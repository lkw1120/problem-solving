#include<bits/stdc++.h>
using namespace std;
string S;
int ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>S;
	int size = S.size();
	int cnt = 0;
	for(int i=0;i<size;i++) {
		if(S[i] == '1') cnt++;
	}
	ans = min(cnt,size-cnt)*2;
	cout<<ans<<"\n";
	return 0;
}