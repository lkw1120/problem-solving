#include<bits/stdc++.h>
using namespace std;
int T,N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>N>>M;
        vector<vector<int>> v(N,vector<int>(M));
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                cin>>v[i][j];
            }
        }
        vector<int> row(N,0),col(M,0);
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                row[i] = max(row[i],v[i][j]);
            }
        }
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                col[j] = max(col[j],v[i][j]);
            }
        }
        bool flag = true;
        for(int i=0;i<N && flag;i++) {
            for(int j=0;j<M;j++) {
                if(v[i][j] != min(row[i],col[j])) {
                    flag = false;
                    break;
                }
            }
        }
        cout<<"Case #"<<tc<<": ";
        if(flag) {
            cout<<"YES"<<"\n";
        }
        else {
            cout<<"NO"<<"\n";
        }
    }
    return 0;
}