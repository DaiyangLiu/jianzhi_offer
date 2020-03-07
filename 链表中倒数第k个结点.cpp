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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	if(pListHead == nullptr) return nullptr;
    	if(k<=0) return nullptr;
		ListNode* front = pListHead;
		for(int i = 2; i<=k;i++){
			cout<<"i: " << i<<endl; 
			front = front->next;
			if(front == nullptr) return nullptr;
		} 
		cout<<"front:"<<front->val<<endl;
		ListNode* back = pListHead;
		while(front->next!=nullptr){
			back=back->next;
			front = front->next;
		}
		return back;
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
		cout<<endl<<"请输入想要找到的倒数第几个数(-1退出本次寻找)：";
		int num;
		while(cin>>num){
			if(num==-1) break; 
			int k = num;
			ListNode *find = s.FindKthToTail(pHead,k);
			if(find == nullptr){
				cout<<"find == nullptr"<<endl;
				cout<<"请输入想要找到的倒数第几个数(-1退出本次寻找)：";
				continue;
			}
			cout<<"找到： "<<find->val<<endl;
			cout<<"请输入想要找到的倒数第几个数(-1退出本次寻找)：";
		} 
		
        
		cout<<endl;
		cout<<"请输入链表元素个数："; 
	}
	
	
	return 0;
}
