#include<bits/stdc++.h>
using namespace std;
vector<pair<string,string>> vp;
vector<string> v{
	"Bessie",
	"Buttercup",
	"Belinda",
	"Beatrice",
	"Bella",
	"Blue",
	"Betsy",
	"Sue"
};
int N;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		string a,b,c,d,e,f;
		cin>>a>>b>>c>>d>>e>>f;
		vp.push_back({a,f});
	}
	sort(v.begin(),v.end());
	do {
		int cnt = 0;
		for(auto item: vp) {
			for(int j=0;j<8;j++) {
                if(v[j] == item.first && v[j+1] == item.second) {
					cnt++;
				}
                if(v[j] == item.second && v[j+1] == item.first) {
					cnt++;
				}
			}
		}
		if(cnt == N) break;
	} while(next_permutation(v.begin(),v.end()));
	for(auto item: v) {
		cout<<item<<"\n";
	}
	return 0;
}