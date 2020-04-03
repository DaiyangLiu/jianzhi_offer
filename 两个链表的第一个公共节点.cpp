#include <cstdio>
#include <iostream>
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode * tmp1 = pHead1 , *ph1 = pHead1;
        ListNode * tmp2 = pHead2 , *ph2 = pHead2;
        int num1=0,num2=0;
        while(tmp1!=nullptr){
        	num1++;
        	tmp1 = tmp1->next;
		}
		while(tmp2!=nullptr){
			num2++;
			tmp2 = tmp2->next;
		}
		if(num1>num2){
			int step = num1-num2;
			while(step){
				step--;
				ph1=ph1->next;
			}
		}else if(num1<num2){
			int step = num2-num1;
			while(step){
				step--;
				ph2=ph2->next;
			}
		}
		
		while(ph1!=ph2){
			ph1=ph1->next;
			ph2=ph2->next;
		}
    }
};

int main(){
	return 0;
} 
