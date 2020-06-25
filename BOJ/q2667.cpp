#include<bits/stdc++.h>
using namespace std;
const int MAX = 25;
int matrix[MAX][MAX] = {0};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
vector<int> v;
int N, cnt, ans;
int dfs(int y, int x) {
    matrix[y][x] = 0;
    cnt++;
    for(int i=0;i<4;i++) {
        int nX = x+dX[i];
        int nY = y+dY[i];
        if(0 <= nX && nX < N && 0 <= nY && nY < N
        && 1 == matrix[nY][nX]) {
            dfs(nY,nX);     
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    string str;
    for(int i=0;i<N;i++) {
        cin>>str;
        for(int j=0;j<N;j++) {
            matrix[i][j] = str[j]-'0';
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(matrix[i][j] == 1) {
                cnt = 0;
                v.push_back(dfs(i,j));
            }
        }
    }
    sort(v.begin(),v.end());
    ans = v.size();
    cout<<ans<<"\n";
    for(auto item: v) {
        cout<<item<<"\n";
    }
    return 0;
}