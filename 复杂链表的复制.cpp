#include <cstdio>
#include <iostream>
#include <map> 
using namespace std; 


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr) return nullptr;
		//复制链表上的节点
		CloneNode(pHead);
		PrintList(pHead);
     	//复制节点的额外连接
		CloneRandomLink(pHead);
		PrintList(pHead);
		//迁移新节点
		RandomListNode* newHead= RemoveNewNode(pHead);
		cout<<"newHead: "<<endl;
		PrintList(newHead);
		cout<<"pHead: "<<endl;
		PrintList(pHead);
		return newHead;
		 
    }
    
    void CloneNode(RandomListNode* pHead){
    	RandomListNode* p = pHead;
    	while(p!=nullptr){
    		RandomListNode* p_copy = new RandomListNode(p->label);
    		p_copy->next = p->next;
    		p->next = p_copy;
    		p=p_copy->next; 
        }
        return;
	}
	
	void CloneRandomLink(RandomListNode* pHead){
		RandomListNode* p = pHead;
		RandomListNode* p_copy = pHead->next;
		while(p!=nullptr&&p_copy!=nullptr){
			if(p->random!=nullptr){
				p_copy->random = p->random->next;
			}
			p = p_copy->next;
			if(p!=nullptr){
				p_copy = p->next;
			}else{
				p_copy = nullptr;
			}
		}
		return;
	}
	
	RandomListNode* RemoveNewNode(RandomListNode* pHead){
		RandomListNode* newHead = nullptr;
		RandomListNode* newp = nullptr;
		
		RandomListNode* p = pHead;
		RandomListNode* p_copy = pHead->next;
		
		while(p!=nullptr&&p_copy!=nullptr){
			cout<<p->label<<" "<<p_copy->label<<endl;
			if(newHead == nullptr){
				newHead = p_copy;
				newp = newHead;
				p->next = p_copy->next;
			}else{
				newp->next = p_copy;
			    newp = newp->next;	
				p->next = p_copy->next;	
			}
			
			p = p_copy->next;
			if(p!=nullptr){
				p_copy = p->next;
			}else{
				p_copy = nullptr;
			}
		}
		
		return newHead;
	}
	
	void PrintList(RandomListNode* pHead){
		////------------链表检验------------------------ 
        RandomListNode* p = pHead;
        while(p!=nullptr){
	        cout<<p->label<<" ";
			p=p->next;
		}
		cout<<endl;
		p = pHead;
		while(p!=nullptr){
			if(p->random!=nullptr){
			    cout<<p->random->label<<" ";	
			}else{
				cout<<"  ";	
			}
			p=p->next;
		}
		cout<<endl;
		 ////------------链表检验------------------------ 
			
	}
};

int main(){
	//创建一个复杂链表
	RandomListNode * phead=nullptr;
	RandomListNode * p=nullptr;
	map<RandomListNode*, RandomListNode*> nmap;
	
	for(int i = 1;i<6;i++){
		RandomListNode * node = new RandomListNode(i);
		if(phead ==nullptr){
			phead = node;
			p=phead;
			continue;
		}
		p->next = node;
		p = p->next;
	}
	//建立复杂链表的额外连接
	//1--3
	RandomListNode * a=phead;
	p = phead;
	while(p!=nullptr){
		if(p->label == 3){
			a->random = p;
			break;
		}
		p=p->next;
	} 
	
	//2--5
	RandomListNode * b=phead->next;
	p = phead;
	while(p!=nullptr){
		if(p->label == 5){
			b->random = p;
			break;
		}
		p=p->next;
	} 
	//4--2 
	RandomListNode * c=phead->next->next->next;
	p = phead;
	while(p!=nullptr){
		if(p->label == 2){
			c->random = p;
			break;
		}
		p=p->next;
	} 
	
	
	
	p = phead;
	while(p!=nullptr){
		cout<<p->label<<" ";
		p=p->next;
	}
	cout<<endl;
	
	p = phead;
	while(p!=nullptr){
		if(p->random!=nullptr){
		    cout<<p->random->label<<" ";	
		}else{
			cout<<"  ";	
		}
		p=p->next;
	}
	cout<<endl;
	 
	 
	Solution s;
	s.Clone(phead);
	return 0;
}
