#include <cstdio>
#include <iostream>
using namespace std;
 

//这里忽略掉了2个问题
//1.str 和pattern为空指针的时候，分别应该做什么处理
 
//2. pattern 为  .* 时，怎么处理 
//写不下去了，看了看答案，还是递归牛啊
 

// . 表示可以是任意一个字符
// * 表示前面的字符可以出现任意次 包括0次

 
class Solution {
public:
	bool match(char* str, char* pattern){
		if(str == nullptr || pattern == nullptr) return false; //只要有一个为空指针，则无法进行比较，判定为false 
		
		return matchCore(str,pattern);
	}
	
	bool matchCore(char * str, char * pattern){
		if(*str == '\0' && *pattern == '\0') return true; //如果两个都到头了，说明都匹配完成了，返回true 
		if(*str!='\0' && *pattern == '\0') return false;//如果pattern到头了，而str没到头，说明匹配失败 
		
		if(*(pattern +1) == '*'){ //最伤脑筋的一种情况，字符后面有 * 
			if(*pattern == *str || (*pattern == '.' && *str!='\0')) 
			//如果当前pattern字符和str字符相等，或者当前pattern 字符为 . 并且str还没到头
			//则表示可以继续针对 * 匹配
			//1.str只有当前这一个字符和pattern当前字符相同，所以 str+1，pattern+2 ，重新开始匹配 
			//2.str有一连串的字符和pattern相同，所以str+1，pattern，从而继续匹配
			//3.str和pattern不相同,此时是*前面字符有零个的情况，所以str，pattern,用新的pattern和str进行匹配 
			    return matchCore(str+1,pattern+2)||matchCore(str+1,pattern)||matchCore(str,pattern+2);
			else//str和pattern不相同,所以str，pattern,用新的pattern和str进行匹配
			    return matchCore(str,pattern+2);
		}
		
		//字符后面没有 *  ，正常匹配即可 
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
				if(pattern[pi+1]!='*'){//字符后面没有 *  
					if(str[si] == pattern[pi]){  //两个字符相匹配 
						si++;
						pi++;
					}else{ //两个字符不相匹配 
						return false;
					}
				}else{ //pattern 字符后面是 * ，进行循环匹配 
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
