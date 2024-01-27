#include<bits/stdc++.h>
using namespace std;
set<string> st;
char arr1[50];
char arr2[100][50];
int N,M,ans;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>arr1[i];
	}
	for(int i=0;i<N;i++) {
		string str = "";
		for(int j=0;j<N;j++) {
			str+=arr1[(i+j)%N];
		}
		st.insert(str);
		for(int j=0;j<N;j++) {
			switch(str[j]) {
				case '1':
					str[j] = '3';
					break;
				case '2':
					str[j] = '4';
					break;
				case '3':
					str[j] = '1';
					break;
				case '4':
					str[j] = '2';
					break;
				default:
					break;
			}
		}
		reverse(str.begin(),str.end());
		st.insert(str);
	}
	cin>>M;
	for(int i=0;i<M;i++) {
		for(int j=0;j<N;j++) {
			cin>>arr2[i][j];
		}
	}
	vector<int> res;
	for(int i=0;i<M;i++) {
		string str = "";
		for(int j=0;j<N;j++) {
			str+=arr2[i][j];
		}
		if(st.count(str)) {
			res.push_back(i);	
		}
	}
	ans = res.size();
	cout<<ans<<"\n";
	for(auto idx: res) {
		for(int i=0;i<N;i++) {
			cout<<arr2[idx][i]<<" ";	
		}
		cout<<"\n";
	}
	return 0;
}