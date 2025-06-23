#include<bits/stdc++.h>
using namespace std;
double arr[11][11];
int N,R,S,X,Y,W;
void init() {
    for(int i=0;i<=10;i++) {
        arr[i][0] = arr[i][i] = 1.0;
        for(int j=1;j<i;j++) {
            arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin>>N;
    while(N--) {
        cin>>R>>S>>X>>Y>>W;
        double p,q,win;
        p = double(S-R+1)/S;
        q = 1.0-p;
        win = 0.0;
        for(int i=X;i<=Y;i++) {
            win+=arr[Y][i]*pow(p,i)*pow(q,Y-i);
        }
        if(1.0 < win*W) {
            cout<<"yes"<<"\n";
        }
        else {
            cout<<"no"<<"\n";
        }
    }
    return 0;
}