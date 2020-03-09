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

//1.用快慢指针是否相遇来判断是否有环，相遇的点就是环内节点，慢指针每次走一步， 快指针每次走两步，可以画图了解 
//2.若有环则找出环中节点的个数，因为一旦进入环内，则采用 p = p->next的话，会始终都在环内循环 
//3.利用环中节点个数找到入口节点。两个指针同时指向头节点，其中一个指针先走，领先一个环中节点总数的距离，然后两个指针以相同速度继续前进
//当它们相遇时，它们所指的节点就是入口节点。
//3的理解方法：一个指针领先环中节点总数的距离，意味着，落后的指针刚好走到环节点入口的位置时，领先的指针也刚好循环完一次环的遍历，第二次指向环的入口 

//疑问：这个链表有环，那么一定是它的尾节点指向链表中的某一个节点吗
//姑且认为这个是
 
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
    	if(pHead == nullptr || pHead->next == nullptr) return nullptr; //链表没有元素，或者链表只有一个元素，且该元素指向空指针 
    	if(pHead == pHead->next) return pHead;//链表只有一个元素，且该元素指向它自己
		 
    	//至此，链表至少有两个元素 
    	//利用快慢指针寻找环内节点
		ListNode * nodeinloop = FindNodeInLoop(pHead);
		cout<<"node in loop: "<<nodeinloop->val<<endl;
		if(nodeinloop == nullptr) return nullptr;
		//利用环内节点找出环内节点数量 
		int loopnodenum = CountNodeNum(nodeinloop);
		cout<<"loop node num: "<<loopnodenum<<endl;
		ListNode * entrynode;
		entrynode = FindEntryNode(pHead,loopnodenum);
		return entrynode; 	

    }
    
    ListNode* FindNodeInLoop(ListNode* pHead){
    	//利用快慢指针是否相遇判断是否有环，相遇的点就是环内节点
		ListNode * p1 = pHead;  //慢指针 
		ListNode * p2 = pHead;  //快指针
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
		//利用当前node指针 已经在环内的前提，循环出环内节点的个数 
		int k=0;
		ListNode * nodecopy = node;
		while(k==0|| nodecopy != node){
			nodecopy = nodecopy->next;
			++k;
		}
		return k;
	}
	
	ListNode * FindEntryNode(ListNode * pHead,int num){
		ListNode * p1 = pHead;  //慢指针 
		ListNode * p2 = pHead;  //快指针
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
	
	//创建一个链表 
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
