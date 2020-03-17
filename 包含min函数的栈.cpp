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
	cout<<"²åÈë£ºc + x"<<endl;
	cout<<"²é¿´Õ»¶¥£ºt"<<endl;
	cout<<"µ¯³öÕ»¶¥£ºp"<<endl;
	cout<<"²é¿´×îÐ¡Öµ£ºm"<<endl;
	cout<<"ÍË³ö£ºe"<<endl;
	
	char command;
	int end_flag=0;
	cout<<"ÇëÊäÈëÃüÁî£º"; 
	while(cin>>command && !end_flag){
		int new_num;
		switch(command){
			case 'c':
				cin>>new_num;
				cout<<"²åÈë "<<new_num<<endl; 
				s.push(new_num);
				cout<<"ÇëÊäÈëÃüÁî£º"; 
				break;
			case 't':
				cout<<"Õ»¶¥ÔªËØ£º"<<s.top()<<endl; 
				cout<<"ÇëÊäÈëÃüÁî£º"; 
				break;
			case 'p':
				cout<<"µ¯³öÕ»¶¥£¡"<<endl;
				s.pop(); 
				cout<<"ÇëÊäÈëÃüÁî£º"; 
				break;
			case 'm':
				cout<<"×îÐ¡Öµ£º"<<s.min()<<endl; 
				cout<<"ÇëÊäÈëÃüÁî£º"; 
				break;
			case 'e':
				end_flag=1;
				cout<<"½áÊø²Ù×÷£¡"<<endl; 
				break;
			default:
				cout<<"ÇëÊäÈëÖ¸¶¨ÃüÁî£¡"<<endl;
				cout<<"ÇëÊäÈëÃüÁî£º";  
				break;
		}
	}
	 
 
	return 0;
}
