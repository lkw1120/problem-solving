#include<bits/stdc++.h>
using namespace std;
map<int,pair<int,int>> mp;
int arr[4][4];
bool check[4][4];
int N,M;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	for(int i=1;i<=3;i++) {
		for(int j=1;j<=3;j++) {
			cin>>arr[i][j];
			mp[arr[i][j]] = {i,j};
		}
	}
	cin>>N;
	for(int i=0;i<N;i++) {
		cin>>M;
		check[mp[M].first][mp[M].second] = true;
	}
	bool flag = false;
	int cnt = 0;
	for(int i=1;i<=3;i++) {
		cnt = 0;
		for(int j=1;j<=3;j++) {
			if(check[i][j]) cnt++;	
		}
		if(cnt == 3) {
			flag = true;
		}
	}
	for(int j=1;j<=3;j++) {
		cnt = 0;
		for(int i=1;i<=3;i++) {
			if(check[i][j]) cnt++;	
		}
		if(cnt == 3) {
			flag = true;
		}
	}
	cnt = 0;
	for(int i=1;i<=3;i++) {
		if(check[i][i]) cnt++;
		if(cnt == 3) {
			flag = true;	
		}
	}
	cnt = 0;
	for(int i=1;i<=3;i++) {
		if(check[i][3-i+1]) cnt++;
		if(cnt == 3) {
			flag = true;	
		}
	}
	if(flag) {
		cout<<"Yes"<<"\n";
	}
	else {
		cout<<"No"<<"\n";
	}
	return 0;
}