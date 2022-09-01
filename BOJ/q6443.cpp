#include<bits/stdc++.h>
using namespace std;
int N;
string str;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	while(N--) {
		cin>>str;
		sort(str.begin(),str.end());
		map<string,bool> mp;
		do {
			if(!mp.count(str)) {
				mp[str] = true;
				cout<<str<<"\n";
			}
		} while(next_permutation(str.begin(),str.end()));
		
	}
	return 0;
}