#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;
 
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
    	//�����Ϊ����ô pop�� 
    	int temp;		
		if(stack2.empty()){
			while(!stack1.empty()){
				temp=stack1.top();
				stack1.pop();
				stack2.push(temp);
			}
		}
		if(!stack2.empty()){
			 temp = stack2.top();
	        stack2.pop();
	        return temp;
		}else{
			return -10000;
		}	
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
	//�� 
	return 0;
}
