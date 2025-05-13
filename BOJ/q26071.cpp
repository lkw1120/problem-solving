#include<bits/stdc++.h>
using namespace std;
vector<string> v;
int N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++) {
        string str;
        cin>>str;
        v.push_back(str);
    }
    int cnt = 0;
    int xmin,xmax,ymin,ymax;
    xmin = ymin = N;
    xmax = ymax = -1;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(v[i][j] == 'G') {
                cnt++;
                xmin = min(xmin,i);
                xmax = max(xmax,i);
                ymin = min(ymin,j);
                ymax = max(ymax,j);
            }
        }
    }
    if(1 < cnt) {
        if(xmin == xmax) {
            ans = min(ymax,(N-1)-ymin);
        }
        else if(ymin == ymax) {
            ans = min(xmax,(N-1)-xmin);
        }
        else {
            int x,y;
            x = min(xmax,(N-1)-xmin);
            y = min(ymax,(N-1)-ymin);
            ans = x+y;
        }
    }
    else {
        ans = 0;
    }
    cout<<ans<<"\n";
    return 0;
}