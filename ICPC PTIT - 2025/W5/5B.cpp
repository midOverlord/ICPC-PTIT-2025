#include <bits/stdc++.h>

using namespace std;

#define  MAXN  1003

void process(void) {
    string s; cin >> s;
    int pos_star = -1;
    for(int i = 0; i < s.size(); i++) if(s[i] == '*') pos_star = i;
    stack<int> st;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++) {
        if(i == pos_star) continue;
        if(s[i] == '(') st.push(i);
        else if(st.size()) {
            if(st.top() < pos_star && pos_star < i) cnt++;
            st.pop();
        }
    }
    cout << cnt << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T; while(T--) process();
    return 0;
}