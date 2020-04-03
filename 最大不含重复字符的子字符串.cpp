#include <cstdio>
#include <iostream>
using namespace std;

class Solution{
	public:
		int LongestSubstringWithoutDuplication(string str){
			if(str.size() <= 1) return str.size();			
			int maxlen = 0;
			int curlen = 0;
			int lastpos[26];
			for(int i =0 ;i<26;i++){
				lastpos[i] = -1;
			}  
			
			for(int i =0;i<str.size();i++){
				curlen++;
				int i_lastpos = lastpos[str[i]-'a'];
				if(  i_lastpos > -1 ){
					int distance = i - i_lastpos;
					if(distance < curlen){
						curlen = distance;
					}
				}
				lastpos[str[i]-'a'] = i;
				if(maxlen<curlen){
					maxlen = curlen;
				}
			}
			
			return maxlen;
		}
};
int main(){
	
	Solution s;
	cout<<s.LongestSubstringWithoutDuplication("arabcacfr")<<endl;
	cout<<s.LongestSubstringWithoutDuplication("aaaaa")<<endl;
	cout<<s.LongestSubstringWithoutDuplication("abcabcavcabcd")<<endl;
	return 0;
} 
