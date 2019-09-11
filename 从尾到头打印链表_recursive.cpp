#include <cstdio>
#include <iostream>
#include <stack>
#include <sstream> 
#include <string>
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
    void printListFromTailToHead(ListNode* head) {
    	//如何处理输入为空指针？？
	   if(head==nullptr){
	   	return;
	   } 
       if(head->next!=NULL){
       	printListFromTailToHead(head->next);
	   } 
	   printf("%d ",head->val);
	   return;
	   
    }
};

int main(){
	ListNode* p, *head, *q;
	string str;
	int num;
	Solution s;
	head=NULL;
    s.printListFromTailToHead(head);
	
//	while(getline(cin,str)){
//		stringstream ss(str); 
//		int first=1;
//		while(ss>>num){
//			printf("%d\n",num);
//			if(first == 1){
//				p=new ListNode(num);
//                head=p;
//				first=0;
//			}else{
//                q=new ListNode(num); 
//			    p->next=q;
//			    p=p->next;
//			}	
//		}
//		
//		ListNode* t=head;
//		while(t){
//			printf("%d ",t->val);
//			t=t->next;
//		}
//		
//		printf("\n-------result-----------\n");
//		Solution s;
//        s.printListFromTailToHead(head);
//
//		printf("\n");
//	}
	
	
	
	return 0;
}
