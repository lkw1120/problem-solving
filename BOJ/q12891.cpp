#include<bits/stdc++.h>
using namespace std;
int arr[4] = {0};
int cnt[4] = {0};
string input;
int S,P,ans;
void add(char ch) {
	if(ch == 'A') cnt[0]++;
	if(ch == 'C') cnt[1]++;
	if(ch == 'G') cnt[2]++;
	if(ch == 'T') cnt[3]++;
}
void subtract(char ch) {
	if(ch == 'A') cnt[0]--;
	if(ch == 'C') cnt[1]--;
	if(ch == 'G') cnt[2]--;
	if(ch == 'T') cnt[3]--;
}
bool check() {
	for(int i=0;i<4;i++) {
		if(cnt[i] < arr[i]) {
			return false;
		}
	}
	return true;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>S>>P;
	cin>>input;
	for(int i=0;i<4;i++) {
		cin>>arr[i];	
	}
	ans = 0;
	for(int i=0;i<S;i++) {
		add(input[i]);
		if(P <= i) {
			subtract(input[i-P]);
		}
		if(P-1 <= i && check()) ans++;
	}
	cout<<ans<<"\n";
	return 0;
}