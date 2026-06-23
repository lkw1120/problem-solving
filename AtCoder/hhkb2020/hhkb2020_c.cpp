#include<bits/stdc++.h>
using namespace std;
bool used[200010];
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    int mex = 0;
    for(int i=0;i<N;i++) {
        int p;
        cin>>p;
        used[p] = true;
        while(used[mex]) {
            mex++;
        }
        cout<<mex<<"\n";
    }
    return 0;
}