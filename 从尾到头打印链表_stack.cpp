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
    vector<int> printListFromTailToHead(ListNode* head) {
        stack<ListNode*>  nodes;
        vector<int> arraylist;
        if(head==nullptr){
        	return arraylist;
		}else if(head->next==NULL){
			arraylist.push_back(head->val);
			return arraylist;
		}
		ListNode* p=head;
		while(p!=NULL){
			nodes.push(p);
			p=p->next;

		}
		
		while(!nodes.empty()){
			p = nodes.top();
			arraylist.push_back(p->val);
			nodes.pop();
		}
        return arraylist;
    }
};

int main(){
	ListNode* p, *head, *q;
	string str;
	int num;
	
	while(getline(cin,str)){
		stringstream ss(str); 
		int first=1;
		while(ss>>num){
			printf("%d\n",num);
			if(first == 1){
				p=new ListNode(num);
                head=p;
				first=0;
			}else{
                q=new ListNode(num); 
			    p->next=q;
			    p=p->next;
			}	
		}
		
		ListNode* t=head;
		while(t){
			printf("%d ",t->val);
			t=t->next;
		}
		
		printf("\n-------result-----------\n");
		Solution s;
		vector<int> result;
		result = s.printListFromTailToHead(head);
		vector<int>::iterator iter;
		for(iter=result.begin(); iter!=result.end();iter++){
			printf("%d ",*iter);
		}
		printf("\n");
	}
	
	
	
	return 0;
}
