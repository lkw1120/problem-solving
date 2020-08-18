#include<bits/stdc++.h>
using namespace std;
vector<int> v,ans;
int N,M;
int gcd(int a, int b) {
	if(b == 0) return a;
	else return gcd(b,a%b);
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	v = vector<int>(N);
	for(int i=0;i<N;i++) cin>>v[i];
	sort(v.begin(),v.end());
	M = v[1]-v[0];
	for(int i=2;i<N;i++) {
		M = gcd(M,v[i]-v[i-1]);
	}
	ans.push_back(M);
	for(int i=2;i*i<=M;i++) {
		if(!(M%i)) {
			ans.push_back(i);
			ans.push_back(M/i);
		}
	}
	sort(ans.begin(),ans.end());
	ans.erase(unique(ans.begin(),ans.end()),ans.end());
	for(auto item: ans) cout<<item<<" ";
	cout<<"\n";
	return 0;
}