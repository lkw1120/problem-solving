#include<bits/stdc++.h>
using namespace std;
map<string,int> mp = {
	{"ESTJ",0},{"ESTP",1},{"ESFJ",2},{"ESFP",3},
	{"ENTJ",4},{"ENTP",5},{"ENFJ",6},{"ENFP",7},
	{"ISTJ",8},{"ISTP",9},{"ISFJ",10},{"ISFP",11},
	{"INTJ",12},{"INTP",13},{"INFJ",14},{"INFP",15},
};
string str;
int T,N,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>N;
		vector<string> v;
		for(int i=0;i<N;i++) {
			cin>>str;
			v.push_back(str);
		}
		if(32 < N) {
			ans = 0;
		}
		else {
			ans = INT_MAX;
			for(int i=0;i<N;i++) {
				for(int j=i+1;j<N;j++) {
					for(int k=j+1;k<N;k++) {
						int a = mp[v[i]];
						int b = mp[v[j]];
						int c = mp[v[k]];
						int dist = 0;
						dist+=bitset<4>(a^b).count();
						dist+=bitset<4>(b^c).count();
						dist+=bitset<4>(a^c).count();
						ans = min(ans,dist);
					}
				}
			}
			if(ans == INT_MAX) {
				ans = 0;	
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}