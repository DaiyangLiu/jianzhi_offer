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
        if(!queue1.empty()){//queue1�����������ֵģ���ʱqueue2��϶�û������ 
        	while(queue1.size()>1){
        		data = queue1.front();
        		queue1.pop();
        		queue2.push(data);
			}
			data=queue1.front();
			queue1.pop();
			return data;
		}else if(!queue2.empty()){//queue2�����������ֵģ���ʱqueue1��϶�û������ 
			while(queue2.size()>1){
        		data = queue2.front();
        		queue2.pop();
        		queue1.push(data);
			}
			data=queue2.front();
			queue2.pop();
			return data;
		}else{//���ǿ� 
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
