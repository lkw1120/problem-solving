#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int abc[26] = {0};
int N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	v.resize(N);
	for(int i=0;i<N;i++) {
		cin>>v[i];
		sort(v[i].begin(),v[i].end());
	}
	int size1 = v[0].size();
	for(int i=0;i<size1;i++) {
		abc[v[0][i]-'A']++;	
	}
	ans = 0;
	for(int i=1;i<N;i++) {
		int size2 = v[i].size();
		if(1 < abs(size1-size2)) continue;
		if(v[0] == v[i]) {
			ans++;
		}
		else {
			int cnt = 0;
			int sub[26] = {0};
			for(int j=0;j<26;j++) {
				sub[j] = abc[j];
			}
			for(int j=0;j<size2;j++) {
				if(0 < sub[v[i][j]-'A']) {
					sub[v[i][j]-'A']--;
					cnt++;
				}
			}
			if(cnt+1 == size1 && size1 == size2) {
				ans++;
			}
			else if(cnt+1 == size1 &&size1 == size2+1) {
				ans++;
			}
			else if(cnt == size1 && size1 == size2-1) {
				ans++;	
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}