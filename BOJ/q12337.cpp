#include<bits/stdc++.h>
using namespace std;
int arr[11][11];
int T,N,M;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        cin>>N>>M;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                cin>>arr[i][j];
            }
        }
        vector<int> row(N,0),col(M,0);
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                row[i] = max(row[i],arr[i][j]);
                col[j] = max(col[j],arr[i][j]);
            }
        }
        bool flag = true;
        for(int i=0;i<N && flag;i++) {
            for(int j=0;j<M;j++) {
                if(arr[i][j] != min(row[i],col[j])) {
                    flag = false;
                    break;
                }
            }
        }
        if(flag) {
            cout<<"Case #"<<tc<<": "<<"YES"<<"\n";
        }
        else {
            cout<<"Case #"<<tc<<": "<<"NO"<<"\n";
        }
    }
    return 0;
}