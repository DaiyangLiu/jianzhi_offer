#include <cstdio>
#include <iostream>
using namespace std;

//需要考虑的问题：
//（空指针，这道题不需要考虑），空str，数字的+-号，非数字，数字溢出 
class Solution {
public:
    int StrToInt(string str) {
        long long num=0;//防止溢出发生错误 
        if(str.size()==0) return num;//空str
		int length = str.size();
		int start = 0;
		//处理正负号
		bool minus_tag;
		
		if(str[0]<'0' || str[0]>'9'){
			if(str[0]=='+' || str[0]=='-'){//合法的数字的+-号 
			    minus_tag=(str[0]=='-')?true:false;
				start = 1; 
		    }else{//非法符号 
		    	return num;
			}
		}
		
		for(int i=start;i<length;i++){
			if(str[i]<'0' || str[i]>'9'){//存在非法符号 
				num=0;
				break;
			} 
			int flag=minus_tag?-1:1;
			num = num*10 + flag*(str[i]-'0');
			//处理溢出
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
