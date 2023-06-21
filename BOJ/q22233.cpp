#include<bits/stdc++.h>
using namespace std;
unordered_set<string> us;
string input;
int N,M,ans;
vector<string> split(string str, char ch) {
    vector<string> res;
    stringstream ss(str);
    string buffer;
    while (getline(ss, buffer, ch)) {
        res.push_back(buffer);
    }
    return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++) {
		cin>>input;
		us.insert(input);
	}
	for(int i=0;i<M;i++) {
		cin>>input;
		for(auto item: split(input,',')) {
			us.erase(item);	
		}
		ans = us.size();
		cout<<ans<<"\n";
	}
	return 0;
}