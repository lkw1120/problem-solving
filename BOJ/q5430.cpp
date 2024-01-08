#include<bits/stdc++.h>
using namespace std;
string ac,input;
int T,N;
vector<string> split(string str, char ch) {
    istringstream iss(str);
    string buf;
    vector<string> res;
    while (getline(iss, buf, ch)) {
        res.push_back(buf);
    }
    return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--) {
		cin>>ac;
		cin>>N;
		cin>>input;
		deque<string> dq;
		bool flag = true;
		if(!N && ac.find("D") != std::string::npos) {
			flag = false;
		}
		else {
			string str = input.substr(1,input.size()-2);
			for(auto item: split(str,',')) {
				dq.push_back(item);
			}
			bool flip = false;
			for(int i=0;i<ac.size();i++) {
				if(ac[i] == 'R') {
					flip = !flip;
				}
				else {
					if(dq.size()) {
						if(flip) {
							dq.pop_back();
						}
						else {
							dq.pop_front();	
						}
					}
					else {
						flag = false;
						break;
					}
				}
			}
			if(flip) {
				reverse(dq.begin(),dq.end());
			}
		}
		if(flag) {
			cout<<"[";
			for(int i=0;i<dq.size();i++) {
				cout<<dq[i];
				if(i < dq.size()-1) {
					cout<<",";	
				}
			}
			cout<<"]"<<"\n";
		}
		else {
			cout<<"error"<<"\n";	
		}
	}
	return 0;
}