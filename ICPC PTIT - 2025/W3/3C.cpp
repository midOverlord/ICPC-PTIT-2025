#include <bits/stdc++.h>

using namespace std;

void process(void) {
    string s; cin >> s;
    int k; cin >> k;
    sort(s.begin(), s.end());
    int cur = 0;
    do {
        if(++cur == k) return void(cout << s);
    } while(next_permutation(s.begin(), s.end()));
}

int main(void) {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    process();
    return 0;
}