#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N,B,ans;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>B;
		v.push_back(B);
	}
	if(N >= 3) {
		sort(v.begin(),v.end());
		ans = 0;
		for(int i=0;i<N-2;i++) {
			for(int j=N-1;j>i+1;j--) {
				if(v[i] + v[i+1] > v[j]) {
					ans = max(ans,j-i+1);	
					break;
				}
			}
		}
		if(ans < 3) ans = 2;
	}
	else {
		ans = N;
	}
	cout<<ans<<"\n";
	return 0;	
}