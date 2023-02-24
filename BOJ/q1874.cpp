#include<bits/stdc++.h>
using namespace std;
vector<char> c;
vector<int> v;
stack<int> s;
int N;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    v.resize(N);
    for(int i=0;i<N;i++) {
        cin>>v[i];
    }
    int n = 1;
    for(int i=0;i<N;i++) {
        if(s.empty()) {
            s.push(n++);
            c.push_back('+');
        }
        if(s.top() < v[i]) {
            while(s.top() < v[i]) {
                s.push(n++);
                c.push_back('+');
            }
        }
        else if(s.top() > v[i]) {
            while(!s.empty() && s.top() > v[i]) {
                s.pop();
                c.push_back('-');
            }
        }
        if(!s.empty() && s.top() == v[i]) {
            s.pop();
            c.push_back('-');
        }
    }
    if(n-1 == N) {
        for(auto item: c) {
            cout<<item<<"\n";
        }
    }
    else {
        cout<<"NO"<<"\n";
    }
    return 0;
}