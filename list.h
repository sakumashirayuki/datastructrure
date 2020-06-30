#ifndef LIST_H
#define LIST_H

#include<iostream>
#include<vector>

using namespace std;

//Definition for singly - linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

//链表的head为第一个节点
ListNode* createList(vector<int>& v)
{
	ListNode* head = new ListNode(v[0]);
	ListNode* cur = head;
	int N = v.size();
	for (int i = 1; i < N; i++)
	{
		ListNode* temp = new ListNode(v[i]);
		cur->next = temp;
		cur = temp;
	}
	return head;
}

void printList(ListNode* head)
{
	ListNode* cur = head;
	while (cur)
	{
		cout << cur->val << " ";
		cur = cur->next;
	}
}

#endif // !LIST_H

