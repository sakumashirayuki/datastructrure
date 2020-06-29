
#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* build_tree(vector<string>& v) {
    if (v.empty() || v[0] == "null") return nullptr;
    TreeNode* root = new TreeNode(stoi(v[0])), * cur;
    queue<TreeNode*> q;
    q.push(root);
    int node_num = 0, idx = 0, N = v.size();
    while (!q.empty() && idx < N - 1) {
        node_num = q.size();
        while ((node_num-- > 0) && (idx < N - 1)) {
            cur = q.front(); q.pop();
            if ((++idx < N) && (v[idx] != "null")) {
                cur->left = new TreeNode(stoi(v[idx]));
                q.push(cur->left);
            }
            if ((++idx < N) && (v[idx] != "null")) {
                cur->right = new TreeNode(stoi(v[idx]));
                q.push(cur->right);
            }
        }
    }
    return root;
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

int main() {
    string s;
    vector<string> node_infor;//因数据包含null，因此使用此类型存储节点信息
    cout << "Input node val(leetcode form): ";
    getline(cin, s);
    s.assign(s.begin() + 1, s.end() - 1); //去括号

    int cont = 0;
    for (auto ch = s.begin(); ch != s.end(); ch++) {
        if (*ch != ',') cont++;
        else {
            node_infor.push_back(s.substr(ch - s.begin() - cont, cont));
            cont = 0;
        }
    }//逗号分隔字符串
    if (!s.empty()) {
        node_infor.push_back(s.substr(s.size() - cont, cont));
    }
    TreeNode* root = build_tree(node_infor);
    cout << "Inorder traversal: "; inorder(root);//中序遍历验证

    return 0;
}