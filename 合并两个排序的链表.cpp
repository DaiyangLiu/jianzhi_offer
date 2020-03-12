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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
		//�ݹ鷽��
		if(pHead1==nullptr && pHead2==nullptr) return nullptr;
		if(pHead1==nullptr && pHead2!=nullptr) return pHead2;
		if(pHead1!=nullptr && pHead2==nullptr) return pHead1;
		ListNode * newpHead = nullptr;
		if(pHead1->val <= pHead2->val){
			newpHead = pHead1;
			newpHead->next = Merge(pHead1->next,pHead2);
		}else{
			newpHead = pHead2;
			newpHead->next = Merge(pHead1,pHead2->next);
		}
		return newpHead;	
	} 
	
    ListNode* Merge_origin(ListNode* pHead1, ListNode* pHead2)
    {
        //��ͨ�����������õݹ� 
		if(pHead1==nullptr && pHead2==nullptr) return nullptr;
		if(pHead1==nullptr && pHead2!=nullptr) return pHead2;
		if(pHead1!=nullptr && pHead2==nullptr) return pHead1;
		
		ListNode * newpHead = nullptr;
		ListNode * p = nullptr;
		while(pHead1!=nullptr && pHead2!=nullptr){
			if(newpHead==nullptr){
				if(pHead1->val <= pHead2->val){
					newpHead = pHead1;
					p = newpHead;
					pHead1 = pHead1->next;
				}else{
					newpHead = pHead2;
					p = newpHead;
					pHead2 = pHead2->next;	
				}
				continue;
			}
			
			if(pHead1->val <= pHead2->val){
				p->next = pHead1;
				p = p->next;
				pHead1 = pHead1->next; 
			}else{
				p->next = pHead2;
				p = p->next;
				pHead2 = pHead2->next; 
			}			
		} 
		
		if(pHead1!=nullptr){
			p->next = pHead1;
		}
		
		if(pHead2!=nullptr){
			p->next = pHead2;
		}		
		return newpHead;
    }
};

int main(){
	//����һ������
	int n,m;
    Solution s;
	cout<<"��ֱ���������1������2��Ԫ�ظ�����"; 
	while(cin>>m>>n){
		cout<<"�Զ�����������������������"<<endl; 
		
		ListNode * pHead1=nullptr;
		ListNode * pHead2=nullptr;
		ListNode * p=nullptr;
 
        int startnum=0;
		for(int i =0;i<m;i++){
			startnum += rand()%3;
			if(i == 0){
				pHead1 = new ListNode(startnum);
				p = pHead1;
				continue;
			}
			ListNode * q = new ListNode(startnum);
			p->next = q;
			p = q;
		}
		
		startnum=0;
		for(int i =0;i<n;i++){
			startnum += rand()%3;
			if(i == 0){
				pHead2 = new ListNode(startnum);
				p = pHead2;
				continue;
			}
			ListNode * q = new ListNode(startnum);
			p->next = q;
			p = q;
		}
		
		cout<<"����1��"; 
		p = pHead1;
		while(p!=nullptr){
			cout<<p->val<<" ";
			p = p->next;
		}
		cout<<endl;
		
		cout<<"����2��"; 
		p = pHead2;
		while(p!=nullptr){
			cout<<p->val<<" ";
			p = p->next;
		}
		cout<<endl;
	    
	    
	    ListNode *newpHead = s.Merge(pHead1,pHead2);
	    p = newpHead;
	  	while(p!=nullptr){
			cout<<p->val<<" ";
			p = p->next;
		}
		cout<<endl;
		cout<<endl;
		cout<<"��ֱ���������1������2��Ԫ�ظ�����"; 
	}
	return 0;
}
