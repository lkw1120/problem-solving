#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> Pair;
vector<Pair> v;
int N,A,B,ans;
int solve(Pair x, Pair y, Pair z) {
	int a = (x.first*y.second)+(y.first*z.second)+(z.first*x.second);
	int b = (x.second*y.first)+(y.second*z.first)+(z.second*x.first);
	return abs(a-b);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>A>>B;
		v.push_back({A,B});
	}
	ans = 0;
	for(int i=0;i<N-2;i++) {
		for(int j=i+1;j<N-1;j++) {
			for(int k=j+1;k<N;k++) {
				ans = max(solve(v[i],v[j],v[k]),ans);
			}
		}
	}
	if(ans%2) {
		cout<<ans/2<<".5"<<"\n";	
	}
	else {
		cout<<ans/2<<".0"<<"\n";	
	}
	return 0;
}