#include <bits/stdc++.h>
using namespace std;

// 題意: 找出所有子序列，有 k 個不同數，的子序列個數
// 使用 sliding window
// l ~ r 紀錄 右端點是 r 的最大可行子序列
// m ~ r 紀錄 右端點是 m 的最大可行子序列
// ans += m - l + 1;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = 0;
        int sz = nums.size();
        map<int, int> mp_for_l_to_r, mp_for_m_to_r;
        int l = 0, m = 0, r = -1;
        while(r < sz - 1){
            r++;
            mp_for_l_to_r[nums[r]]++;
            mp_for_m_to_r[nums[r]]++;
            // 把 l 做到符合 k 就結束
            while(mp_for_l_to_r.size() > k){
                mp_for_l_to_r[nums[l]]--;
                if(mp_for_l_to_r[nums[l]] == 0) mp_for_l_to_r.erase(nums[l]);
                l++;
            }
            // 把 m 做到符合 k 並且要最小化它
            while(mp_for_m_to_r.size() > k || (mp_for_m_to_r.size() == k && mp_for_m_to_r[nums[m]] != 1)){
                mp_for_m_to_r[nums[m]]--;
                if(mp_for_m_to_r[nums[m]] == 0) mp_for_m_to_r.erase(nums[m]);
                m++;
            }
            if(mp_for_l_to_r.size() == k){ // 特判 ans == 0 的測資
                ans += (m - l + 1);
                // cout << l << " " << m << " " << r << endl;
            }
        }
        return ans;
    }
};
int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        int k; cin >> k;
        Solution x;
        cout << x.subarraysWithKDistinct(v, k) << "\n";
    }
}