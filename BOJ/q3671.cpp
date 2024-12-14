#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e7+1;
bool p[MAX];
set<int> st;
string str;
int C,ans;
void eratosthenes() {
    fill(p,p+MAX,true);
    p[0] = p[1] = false;
    for(int i=2;i*i<MAX;i++) {
        if(p[i]) {
            for(int j=2;i*j<MAX;j++) {
                p[i*j] = false;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    eratosthenes();
    cin>>C;
    while(C--) {
        st.clear();
        cin>>str;
        sort(str.begin(),str.end());
        int size = str.size();
        do {
            for(int i=0;i<size;i++) {
                int n = stoi(str.substr(i));
                if(p[n]) st.insert(n);
            }
        } while(next_permutation(str.begin(),str.end()));
        ans = st.size();
        cout<<ans<<"\n";
    }
    return 0;
}