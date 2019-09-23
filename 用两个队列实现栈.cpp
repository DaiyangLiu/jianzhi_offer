#include <cstdio>
#include <iostream>
#include <stack>
#include <queue> 
using namespace std;
 
class Solution
{
public:
    void push(int node) {
      if(queue1.empty()&&queue2.empty()){
      	queue1.push(node);
	  }else if(queue1.empty() && !queue2.empty()){
	  	queue2.push(node);
	  }else{
	  	queue1.push(node);
	  }
    }

    int pop() {
        int data;
        if(!queue1.empty()){//queue1里面是有数字的，此时queue2里肯定没有数字 
        	while(queue1.size()>1){
        		data = queue1.front();
        		queue1.pop();
        		queue2.push(data);
			}
			data=queue1.front();
			queue1.pop();
			return data;
		}else if(!queue2.empty()){//queue2里面是有数字的，此时queue1里肯定没有数字 
			while(queue2.size()>1){
        		data = queue2.front();
        		queue2.pop();
        		queue1.push(data);
			}
			data=queue2.front();
			queue2.pop();
			return data;
		}else{//都是空 
			return -10000; 
		} 
    }

private:
    queue<int> queue1;
    queue<int> queue2;
};

int main(){
	Solution s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout<< s.pop()<<endl;
	s.push(5);
	s.push(6);
	cout<< s.pop()<<endl;
	return 0;
}
