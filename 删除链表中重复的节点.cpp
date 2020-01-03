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
		//��pre ��cur֮������һ��Ϊ����һ����preָ��Ľڵ���ֵ��cur��ȣ�һ����preָ��Ľڵ���ֵ��cur����� 
		if (pHead == nullptr || pHead->next == nullptr) return pHead;
		ListNode* pPre = pHead, *pCur = pHead->next;

		while (pCur) {
			if (pCur->next == nullptr) {
				if (pPre->val == pCur->val) {
					//˵��Ŀǰǰ�������ڵ㶼����ȵ�
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
					//˵��pre�Ѿ�ָ����һ���������ظ��ڵ�,pre��Ľڵ�ֱ��cur��������ȵ�
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
				if (pCur->next->val != pCur->val) {//cur ��һ���ڵ���ֵ��cur�����
					if (pPre->val == pCur->val) {
						//˵��Ŀǰǰ�������ڵ㶼����ȵ�
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
						//˵��pre�Ѿ�ָ����һ���������ظ��ڵ�,pre��Ľڵ�ֱ��cur��������ȵ�
						pPre->next = pCur->next;
						pCur = pCur->next;
						ListNode * tmp = pPre->next;
						while (tmp != pCur) {
							ListNode* tobedeleted = tmp;
							tmp = tmp->next;
							delete tobedeleted;
						}
					}else if(pPre->next == pCur){
						//˵��pre��curָ�����ڣ���������ָ��һ��ǰ��
						pPre = pCur;
						pCur = pCur->next;
					}
				}
				else if (pCur->next->val == pCur->val) {//cur ��һ���ڵ���ֵ��cur���
					pCur = pCur->next;
				}
			}
			
		}

		return pHead;

	}
	
    ListNode* deleteDuplication_headnode(ListNode* pHead)
    {
    	//��δ����Ƕ������������˴�������Ϊ��һ���������ͷ��㣬�����û���������ͷ���ġ� 
    	if(pHead == nullptr ||pHead->next==nullptr) return pHead;
    	ListNode* pPre=pHead, *pCur=pHead->next;
		//preָ��ָ����ֵ������ȵ�һ����ֵ��ǰһ���ڵ� 
		//curָ��ָ��ǰ���ڷ��ʵĽڵ� 
		
		while(pCur){
			if(pCur->next == nullptr){//�����ǰ�ڵ����һ���ڵ��ǿ� 
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
			//�����ǰ�ڵ����һ���ڵ㲻Ϊ�� 
			}else if(pCur->val == pCur->next->val){//�����ǰ�ڵ��ֵ����һ���ڵ��ֵ��� 
				pCur = pCur->next;//�����ǰ�� 
			//�����ǰ�ڵ��ֵ����һ���ڵ��ֵ�����	
			}else if(pPre->next != pCur){  //��preָ���curָ�벻���ڣ�
			//˵������֮�����������ȵģ���curҲ�����������ֵ�� 
				pCur = pCur->next;//���Դ�ʱcurǰ��һ������������ȵĵ�һ���� 
				ListNode *tmp = pPre->next,*toBeDeleted=tmp;
				while(tmp!=pCur){//��pre��cur֮����������ֽ���ɾ�� 
					toBeDeleted = tmp;
					tmp = tmp->next;
					delete toBeDeleted;
				}
				pPre->next = pCur;
			}else if(pPre->next == pCur){//�����ǰ�ڵ�����һ���ڵ����ֵ�����
			//��pre�ڵ��cur�ڵ������ڵģ����Խ�������ָ��һ���ƶ� 
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
