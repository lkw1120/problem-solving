#include<bits/stdc++.h>
using namespace std;
vector<int> x,y;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    x.resize(N);
    y.resize(N);
    for(int i=0;i<N;i++) {
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            for(int k=j+1;k<N;k++) {
                int dx1 = x[j]-x[i];
                int dy1 = y[j]-y[i];
                int dx2 = x[k]-x[i];
                int dy2 = y[k]-y[i];
                if(dx1*dy2 == dy1*dx2) {
                    cout<<"Yes"<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"No"<<"\n";
    return 0;
}