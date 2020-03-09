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

//1.�ÿ���ָ���Ƿ��������ж��Ƿ��л��������ĵ���ǻ��ڽڵ㣬��ָ��ÿ����һ���� ��ָ��ÿ�������������Ի�ͼ�˽� 
//2.���л����ҳ����нڵ�ĸ�������Ϊһ�����뻷�ڣ������ p = p->next�Ļ�����ʼ�ն��ڻ���ѭ�� 
//3.���û��нڵ�����ҵ���ڽڵ㡣����ָ��ͬʱָ��ͷ�ڵ㣬����һ��ָ�����ߣ�����һ�����нڵ������ľ��룬Ȼ������ָ������ͬ�ٶȼ���ǰ��
//����������ʱ��������ָ�Ľڵ������ڽڵ㡣
//3����ⷽ����һ��ָ�����Ȼ��нڵ������ľ��룬��ζ�ţ�����ָ��պ��ߵ����ڵ���ڵ�λ��ʱ�����ȵ�ָ��Ҳ�պ�ѭ����һ�λ��ı������ڶ���ָ�򻷵���� 

//���ʣ���������л�����ôһ��������β�ڵ�ָ�������е�ĳһ���ڵ���
//������Ϊ�����
 
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
    	if(pHead == nullptr || pHead->next == nullptr) return nullptr; //����û��Ԫ�أ���������ֻ��һ��Ԫ�أ��Ҹ�Ԫ��ָ���ָ�� 
    	if(pHead == pHead->next) return pHead;//����ֻ��һ��Ԫ�أ��Ҹ�Ԫ��ָ�����Լ�
		 
    	//���ˣ���������������Ԫ�� 
    	//���ÿ���ָ��Ѱ�һ��ڽڵ�
		ListNode * nodeinloop = FindNodeInLoop(pHead);
		cout<<"node in loop: "<<nodeinloop->val<<endl;
		if(nodeinloop == nullptr) return nullptr;
		//���û��ڽڵ��ҳ����ڽڵ����� 
		int loopnodenum = CountNodeNum(nodeinloop);
		cout<<"loop node num: "<<loopnodenum<<endl;
		ListNode * entrynode;
		entrynode = FindEntryNode(pHead,loopnodenum);
		return entrynode; 	

    }
    
    ListNode* FindNodeInLoop(ListNode* pHead){
    	//���ÿ���ָ���Ƿ������ж��Ƿ��л��������ĵ���ǻ��ڽڵ�
		ListNode * p1 = pHead;  //��ָ�� 
		ListNode * p2 = pHead;  //��ָ��
		while(p2->next && p2->next->next){
			p1=p1->next;
			p2=p2->next->next;
			if(p1 == p2){
				return p1;
			}
		} 
		return nullptr;
	} 
	
	int CountNodeNum(ListNode * node){
		//���õ�ǰnodeָ�� �Ѿ��ڻ��ڵ�ǰ�ᣬѭ�������ڽڵ�ĸ��� 
		int k=0;
		ListNode * nodecopy = node;
		while(k==0|| nodecopy != node){
			nodecopy = nodecopy->next;
			++k;
		}
		return k;
	}
	
	ListNode * FindEntryNode(ListNode * pHead,int num){
		ListNode * p1 = pHead;  //��ָ�� 
		ListNode * p2 = pHead;  //��ָ��
		while(num--){
			p2=p2->next;
		}
		while(p1!=p2){
			p1=p1->next;
			p2=p2->next;
		}
		return p1;
	} 
};

int main(){
	
	//����һ������ 
	ListNode * pHead=nullptr;
	ListNode * p=nullptr;
	ListNode * entrynode=nullptr;
	for(int i =0;i<6;i++){
		if(i == 0){
			pHead = new ListNode(i+1);
			p = pHead;
			continue;
		}
		ListNode * q = new ListNode(i+1);
		p->next = q;
		p = q;
		if((i+1) == 3){
			entrynode = p;
		} 
		if((i+1) == 6 ){
			p->next = entrynode;
		}
	}
	
	p = pHead;
	int count = 10;
	while(count--){
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
	Solution s;
	ListNode * EntryNode;
	EntryNode = s.EntryNodeOfLoop(pHead);
	cout<<endl<<"EntryNode: "<<EntryNode->val<<endl;
	return 0;
} 
