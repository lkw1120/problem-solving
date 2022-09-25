#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,M,sum,l,r,a,b,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	sum = 0;
	for(int i=0;i<N;i++) {
		cin>>M;
		v.push_back(M);
		sum+=M;
	}
	ans = 0;
	l = 0;
	r = 1;
	a = b = 0;
	while(l < r && r <= N) {
		a+=v[r-1];
		b = sum-a;
		ans = max(min(a,b),ans);
		if(a < b) {
			r++;
		}
		else {
			a-=v[l];
			a-=v[r-1];
			l++;
		}
	}
	cout<<ans<<"\n";
	return 0;	
}