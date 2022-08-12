#include<bits/stdc++.h>
#define MAX 251
using namespace std;
char arr[MAX][MAX] = {};
vector<pair<int,int>> v;
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int R,C,O,V;
void dfs(int x, int y) {
	if(arr[x][y] == 'v') V++;
	if(arr[x][y] == 'o') O++;
	arr[x][y] = '#';
	for(int i=0;i<4;i++) {
		if((0 < x+dX[i]	&& x+dX[i] <= R) &&
		   (0 < y+dY[i] && y+dY[i] <= C) &&
		   (arr[x+dX[i]][y+dY[i]] != '#')) {
			dfs(x+dX[i],y+dY[i]);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>R>>C;
	for(int i=1;i<=R;i++) {
		string str;
		cin>>str;
		for(int j=1;j<=C;j++) {
			arr[i][j] = str[j-1];
		}
	}
	for(int i=1;i<=R;i++) {
		for(int j=1;j<=C;j++) {
			if(arr[i][j] != '#') {
				O = V = 0;
				dfs(i,j);
				v.push_back({O,V});
			}
		}
	}
	O = V = 0;
	for(auto item: v) {
		if(item.first > item.second) {
			O+=item.first;	
		}
		else {
			V+=item.second;	
		}
	}
	cout<<O<<" "<<V<<"\n";
	return 0;	
}