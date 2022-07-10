#include<bits/stdc++.h>
#define MAX 51
using namespace std;
vector<int> v1,v2;
int N,M,book,ans;
void solve() {
	int sum = 0;
	int low,high;
	low = high = 0;
	if(!v1.empty()) {
		sort(v1.begin(),v1.end(),greater<int>());
		for(int i=0;i<v1.size();i+=M) {
			sum+=(abs(v1[i])*2);
		}
		high = abs(v1[0]);
	}
	if(!v2.empty()) {
		sort(v2.begin(),v2.end());
		for(int i=0;i<v2.size();i+=M) {
			sum+=(abs(v2[i])*2);
		}
		low = abs(v2[0]);
	}
	ans = min(sum-low,sum-high);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		cin>>book;
		if(book > 0) {
			v1.push_back(book);
		}
		else {
			v2.push_back(book);	
		}
	}
	ans = 0;
	solve();
	cout<<ans<<"\n";
	return 0;	
}