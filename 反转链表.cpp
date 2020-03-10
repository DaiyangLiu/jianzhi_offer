#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
    	ListNode * p=nullptr;
    	ListNode * right=nullptr;
    	ListNode * left=nullptr;
    	if(pHead == nullptr) return nullptr;
    	if(pHead->next == nullptr) return pHead;
    	
    	right = pHead;
    	while(right != nullptr){
    		p = right;
    		right = p->next;
    		p->next = left;
    		left = p;
		}
    	
        return p;
    }
};

int main(){
	//创建一个链表
	int n;
    Solution s;
	cout<<"请输入链表元素个数："; 
	while(cin>>n){
		ListNode * pHead=nullptr;
		ListNode * p=nullptr;
 
		for(int i =0;i<n;i++){
			if(i == 0){
				pHead = new ListNode(i+1);
				p = pHead;
				continue;
			}
			ListNode * q = new ListNode(i+1);
			p->next = q;
			p = q;
		}
		
		p = pHead;
		while(p!=nullptr){
			cout<<p->val<<" ";
			p = p->next;
		}
		cout<<endl;
		cout<<"反转后结果："<<endl; 
		p = s.ReverseList(pHead);
		while(p!=nullptr){
			cout<<p->val<<" ";
			p = p->next;
		}
		cout<<endl;
		cout<<"请输入链表元素个数："; 
	}
	
	return 0;
} 
