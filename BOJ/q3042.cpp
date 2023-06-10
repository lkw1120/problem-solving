#include<bits/stdc++.h>
using namespace std;
int arr[101][101] = {0};
vector<pair<int,int>> v;
int N,M,ans;
int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
    return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++) {
		string str;
		cin>>str;
		for(int j=0;j<N;j++) {
			arr[i][j] = str[j];
			if('A' <= arr[i][j] &&arr[i][j] <= 'Z') {
				v.push_back({i,j});
			}
		}
	}
	M = v.size();
	ans = 0;
	for(int i=0;i<M;i++) {
		for(int j=i+1;j<M;j++) {
			for(int k=j+1;k<M;k++) {
				if(!ccw(v[i].first,v[i].second,v[j].first,v[j].second,v[k].first,v[k].second)) {
					ans++;
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}