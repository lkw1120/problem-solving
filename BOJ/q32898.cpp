#include<bits/stdc++.h>
using namespace std;
vector<int> x,y,h;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    x.resize(N);
    y.resize(N);
    h.resize(N);
    for(int i=0;i<N;i++) {
        cin>>x[i]>>y[i]>>h[i];
    }
    for(int i=0;i<N;i++) {
        int tmp = h[i];
        for(int j=0;j<N;j++) {
            if(h[i] < h[j]) {
                int dx = x[i]-x[j];
                int dy = y[i]-y[j];
                int d2 = dx*dx+dy*dy;
                int d = sqrt(d2);
                if((d+1)*(d+1) <= d2) d++;
                if(d*d > d2) d--;
                tmp = min(d,tmp);
            }
        }
        ans = tmp;
        cout<<ans<<"\n";
    }
}