#include <bits/stdc++.h>
using namespace std;
#define int long long
// 求樹上最大路徑，分數是經過點的總和
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int ans = -2e9;
    int maxPathSum(TreeNode* root) {
        return max(ans, dfs(root));
    }
    int dfs(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = max(0LL, dfs(root->left));   // max(0, 左子樹答案);
        int right = max(0LL, dfs(root->right)); // max(0, 右子樹答案);
        ans = max(ans, root->val + left + right);   // 左父右連起來
        return root->val + max(left, right);    // 回傳父+max(左, 右);
    }
};
void link(TreeNode *root, vector<int> &v, int now, int nowdeep, int deep){
    if(root == nullptr) return;
    if(nowdeep == deep){
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    root->left = v[now * 2 + 1] == 1e9 ? nullptr : new TreeNode(v[now * 2 + 1]);
    root->right = v[now * 2 + 2] == 1e9 ? nullptr : new TreeNode(v[now * 2 + 2]);
    link(root->left, v, now * 2 + 1, nowdeep + 1, deep);
    link(root->right, v, now * 2 + 2, nowdeep + 1, deep);
}
signed main(){
    int n; cin >> n;    // 有幾層
    cin.ignore();
    vector<int> v((int)pow(2, n) - 1);
    for(int i = 0; i < (int)pow(2, n) - 1; i++){
        string s;
        getline(cin, s);
        if(s == ""){
            v[i] = 1e9;
        }
        else v[i] = stoll(s);
    }
    TreeNode root(v[0]);
    link(&root, v, 0, 1, n);
    Solution s;
    cout << s.maxPathSum(&root) << "\n";
}