#include<bits/stdc++.h>
using namespace std;
int tree[101] = {0};
vector<int> res;
int K,A,B;
vector<string> split(string input, char delimiter) {
    vector<string> res;
    stringstream ss(input);
    string temp;
    while(getline(ss, temp, delimiter)) {
        res.push_back(temp);
    }
    return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>K;
	while(true) {
		int parent;
		cin>>parent;
		cin.ignore();
		if(parent == -1) break;
		string str;
		getline(cin,str);
		auto v = split(str,' ');
		int size = v.size();
		for(int i=0;i<size;i++) {
			int child = stoi(v[i]);
			tree[child] = parent;
		}
	}
	int p = K;
	while(tree[p]) {
		res.push_back(p);
		p = tree[p];
	}
	res.push_back(p);
	for(auto item: res) {
		cout<<item<<" ";	
	}
	cout<<"\n";
	return 0;
}