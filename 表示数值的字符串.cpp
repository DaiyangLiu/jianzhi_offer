#include <cstdio>
#include <iostream>
using namespace std;
 
// A[.[B]][e|EC]
//Aǰ����������Ż򸺺�
//Cǰ����������Ż򸺺�
//Bǰ�治�������Ż򸺺�
//Bǰ�����ֻ��һ��С���㣬û��A 
//A�������ʲô��û�У�����û��B����C 
//B�������ʲô��û��
//e|E�������������
 
class Solution {
public:
	bool isNumeric(char* str){
		if(str == nullptr) return false;
		
		bool numeric = scanInteger(&str); //���������Ƿ�Ϊ���֣�strһֱ��������Ϊ���ֵ���һλ�� 
		if(*str=='.'){
			++str;
			numeric = scanUnsignedInteger(&str) || numeric;//  ||���ߵ�ԭ���ǣ�����ֻ����С�����֣�Ҳ����ֻ������������ 
		}
		
		if(*str=='e'||*str=='E'){
			++str;
			numeric = numeric && scanInteger(&str);
		}
		return numeric && *str=='\0'; //*str=='\0' ǡ�ô��������������������ŵ���� 
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
    bool isNumericByLiu(char* string)//���δ��̫����̫������һ�� 
    {
        if(string == nullptr ||*string == '\0') return false;
        
        int bit_count = 0; 
        
        if(*string != '.'){ //���������С���㿪ͷ 
        	//���A���ֵ���ȷ�� 
        	bit_count = isnumericA(string);
        	if(bit_count < 0){
        		return false;
			} else{ //˵��A�����ǶԵ� ,����������������� 
				string = string + bit_count; 
				if(*string == '.' ){
					//��ʱ��С�������Ը����֣�Ҳ���Բ������� 
				cout<<"С����� "<<string<<endl;
				string ++;//�Ƶ�С��������һλ�� 
				if(*string == '\0') return true;
				else{ //С�������������� 
					bit_count = isnumericB(string); 
					if(bit_count < 0){
						return false;
					}else{ //С�������������ǶԵģ�����Ҫ���e ||E 
						string = string + bit_count;
						cout<<"С�������ֺ� "<<string<<endl;
						if(*string == '\0') return true;
						else{//С���������ָ�� 
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
		}else{//�������С���㿪ͷ 
			//���B���ֵ���ȷ�� 
			string ++;//�Ƶ�С��������һλ�� 
			if(*string == '\0') return false;
			else{ //С�������������� 
				bit_count = isnumericB(string); 
				if(bit_count < 0){
					return false;
				}else{ //С�������������ǶԵģ�����Ҫ���e ||E 
					string = string + bit_count;
					cout<<"С�������ֺ� "<<string<<endl;
					if(*string == '\0') return true;
					else{//С���������ָ�� 
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
			if(*string == '.')return -1; //��֪��  +.11 ���ֿ����� ���if ����������ж�Ϊ������ 
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
		if(wrongletter || correct < 1) return -1; //���� -1 ˵���������� 
		return correct; //���ش���������֣�˵���ø�stringǰ�������֣�str + correct ���Ե���һ���������ֵ�λ�� 
	} 
	
	int isnumericB(char* string){
		int correct = 0;
		if(*string == '+' || *string == '-'){
		    return -1; //С�����������ֲ����������� 
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
		if(wrongletter) return -1; //���� -1 ˵���������� ���������õ��� С����������û�����֣�ֱ�Ӹ�E ||e 
		return correct; //���ش���������֣�˵���ø�stringǰ�������֣�str + correct ���Ե���һ���������ֵ�λ�� 
	} 
	
	 int isnumericC(char* string){
		int correct = 0;
		if(*string == '+' || *string == '-'){
			string ++;
			correct++;
			if(*string == '.')return -1; //��֪��  +.11 ���ֿ����� ���if ����������ж�Ϊ������ 
		}else{ // �����ʾe��������ֱ�������� 
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
		if(wrongletter || correct <= 1) return -1; //���� -1 ˵���������� ,correct�������1 ������ֻ�з��� 
		return correct; //���ش���������֣�˵���ø�stringǰ�������֣�str + correct ���Ե���һ���������ֵ�λ�� 
	} 
	

};




int main(){
	
	char str[] = "+1234.111e-1"; 
	cout<<str<<endl;
	
	Solution s;
	cout<<"�Ƿ������֣� "<<s.isNumeric(str)<<endl;

	return 0;
}
