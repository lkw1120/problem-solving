#include<bits/stdc++.h>
using namespace std;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        cin>>N;
        if(N == 0) break;
        vector<int> row(N,0);
        vector<int> col(N,0);
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                int x;
                cin>>x;
                row[i]^=x;
                col[j]^=x;
            }
        }
        vector<int> oddRow,oddCol;
        for(int i=0;i<N;i++) {
            if(row[i]) {
                oddRow.push_back(i+1);
            }
        }
        for(int j=0;j<N;j++) {
            if(col[j]) {
                oddCol.push_back(j+1);
            }
        }
        if(oddRow.empty() && oddCol.empty()) {
            cout<<"OK"<<"\n";
        }
        else if(oddRow.size() == 1 && oddCol.size() == 1) {
            cout<<"Change bit ("<<oddRow[0]<<","<<oddCol[0]<<")\n";
        }
        else {
            cout<<"Corrupt"<<"\n";
        }
    }
    return 0;
}