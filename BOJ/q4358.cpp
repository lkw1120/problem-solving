#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
vector<pair<string, double>> v;
string str;
int N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	N = 0;
	while(getline(cin,str)) {
		if(str == "") break;
		if(mp.count(str) != 0) {
			mp[str]++;
		}
		else {
			mp[str] = 1;	
		}
		N++;
    }
	for(auto item: mp) {
		v.push_back({item.first,(double)(item.second*100.0/N)});
	}
	sort(v.begin(),v.end());
	cout<<fixed;
	cout.precision(4);
	for(auto item: v) {
		cout<<item.first<<" "<<item.second<<"\n";
	}
	return 0;	
}