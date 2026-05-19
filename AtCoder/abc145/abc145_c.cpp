#include<bits/stdc++.h>
using namespace std;
vector<double> x,y;
vector<int> v;
int N;
double X,Y,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>X>>Y;
        x.push_back(X);
        y.push_back(Y);
        v.push_back(i);
    }
    double total = 0.0;
    int cnt = 0;
    do {
        double dist = 0.0;
        for(int i=0;i<N-1;i++) {
            int a = v[i];
            int b = v[i+1];
            double dx = x[a]-x[b];
            double dy = y[a]-y[b];
            dist+=sqrt(dx*dx+dy*dy);
        }
        total+=dist;
        cnt++;
    } while(next_permutation(v.begin(),v.end()));
    ans = total/cnt;
    cout<<fixed<<setprecision(10)<<ans<<"\n";
    return 0;
}