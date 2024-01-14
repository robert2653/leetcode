// kmp，回傳再判斷
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define int long long
typedef pair<int, int> pii;
typedef struct {
    int from; int to;
    int weight;
} edge;
typedef struct {
    int sum;
} Node;
const int llinf = 4e18;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

class Solution {
public:
struct KMP {
    string sub;
    vector<int> failure;
    KMP(string sub) {
        this->sub = sub;
        failure.resize(sub.size(), -1);
    }
    void buildFailFunction() {
        for(int i = 1; i < sub.size(); i++) {
            int now = failure[i - 1];
            while(now != -1 && sub[now + 1] != sub[i]) now = failure[now];
            if (sub[now + 1] == sub[i]) failure[i] = now + 1;
        }
    }
    vector<int> KMPmatching(string &s) {
        vector<int> ans;
        for(int i = 0, now = -1; i < s.size(); i++) {
            // now is the compare sucessed length -1
            while (s[i] != sub[now + 1] && now != -1) now = failure[now];
            // f stores if comparison fail, move to where
            if (s[i] == sub[now + 1]) now++;
            if (now + 1 == sub.size()) {
                // cout << "found a match start at position " << i - now << "\n";
                ans.push_back(i - now);
                now = failure[now];
            }
        }
        return ans;
    }
};
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        KMP kmpa(a), kmpb(b);
        kmpa.buildFailFunction();
        kmpb.buildFailFunction();
        vector<int> va, vb;
        va = kmpa.KMPmatching(s);
        vb = kmpb.KMPmatching(s);
        vector<int> ans;
        if(vb.size() == 0) return ans;
        for(auto i : va){
            auto it = upper_bound(vb.begin(), vb.end(), i + k);
            int r = --upper_bound(vb.begin(), vb.end(), i + k) - vb.begin();
            int l = lower_bound(vb.begin(), vb.end(), i - k) - vb.begin();
            if(l <= r) ans.push_back(i);
        }
        return ans;
    }
};

void solve(){
    string s, a, b;
    int k;
    cin >> s >> a >> b >> k;
    Solution obj;
    vector<int> ans = obj.beautifulIndices(s, a, b, k);
    for(int i : ans) cout << i << " ";
    cout << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}