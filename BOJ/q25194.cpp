#include<bits/stdc++.h>
#define MAX 100001
using namespace std;
int arr[7] = {0};
vector<int> v;
int N;
string ans;
void solve(int n) {
	if(n%7 == 4) {
		ans = "YES";
		return ;
	}
	for(int i=1;i<7;i++) {
		if(0 < arr[i]) {
			arr[i]--;
			solve(n+i);
			arr[i]++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
		v[i]%=7;
		arr[v[i]]++;
	}
	ans = "NO";
	if(4 <= arr[1] || 2 <= arr[2] || 6 <= arr[3] || 1 <= arr[4] || 5 <= arr[5] || 3 <= arr[6]) {
		ans = "YES";
	}
	else {
		solve(0);
	}
	cout<<ans<<"\n";
	return 0;
}