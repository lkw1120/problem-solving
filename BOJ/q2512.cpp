#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M,ans;
bool solve(int n) {
	int sum = 0;
	for(int i=0;i<N;i++) {
		if(v[i] < n) {
			sum+=v[i];
		}
		else {
			sum+=n;	
		}
	}
	return sum <= M;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	cin>>M;
	int low,high;
	low = 0;
	high = *max_element(v.begin(),v.end());
	while(low <= high) {
		int mid = (low+high)/2;
		if(solve(mid)) {
			low = mid+1;
			ans = mid;
		}
		else {
			high = mid-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}