#include<bits/stdc++.h>
using namespace std;
vector<int> x,y;
int N,X,Y;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        x.push_back(X);
        y.push_back(Y);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    X = N/2;
    Y = N/2;
    if(N%2 == 0) {
        X--;
        Y--;
    }
    cout<<x[X]<<" "<<y[Y]<<"\n";
    return 0;
}