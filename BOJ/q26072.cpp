#include<bits/stdc++.h>
using namespace std;
vector<double> v1,v2;
double N,L,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>L;
    v1.resize(N);
    v2.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v1[i];
    }
    for(int i=0;i<N;i++) {
        cin>>v2[i];
    }
    double l,r;
    l = 0, r = L;
    while(0.0000001 < r-l) {
        double mid = (l+r)/2;
        double left,right;
        left = right = 0;
        for(int i=0;i<N;i++) {
            if(v1[i] < mid) {
                left+=v2[i]*(mid-v1[i]);
            }
            else {
                right+=v2[i]*(v1[i]-mid);
            }
        }
        if(left < right) {
            l = mid;
            ans = l;
        }
        else {
            r = mid;
        }
    }
    cout<<fixed;
	cout.precision(6);
    cout<<ans<<"\n";
    return 0;
}