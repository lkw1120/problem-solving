#include<bits/stdc++.h>
using namespace std;
int C,L,M,ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>C;
    while(C--) {
        cin>>L>>M;
        L*=100;
        queue<int> q1,q2;
        for(int i=0;i<M;i++) {
            int car;
            string bank;
            cin>>car>>bank;
            if(bank == "left") {
                q1.push(car);
            } 
            else {
                q2.push(car);
            }
        }
        ans = 0;
        bool flag = false;
        while(!q1.empty() || !q2.empty()) {
            int tmp = 0;
            if(flag) {
                while(!q2.empty() && tmp+q2.front() <= L) {
                    tmp+=q2.front();
                    q2.pop();
                }
            }
            else {
                while(!q1.empty() && tmp+q1.front() <= L) {
                    tmp+=q1.front();
                    q1.pop();
                }
            }
            ans++;
            flag = !flag;
        }
        cout<<ans<<"\n";
    }
    return 0;
}