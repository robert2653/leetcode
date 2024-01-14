// 水
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
    int maxFrequencyElements(vector<int>& nums) {
        int mx = 0;
        map<int, int> mp;
        for(auto i : nums){
            mp[i]++;
            mx = max(mx, mp[i]);
        }
        int ans = 0;
        for(auto [i, j] : mp){
            if(j == mx) ans += j;
        }
        return ans;
    }
};

void solve(){

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}