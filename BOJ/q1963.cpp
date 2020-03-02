#include<bits/stdc++.h>
#define MAX 10000
using namespace std;
bool primes[MAX];
void prime() {
    for(int i=0;i<MAX;i++) primes[i] = true;
    primes[0] = primes[1] = false;
    for(int i=2;i<100;i++) {
        for(int j=2;j*i<MAX;j++) {
            primes[i*j] = false;
        }
    }
}
int change(int n,int i,int j){
    int k=n;
    if(i==0){
        k-=(n/1000)*1000;
        k+=j*1000;
    }else if(i==1){
        k-=((n/100)%10)*100;
        k+=j*100;
    }else if(i==2){
        k-=((n%100)/10)*10;
        k+=j*10;
    }else if(i==3){
        k-=n%10;
        k+=j;
    }   
    return k;
}
int bfs(int A, int B) {
    bool visited[MAX] = {false,};
    queue<pair<int,int>> q;
    q.push({A,0});
    visited[A] = true;
    while(!q.empty()) {
        pair<int,int> p = q.front();
        q.pop();
        if(p.first == B) {
            return p.second;
        }
        for(int i=0;i<4;i++) {
            for(int j=0;j<10;j++) {
                int n = change(p.first,i,j);
                if(1000 < n && !visited[n] && primes[n]) {
                    visited[n] = true;
                    q.push({n,p.second+1});
                }
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(false);
    prime();
    int T;
    cin>>T;
    for(int t=0;t<T;t++) {
        int A, B;
        cin>>A>>B;
        int cnt = bfs(A,B);
        if(0 <= cnt) {
            cout<<cnt<<"\n";
        }
        else {
            cout<<"Impossible"<<"\n";
        }
    }
    return 0;
}