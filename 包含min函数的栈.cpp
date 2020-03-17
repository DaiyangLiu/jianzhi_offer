#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

 
class Solution {
public:
	stack<int> data_stack,min_stack;
	
    void push(int value) {
        data_stack.push(value);
        if(!min_stack.empty()){
        	int min_now = min_stack.top();
        	if(value< min_now){
        		min_stack.push(value);
			}else{
				min_stack.push(min_now);
			}
		}else{
			min_stack.push(value);
		}
		
    }
    void pop() {
    	if(!data_stack.empty()){
    		data_stack.pop();
            min_stack.pop();
		}   
	}
    int top() {
    	if(!data_stack.empty()){
    		return data_stack.top();
		}else{
			return -9999;
		}
    }
    int min() {
    	if(!min_stack.empty()){
    		return min_stack.top();
		}else{
			return -9999;
		}
    }
    
    

};

int main(){
	Solution s;
	cout<<"���룺c + x"<<endl;
	cout<<"�鿴ջ����t"<<endl;
	cout<<"����ջ����p"<<endl;
	cout<<"�鿴��Сֵ��m"<<endl;
	cout<<"�˳���e"<<endl;
	
	char command;
	int end_flag=0;
	cout<<"���������"; 
	while(cin>>command && !end_flag){
		int new_num;
		switch(command){
			case 'c':
				cin>>new_num;
				cout<<"���� "<<new_num<<endl; 
				s.push(new_num);
				cout<<"���������"; 
				break;
			case 't':
				cout<<"ջ��Ԫ�أ�"<<s.top()<<endl; 
				cout<<"���������"; 
				break;
			case 'p':
				cout<<"����ջ����"<<endl;
				s.pop(); 
				cout<<"���������"; 
				break;
			case 'm':
				cout<<"��Сֵ��"<<s.min()<<endl; 
				cout<<"���������"; 
				break;
			case 'e':
				end_flag=1;
				cout<<"����������"<<endl; 
				break;
			default:
				cout<<"������ָ�����"<<endl;
				cout<<"���������";  
				break;
		}
	}
	 
 
	return 0;
}
