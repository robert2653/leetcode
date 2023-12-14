#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // first find an ans
        // use queue
        // r+1 or l+1 or r+1&&l+1
        int ans = 0;
        int sz = nums.size();
        int now = 0;
        queue<pair<unordered_map<int, int>, pair<int, int>>> q;
        unordered_map<int, int> mp;
        while(now < sz){
            mp[nums[now]]++;
            if(mp.size() == k){
                q.push({mp, {0, now}});
                break;
            }
            now++;
        }
        while(!q.empty()){
            ans++;
            unordered_map<int, int> tmp = q.front().first;
            int l = q.front().second.first, r = q.front().second.second;
            while(r < sz - 1){
                r++;
                tmp[nums[r]]++;
                if(tmp.size() == k) q.push({tmp, {l, r}});
                else break;
            }
            tmp = q.front().first;
            l = q.front().second.first, r = q.front().second.second;
            while(true){
                l++;
                tmp[nums[l]]--;
                if(!tmp[nums[l]]) tmp.erase(nums[l]);
                if(tmp.size() == k) q.push({tmp, {l, r}});
                else break;
            }
            q.pop();
        }
        return ans;
    }
};
int main(){
    
}