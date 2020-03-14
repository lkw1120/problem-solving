#include<bits/stdc++.h>
#define SIZE 101
using namespace std;
int N, M;
int matrix[SIZE][SIZE];
bool visited[SIZE][SIZE];
int X[4] = { 1,-1,0,0 };
int Y[4] = { 0,0,1,-1 };
void bfs(int i, int j) {
	queue<pair<int, int>> que;
	que.push(pair<int, int>(i, j));
	visited[i][j] = true;
	while (!que.empty()) {
		pair<int, int> pos = que.front();
		i = pos.first;
		j = pos.second;
		que.pop();
		for (int k = 0; k < 4; k++) {
			if (i + X[k] > 100 || i + X[k] < 0 || j + Y[k]>100 || j + Y[k] < 0) continue;
			if (matrix[i + X[k]][j + Y[k]] != 0 && !visited[i + X[k]][j + Y[k]]) {
				que.push(pair<int, int>(i + X[k], j + Y[k]));
				visited[i + X[k]][j + Y[k]] = true;
				matrix[i + X[k]][j + Y[k]] = matrix[i][j] + 1;
			}
		}
	}
}
int main() {
    ios_base::sync_with_stdio(false);
	cin>>N>>M;
	for (int i = 1; i <= N; i++) {
        string num;
        cin>>num;
		for (int j = 1; j <= M; j++) {
            matrix[i][j] = (num[j-1]=='0')? 0:1;
			if (matrix[i][j] == 1) {
				visited[i][j] = false;
			}
		}
	}
	bfs(1, 1);
    cout<<matrix[N][M]<<"\n";
	return 0;
}
