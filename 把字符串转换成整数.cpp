#include <cstdio>
#include <iostream>
using namespace std;

//��Ҫ���ǵ����⣺
//����ָ�룬����ⲻ��Ҫ���ǣ�����str�����ֵ�+-�ţ������֣�������� 
class Solution {
public:
    int StrToInt(string str) {
        long long num=0;//��ֹ����������� 
        if(str.size()==0) return num;//��str
		int length = str.size();
		int start = 0;
		//����������
		bool minus_tag;
		
		if(str[0]<'0' || str[0]>'9'){
			if(str[0]=='+' || str[0]=='-'){//�Ϸ������ֵ�+-�� 
			    minus_tag=(str[0]=='-')?true:false;
				start = 1; 
		    }else{//�Ƿ����� 
		    	return num;
			}
		}
		
		for(int i=start;i<length;i++){
			if(str[i]<'0' || str[i]>'9'){//���ڷǷ����� 
				num=0;
				break;
			} 
			int flag=minus_tag?-1:1;
			num = num*10 + flag*(str[i]-'0');
			//�������
			if( ( (!minus_tag) && (num>0x7fffffff) ) ||(minus_tag && (num<(signed int)0x80000000) ) ){
				num=0;
				break;
			}
			 
		}
		return num;
    }
};

int main(){
	Solution s;
	cout<<s.StrToInt("+2147483647")<<endl;
	cout<<s.StrToInt("1a33")<<endl;
	return 0;
}
