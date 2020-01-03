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
	
	ListNode* deleteDuplication(ListNode* pHead)
	{
		//将pre 和cur之间的情况一分为二，一个是pre指向的节点数值与cur相等，一个是pre指向的节点数值与cur不相等 
		if (pHead == nullptr || pHead->next == nullptr) return pHead;
		ListNode* pPre = pHead, *pCur = pHead->next;

		while (pCur) {
			if (pCur->next == nullptr) {
				if (pPre->val == pCur->val) {
					//说明目前前面的链表节点都是相等的
					pHead = nullptr;
					ListNode * tmp = pPre;
					while (tmp ) {
						ListNode* tobedeleted = tmp;
						tmp = tmp->next;
						delete tobedeleted;
					}
					break;
				}
				else if(pPre->val != pCur->val &&  pPre->next != pCur  &&(pPre->next->val == pCur->val)){
					//说明pre已经指向了一个独立不重复节点,pre后的节点直到cur，都是相等的
					pPre->next = pCur->next;
					pCur = pCur->next;
					ListNode * tmp = pPre->next;
					while (tmp != pCur) {
						ListNode* tobedeleted = tmp;
						tmp = tmp->next;
						delete tobedeleted;
					}
					break;
				}
				else{
					break;
				}

			}
			else {
				if (pCur->next->val != pCur->val) {//cur 后一个节点数值与cur不相等
					if (pPre->val == pCur->val) {
						//说明目前前面的链表节点都是相等的
						pHead = pCur->next;
						pPre = pHead;
						ListNode * tmp = pPre;
						while (tmp != pPre) {
							ListNode* tobedeleted = tmp;
							tmp = tmp->next;
							delete tobedeleted;
						}
						pCur = pHead->next;
					}
					else if(pPre->val != pCur->val && pPre->next != pCur  &&(pPre->next->val == pCur->val)) {
						//说明pre已经指向了一个独立不重复节点,pre后的节点直到cur，都是相等的
						pPre->next = pCur->next;
						pCur = pCur->next;
						ListNode * tmp = pPre->next;
						while (tmp != pCur) {
							ListNode* tobedeleted = tmp;
							tmp = tmp->next;
							delete tobedeleted;
						}
					}else if(pPre->next == pCur){
						//说明pre和cur指针相邻，进而两个指针一起前进
						pPre = pCur;
						pCur = pCur->next;
					}
				}
				else if (pCur->next->val == pCur->val) {//cur 后一个节点数值与cur相等
					pCur = pCur->next;
				}
			}
			
		}

		return pHead;

	}
	
    ListNode* deleteDuplication_headnode(ListNode* pHead)
    {
    	//这段代码是对题意理解产生了错误，我以为有一个无意义的头结点，结果是没有无意义的头结点的。 
    	if(pHead == nullptr ||pHead->next==nullptr) return pHead;
    	ListNode* pPre=pHead, *pCur=pHead->next;
		//pre指针指向数值连续相等的一串数值的前一个节点 
		//cur指针指向当前正在访问的节点 
		
		while(pCur){
			if(pCur->next == nullptr){//如果当前节点的下一个节点是空 
				if((pPre->next != pCur) && (pPre->next->val == pCur->val)){
					ListNode *tmp = pPre->next,*toBeDeleted=tmp;
					while(tmp){
						toBeDeleted = tmp;
						tmp = tmp->next;
						delete toBeDeleted;
					}	
					pPre->next = nullptr;
					break;
				}else{
				    if(pPre->next != pCur){
				    	pPre->next = pCur;
					}
					break;
				}
			//如果当前节点的下一个节点不为空 
			}else if(pCur->val == pCur->next->val){//如果当前节点的值与下一个节点的值相等 
				pCur = pCur->next;//则继续前进 
			//如果当前节点的值与下一个节点的值不相等	
			}else if(pPre->next != pCur){  //且pre指针和cur指针不相邻，
			//说明他们之间的数字是相等的，且cur也包括在相等数值内 
				pCur = pCur->next;//所以此时cur前进一步，跳到不相等的第一个数 
				ListNode *tmp = pPre->next,*toBeDeleted=tmp;
				while(tmp!=pCur){//对pre和cur之间的连续数字进行删除 
					toBeDeleted = tmp;
					tmp = tmp->next;
					delete toBeDeleted;
				}
				pPre->next = pCur;
			}else if(pPre->next == pCur){//如果当前节点与下一个节点的数值不相等
			//且pre节点和cur节点是相邻的，所以将这两个指针一起移动 
				pPre = pCur;
			    pCur = pCur->next;
			}	
		}
		 return pHead;
    	
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
		
	Solution s;
	s.deleteDuplication(Head);
	p = Head;
	while(p){
		cout<<p->val<<" ";
		p = p->next;
	} 
	cout<<endl;
	
	
	return 0;
}
