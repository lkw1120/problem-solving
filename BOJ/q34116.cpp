#include<bits/stdc++.h>
using namespace std;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int xmin = 1e9;
    int xmax = -1e9;
    int ymin = 1e9;
    int ymax = -1e9;
    int smin = 1e9;
    int smax = -1e9;
    int pmin = 1e9;
    int pmax = -1e9;
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        xmin = min(xmin,x);
        xmax = max(xmax,x);
        ymin = min(ymin,y);
        ymax = max(ymax,y);
        smin = min(smin,x-y);
        smax = max(smax,x-y);
        pmin = min(pmin,x+y);
        pmax = max(pmax,x+y);
    }
    int up = max(xmax,-ymin+pmax)-min(xmin,ymin+smin);
    int down = max(xmax, ymax+smax)-min(xmin,-ymax+pmin);
    ans = min(up,down);
    cout<<ans<<"\n";
}