#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int arr[3][3];
int T,N,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int tc=1;tc<=T;tc++) {
        v.clear();
        cin>>N;
        v.resize(N);
        for(int i=0;i<N;i++) {
            cin>>v[i];
        }
        fill(&arr[0][0],&arr[0][0]+3*3,0);
        for(int i=0;i<N;i++) {
            int a = i%3;
            int b = v[i]%3;
            arr[a][b]++;
        }
        int d = 0;
        d+=min(arr[0][1],arr[1][0]);
        d+=min(arr[0][2],arr[2][0]);
        d+=min(arr[1][2],arr[2][1]);
        int sum = 0;
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                if(i != j) {
                    sum+=arr[i][j];
                }
            }
        }
        int tmp = sum-2*d;
        ans = d+2*(tmp/3);
        cout<<"Case #"<<tc<<": "<<ans<<"\n";
    }
    return 0;
}