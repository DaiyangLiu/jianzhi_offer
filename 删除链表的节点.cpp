#include <cstdio>
#include <iostream>
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
    void deleteNode(ListNode* pHead, ListNode* ToBeDeleted){ 
    	//��O(1)ʱ����ɾ������Ľڵ� 
    	//1.������ 
    	if(pHead==nullptr) return;
		//2.ֻ��һ���ڵ������ 
		if(pHead->next == nullptr){
			//ɾ���ýڵ� 
			delete ToBeDeleted;
			return;
		} 
		//3.����ڵ���ڵ���2
		//3.1.Ҫɾ���Ľڵ㲻��β�ڵ� 
		if(ToBeDeleted->next != nullptr){
			ListNode* NextNode = ToBeDeleted->next;
			ToBeDeleted->val = NextNode->val;
			ToBeDeleted->next = NextNode->next;
			delete NextNode;
			
		}else{// 3.2.Ҫɾ���Ľڵ���β�ڵ�
			ListNode * FrontNode = pHead;
			while(FrontNode->next != ToBeDeleted){
				FrontNode = FrontNode->next;
			}
			FrontNode->next=ToBeDeleted->next;
			delete ToBeDeleted;
		}
		 return;
    }
};


int main(){
	
		
	ListNode  *Head,*tail;
	//ListNode  *tail;
	int n,first_flag = 1;
	while( cin>> n){
		ListNode  *new_node= new ListNode(n);
		if(first_flag == 1){
			Head = new_node;
			tail = Head;
			first_flag = 0;
			continue;			
		}
		tail->next = new_node;
		tail = new_node;		
	}
	
	
	ListNode *p = Head;
	while(p){
		cout<<p->val<<" ";
		p = p->next;
	} 
	cout<<endl;
	
	p = Head;
	int deleted_number = 2;//Ҫɾ���������еĵ�N��Ԫ�� 
	for(int i = 0; i<deleted_number;i++ ){
		p=p->next;
	} 
	cout<<"p->val = "<<p->val<<endl;
	Solution s;
	s.deleteNode(Head, p);
	p = Head;
	while(p){
		cout<<p->val<<" ";
		p = p->next;
	} 
	cout<<endl;
	
	
	
	return 0;
}
