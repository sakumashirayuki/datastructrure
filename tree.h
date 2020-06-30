#ifndef  TREE_H
#define TREE_H

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#define MaxNode 100

using namespace std;

//definition of binary tree node
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//��˳��洢vector����������
TreeNode* createBLink(vector<int>& v)
{
	if (v.empty()) return nullptr;
	TreeNode *root = new TreeNode(v[0]);
	TreeNode *cur;
	queue<TreeNode*> q;
	q.push(root);
	int idx = 0;
	int N = v.size();
	while (!q.empty() && idx < N - 1)
	{
		cur = q.front();
		q.pop();
		if ((++idx < N) && (v[idx] != NULL))
		{
			cur->left = new TreeNode(v[idx]);
			q.push(cur->left);
		}
		if ((++idx < N) && (v[idx] != NULL))
		{
			cur->right = new TreeNode(v[idx]);
			q.push(cur->right);
		}
	}
	return root;
}
//��ת������
TreeNode* invertTree(TreeNode* root) {
	if (root == nullptr)
		return nullptr;
	TreeNode* left = invertTree(root->left);
	TreeNode* right = invertTree(root->right);
	root->left = right;
	root->right = left;
	return root;
}
//�ݹ��������
void preorderRecur(TreeNode* root)
{
	if (root == nullptr) return;
	cout << root->val << " ";
	preorderRecur(root->left);
	preorderRecur(root->right);
}

//�ݹ��������
void inorderRecur(TreeNode* root)
{
	if (root == nullptr) return;
	inorderRecur(root->left);
	cout << root->val << " ";
	inorderRecur(root->right);
}

//�ݹ�������
void postorderRecur(TreeNode* root)
{
	if (root == nullptr) return;
	postorderRecur(root->left);
	postorderRecur(root->right);
	cout << root->val << " ";
}
//�ǵݹ��������
void preorderNonRecur(TreeNode* root)
{
	TreeNode* T = root;
	stack<TreeNode*> s;
	while (T != nullptr || !s.empty())
	{
		while (T != nullptr)
		{
			cout << T->val << " ";
			s.push(T);
			T = T->left;
		}
		T = s.top();
		s.pop();
		T = T->right;
	}
}
//�ǵݹ��������
void inorderNonRecur(TreeNode* root)
{
	TreeNode* T = root;
	stack<TreeNode*> s;
	while (T != nullptr || !s.empty())
	{
		while (T != nullptr)
		{
			s.push(T);
			T = T->left;
		}
		T = s.top();
		s.pop();
		cout << T->val << " ";
		T = T->right;
	}
}
//�ǵݹ�������
void postorderNonRecur(TreeNode* root) {
	TreeNode* invertRoot = invertTree(root);
	TreeNode* T = invertRoot;
	stack<TreeNode*> s;
	stack<int> sout;
	while (T != nullptr || !s.empty())
	{
		while (T != nullptr)
		{
			sout.push(T->val);
			s.push(T);
			T = T->left;
		}
		T = s.top();
		s.pop();
		T = T->right;
	}
	while (!sout.empty())
	{
		cout << sout.top() << " ";
		sout.pop();
	}
}
#endif //  TREE_H
