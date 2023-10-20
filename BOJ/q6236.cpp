#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e9+1;
vector<int> v;
int N,M,ans;
int find(int k) {
	int cnt = 0;
	int n = 0;
	for(int i=0;i<N;i++) {
		if(n < v[i]) {
			n = k-v[i];
			cnt++;
		}
		else {
			n-=v[i];
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];	
	}
	int low,high;
	low = *max_element(v.begin(),v.end());
	high = MAX;
	while(low <= high) {
		int mid = (low+high)/2;
		int cnt = find(mid);
		if(M < cnt) {
			low = mid+1;
		}
		else {
			high = mid-1;
			ans = mid;
		}
	}
	cout<<ans<<"\n";
	return 0;
}