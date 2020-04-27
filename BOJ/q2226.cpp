#include<bits/stdc++.h>
using namespace std;
vector<short> v;
int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin>>N;
    if(N == 1) {
        v.push_back(0);
    }
    else {
        v.push_back(1);
        for(int i=3;i<=N;i++) {
            for(int j=0;j<v.size();j++) {
                v[j]*=2;
            }
            if(i%2) {
                v[0]--;
            }
            else {
                v[0]++;
            }
            for(int j=v.size()-1;j>=0;j--) {
                if(v[j]/10) {
                    if(j==v.size()-1) {
                        v.push_back(0);
                    }
                    v[j]%=10;
                    v[j+1]++;
                }
            }
        }
    }
    for(int i=v.size()-1;i>=0;i--) {
        cout<<v[i];
    }
    cout<<"\n";
    return 0;
}