#include<bits/stdc++.h>
using namespace std;
string arr[10][7] = {
	{"000000","001100","010010","010010","010010","001100","000000"},
	{"000000","000100","001100","000100","000100","000100","000000"},
	{"000000","011110","000010","011110","010000","011110","000000"},
	{"000000","011100","000010","000100","000010","011100","000000"},
	{"000000","000100","001100","010100","111110","000100","000000"},
	{"000000","011110","010000","011100","000010","010010","001100"},
	{"000000","010000","010000","011110","010010","011110","000000"},
	{"000000","011110","000010","000100","000100","000100","000000"},
	{"000000","011110","010010","011110","010010","011110","000000"},
	{"011110","010010","010010","011110","000010","000010","000010"}
};
string input[7],res[7];
vector<int> v,vv;
void convert() {
	int size = input[0].size();
	for(int i=0;i<size;i+=6) {
		for(int j=0;j<10;j++) {
			bool flag = true;
			for(int k=0;k<7;k++) {
				if(input[k].substr(i,6) != arr[j][k]) {
					flag = false;
				}
			}
			if(flag) {
				v.push_back(j);
				vv.push_back(j);
			}
		}
	}
}
void reverse() {
	for(auto item: v) {
		for(int i=0;i<7;i++) {
			res[i]+=arr[item][i];	
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<7;i++) {
		cin>>input[i];
	}
	convert();
	sort(v.begin(),v.end());
	bool flag = false;
	int size = v.size();
	do {
		if(flag) {
			reverse();
			flag = false;
			break;
		}
		int cnt = 0;
		for(int i=0;i<size;i++) {
			if(v[i] == vv[i]) cnt++;
		}
		if(cnt == size) flag = true;
	} while(next_permutation(v.begin(),v.end()));
	if(flag) {
		cout<<"The End"<<"\n";
	}
	else {
		for(auto item: res) {
			cout<<item<<"\n";	
		}
	}
	return 0;
}