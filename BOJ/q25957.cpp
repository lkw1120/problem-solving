#include<bits/stdc++.h>
using namespace std;
unordered_map<string,string> mp;
vector<string> v;
string word;
int N,M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>word;
		int size = word.size();
		if(size <= 3) {
			mp[word] = word;
		}
		else {
			string str = word.substr(1,size-2);
			sort(str.begin(),str.end());
			mp[word[0]+str+word[size-1]] = word;
		}
	}
	cin>>M;
	for(int i=0;i<M;i++) {
		cin>>word;
		int size = word.size();
		if(size <= 3) {
			v.push_back(word);
		}
		else {
			string str = word.substr(1,size-2);
			sort(str.begin(),str.end());
			v.push_back(mp[word[0]+str+word[size-1]]);
		}
	}
	for(auto item: v) {
		cout<<item<<" ";	
	}
	cout<<"\n";
	return 0;
}