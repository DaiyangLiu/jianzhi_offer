#include <cstdio>
#include <iostream>
using namespace std;
 
// A[.[B]][e|EC]
//A前面可以有正号或负号
//C前面可以有正号或负号
//B前面不能有正号或负号
//B前面可以只有一个小数点，没有A 
//A后面可以什么都没有，可以没有B而有C 
//B后面可以什么都没有
//e|E后面必须有数字
 
class Solution {
public:
	bool isNumeric(char* str){
		if(str == nullptr) return false;
		
		bool numeric = scanInteger(&str); //整数部分是否为数字，str一直遍历到不为数字的那一位上 
		if(*str=='.'){
			++str;
			numeric = scanUnsignedInteger(&str) || numeric;//  ||或者的原因是：可以只包含小数部分，也可以只包含整数部分 
		}
		
		if(*str=='e'||*str=='E'){
			++str;
			numeric = numeric && scanInteger(&str);
		}
		return numeric && *str=='\0'; //*str=='\0' 恰好处理了如果有其他特殊符号的情况 
	}
	bool scanUnsignedInteger(char ** str){
		char* before = *str;
		while(**str!='\0' && **str>='0'&&**str<='9'){
			++(*str);
		}
		return *str>before;
	}
	
	bool scanInteger(char ** str){
		if(**str == '+' || **str=='-'){
			++(*str);
		}
		return scanUnsignedInteger(str);
	}
	//======================================================================
	//======================================================================
    bool isNumericByLiu(char* string)//这个未免太啰嗦太复杂了一点 
    {
        if(string == nullptr ||*string == '\0') return false;
        
        int bit_count = 0; 
        
        if(*string != '.'){ //如果不是以小数点开头 
        	//检查A部分的正确性 
        	bit_count = isnumericA(string);
        	if(bit_count < 0){
        		return false;
			} else{ //说明A部分是对的 ,接下来检查后面的数字 
				string = string + bit_count; 
				if(*string == '.' ){
					//此时，小数点后可以跟数字，也可以不跟数字 
				cout<<"小数点后： "<<string<<endl;
				string ++;//移到小数点后面第一位数 
				if(*string == '\0') return true;
				else{ //小数点后面跟了数字 
					bit_count = isnumericB(string); 
					if(bit_count < 0){
						return false;
					}else{ //小数点后面的数字是对的，现在要检查e ||E 
						string = string + bit_count;
						cout<<"小数点数字后： "<<string<<endl;
						if(*string == '\0') return true;
						else{//小数后面跟了指数 
							if(*string == 'e' || *string=='E'){
		                    	string++;
								bit_count = isnumericC(string);
								if(bit_count<0)return false;
								else{
									return true;
								} 								
							} else{
								return false;
							}
						}
					}
				}	
				}else if(*string == 'e' || *string =='E'){
					string++;
					bit_count = isnumericC(string);
					if(bit_count<0)return false;
					else{
						return true;
					} 	
				}else{
					return false;
				}
				
			}			
		}else{//如果是以小数点开头 
			//检查B部分的正确性 
			string ++;//移到小数点后面第一位数 
			if(*string == '\0') return false;
			else{ //小数点后面跟了数字 
				bit_count = isnumericB(string); 
				if(bit_count < 0){
					return false;
				}else{ //小数点后面的数字是对的，现在要检查e ||E 
					string = string + bit_count;
					cout<<"小数点数字后： "<<string<<endl;
					if(*string == '\0') return true;
					else{//小数后面跟了指数 
						if(*string == 'e' || *string=='E'){
		                   	string++;
							bit_count = isnumericC(string);
							if(bit_count<0)return false;
							else{
								return true;
							} 								
						} else{
							return false;
						}
					}
				}
			}	
		} 
		return false;		 
    }
     
	 
	 int isnumericA(char* string){
		int correct = 0;
		if(*string == '+' || *string == '-'){
			string ++;
			correct++;
			if(*string == '.')return -1; //不知道  +.11 这种可以吗， 这个if 把这种情况判定为不可以 
		}
		int wrongletter=0;
		while(*string!='\0'){
			if(*string >='0' &&*string<='9'){
				string++;
				correct++;
			}else if(*string == '.'||*string == 'e'||*string == 'E'){
				break;
			}else{
				wrongletter++;
				break;
			}		
		}
		if(wrongletter || correct < 1) return -1; //返回 -1 说明不是数字 
		return correct; //返回大于零的数字，说明该该string前部是数字，str + correct 可以到下一个不是数字的位置 
	} 
	
	int isnumericB(char* string){
		int correct = 0;
		if(*string == '+' || *string == '-'){
		    return -1; //小数点后面的数字不能有正负号 
		}
		int wrongletter=0;
		while(*string!='\0'){
			if(*string >='0' &&*string<='9'){
				string++;
				correct++;
			}else if(*string == 'e' || *string == 'E'){
				break;
			}else{
				wrongletter++;
				break;
			}		
		}
		if(wrongletter) return -1; //返回 -1 说明不是数字 ，这里设置的是 小数点后面可以没有数字，直接跟E ||e 
		return correct; //返回大于零的数字，说明该该string前部是数字，str + correct 可以到下一个不是数字的位置 
	} 
	
	 int isnumericC(char* string){
		int correct = 0;
		if(*string == '+' || *string == '-'){
			string ++;
			correct++;
			if(*string == '.')return -1; //不知道  +.11 这种可以吗， 这个if 把这种情况判定为不可以 
		}else{ // 这里表示e后面的数字必须带符号 
			return -1;
		}
		
		int wrongletter=0;
		while(*string!='\0'){
			if(*string >='0' &&*string<='9'){
				string++;
				correct++;
			}else{
				wrongletter++;
				break;
			}		
		}
		if(wrongletter || correct <= 1) return -1; //返回 -1 说明不是数字 ,correct必须大于1 ，否则只有符号 
		return correct; //返回大于零的数字，说明该该string前部是数字，str + correct 可以到下一个不是数字的位置 
	} 
	

};




int main(){
	
	char str[] = "+1234.111e-1"; 
	cout<<str<<endl;
	
	Solution s;
	cout<<"是否是数字： "<<s.isNumeric(str)<<endl;

	return 0;
}
