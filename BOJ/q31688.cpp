#include <bits/stdc++.h>
using namespace std;
int T,N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--) {
        cin>>N;
        vector<vector<int>> v(N,vector<int>(N));
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin>>v[i][j];
            }
        }
        vector<int> path;
        for(int i=0;i<N;i++) {
            if(i%2 == 0) {
                for(int j=0;j<N;j++) {
                    path.push_back(v[i][j]);
                }
            }
            else {
                for(int j=N-1;j>=0;j--) {
                    path.push_back(v[i][j]);
                }
            }
        }
        int size = path.size();
        int up,down;
        up = down = 0;
        for(int i=1;i<size;i++) {
            if(path[i-1] < path[i]) {
                up++;
            }
            else if(path[i] < path[i-1]) {
                down++;
            }
        }
        if(down < up) {
            reverse(path.begin(),path.end());
        }
        for(auto item: path) {
            cout<<item<<" ";
        }
        cout<<"\n";
    }
    return 0;
}