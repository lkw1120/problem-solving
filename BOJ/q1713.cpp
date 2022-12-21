#include<bits/stdc++.h>
using namespace std;
vector<int> v;
map<int,int> mp;
int N,M,A,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--) {
		cin>>A;
		auto it = find(v.begin(),v.end(),A);
		if(it != v.end()) {
			mp[A]++;
		}
		else {
			if(v.size() < N) {
				v.push_back(A);
				mp[A] = 1;
			}
			else {
				int a,idx,cnt;
                a = idx = 0;
				cnt = 1001;
				for(int i=v.size()-1;i>=0;i--) {
					if(mp[v[i]] <= cnt) {
						cnt = mp[v[i]];
						a = v[i];
						idx = i;
					}
				}
				mp[a] = 0;
				v.erase(v.begin()+idx);
				v.push_back(A);
				mp[A] = 1;
			}
		}
	}
	sort(v.begin(),v.end());
	for(auto item: v) {
		cout<<item<<" ";	
	}
	cout<<"\n";
	return 0;	
}