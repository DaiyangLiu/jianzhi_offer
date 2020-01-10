#include <cstdio>
#include <iostream>
using namespace std;
 

//������Ե���2������
//1.str ��patternΪ��ָ���ʱ�򣬷ֱ�Ӧ����ʲô����
 
//2. pattern Ϊ  .* ʱ����ô���� 
//д����ȥ�ˣ����˿��𰸣����ǵݹ�ţ��
 

// . ��ʾ����������һ���ַ�
// * ��ʾǰ����ַ����Գ�������� ����0��

 
class Solution {
public:
	bool match(char* str, char* pattern){
		if(str == nullptr || pattern == nullptr) return false; //ֻҪ��һ��Ϊ��ָ�룬���޷����бȽϣ��ж�Ϊfalse 
		
		return matchCore(str,pattern);
	}
	
	bool matchCore(char * str, char * pattern){
		if(*str == '\0' && *pattern == '\0') return true; //�����������ͷ�ˣ�˵����ƥ������ˣ�����true 
		if(*str!='\0' && *pattern == '\0') return false;//���pattern��ͷ�ˣ���strû��ͷ��˵��ƥ��ʧ�� 
		
		if(*(pattern +1) == '*'){ //�����Խ��һ��������ַ������� * 
			if(*pattern == *str || (*pattern == '.' && *str!='\0')) 
			//�����ǰpattern�ַ���str�ַ���ȣ����ߵ�ǰpattern �ַ�Ϊ . ����str��û��ͷ
			//���ʾ���Լ������ * ƥ��
			//1.strֻ�е�ǰ��һ���ַ���pattern��ǰ�ַ���ͬ������ str+1��pattern+2 �����¿�ʼƥ�� 
			//2.str��һ�������ַ���pattern��ͬ������str+1��pattern���Ӷ�����ƥ��
			//3.str��pattern����ͬ,��ʱ��*ǰ���ַ�����������������str��pattern,���µ�pattern��str����ƥ�� 
			    return matchCore(str+1,pattern+2)||matchCore(str+1,pattern)||matchCore(str,pattern+2);
			else//str��pattern����ͬ,����str��pattern,���µ�pattern��str����ƥ��
			    return matchCore(str,pattern+2);
		}
		
		//�ַ�����û�� *  ������ƥ�伴�� 
		if(*str == *pattern || (*pattern=='.'&&*str!='\0')) 
		    return matchCore(str+1,pattern+1);
		    
		return false;
	}
	
	
    bool match_something_wrong(char* str, char* pattern)
    {
    	if(str == nullptr && pattern == nullptr) return false;
    	if(pattern == nullptr) return false;
		if(pattern==".*") return true;
		
    	int pi = 0, si = 0;
		while(str[si]!='\0' && pattern[pi]!='\0'){
			if(pattern[pi] == '.'){
				si++;
				pi++;
			}else if(pattern[pi] == '*'){
				pi++;
			}else{
				if(pattern[pi+1]!='*'){//�ַ�����û�� *  
					if(str[si] == pattern[pi]){  //�����ַ���ƥ�� 
						si++;
						pi++;
					}else{ //�����ַ�����ƥ�� 
						return false;
					}
				}else{ //pattern �ַ������� * ������ѭ��ƥ�� 
				    if(pattern[pi]!= '.'){
				    	while(str[si]!='\0' && str[si] == pattern[pi]){
							si++;
						} 
						pi++;
					}else if(pattern[pi]== '.'){
						
					}
					
				}
			}
		}  
		
		if(str[si]!='\0') return false;		
		if(pattern[pi]!='\0' && pattern[pi]!='*') return false;
		 
        return true;
    }
};

int main(){
	char str[] = "";
	char pattern[] = ".*";
	int i = 0 ;
	while(str[i] != '\0'){
		cout<<str[i++];
	}
	Solution s;
	cout<<s.match(str,pattern)<<endl;
	return 0;
}
