#include<bits/stdc++.h>
using namespace std;
typedef pair<int,string> Pair;
vector<vector<Pair>> v;
int P,M,L;
string id;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>P>>M;
	for(int i=0;i<P;i++) {
		cin>>L>>id;
		if(v.empty()) {
			vector<Pair> tmp;
			tmp.push_back({L,id});
			v.push_back(tmp);
		}
		else {
			bool flag = false;
			for(int j=0;j<v.size();j++) {
				int low = v[j][0].first-10;
				int high = v[j][0].first+10;
				if(low <= L && L <= high && v[j].size() < M) {
					v[j].push_back({L,id});
					flag = true;
					break;
				}
			}
			if(!flag) {
				vector<Pair> tmp;
				tmp.push_back({L,id});
				v.push_back(tmp);
			}
		}
	}
	for(int i=0;i<v.size();i++) {
		if(v[i].size() == M) {
			cout<<"Started!"<<"\n";	
		}
		else {
			cout<<"Waiting!"<<"\n";
		}
		sort(v[i].begin(),v[i].end(),[](Pair a, Pair b) {
			return a.second < b.second;
		});
		for(int j=0;j<v[i].size();j++) {
			cout<<v[i][j].first<<" "<<v[i][j].second<<"\n";	
		}
	}
	return 0;
}