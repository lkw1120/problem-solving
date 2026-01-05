#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int N;
double ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    v.resize(N);
    int sum = 0;
    int mx1 = -1;
    int mx2 = -1;
    for(int i=0;i<N;i++) {
        cin>>v[i];
        sum+=v[i];
        if(mx1 <= v[i]) {
            mx2 = mx1;
            mx1 = v[i];
        }
        else if(mx2 < v[i]) {
            mx2 = v[i];
        }
    }
    double tmp = 1.0*sum/N;
    if(N == 1) {
        ans = mx1;
    }
    else {
        ans = max((double)mx2,tmp);
    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";
    return 0;
}