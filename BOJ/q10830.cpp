#include<bits/stdc++.h>
using namespace std;
int A[5][5],ans[5][5];
long long N,B;
void multi(int a[][5], int b[][5]) {
    int c[5][5] = {0};
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            for(int k=0;k<N;k++) {
                c[i][j]=(c[i][j]+a[i][k]*b[k][j])%1000;
            }
        }
    }
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            a[i][j] = c[i][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>B;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin>>A[i][j];
        }
        ans[i][i]=1;
    }
    while(B>0) {
        if(B%2==1) {
            multi(ans,A);
        }
        multi(A,A);
        B/=2;
    }

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}