#include<bits/stdc++.h>
using namespace std;
int X[101];
int Y[101];
int H[101];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=1;i<=N;i++) {
        cin>>X[i]>>Y[i]>>H[i];
    }
    for(int x=0;x<=100;x++) {
        for(int y=0;y<=100;y++) {
            int h = 0;
            for(int i=1;i<=N;i++) {
                if(H[i] != 0) {
                    h = H[i]+abs(x-X[i])+abs(y-Y[i]);	
                }
            }
            bool flag = true;
            for(int i=1;i<=N;i++) {
                if(max(h-abs(X[i]-x)-abs(Y[i]-y),0) != H[i]) {
                    flag = false;
                }
            }
            if(flag) {
                cout<<x<<" "<<y<<" "<<h<<"\n";
                return 0;
            }
        }
    }
    return 0;
}