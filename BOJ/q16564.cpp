#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> v;
int N,K,ans;
ll check(int n) {
	ll sum = 0;
	for(int i=0;i<N;i++) {
		if(v[i] < n) {
			sum+=(n-v[i]);
		}
	}
	return sum;
}
int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	int left,right;
	left = v[0],
	right = v[N-1]+K;
	while(left <= right) {
		int mid = (left+right)/2;
		if (check(mid) <= K) {
			left = mid+1;
		}
		else {
			right = mid-1;
		}
	}
	ans = right;
	cout<<ans<<"\n";
	return 0;
}