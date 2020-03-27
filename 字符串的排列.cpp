#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
 
 
//字符串中的字母可能有重复 
class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> ans;
        if(str.length() == 0) return ans;
		PermuteRecurse(str, 0, ans);
		sort(ans.begin(),ans.end());//按字典序输出 
		return ans;   
        
    }
    
    void PermuteRecurse(string str, int n, vector<string> &ans){
        if(n == str.length()){
        	if(find(ans.begin(),ans.end(),str) == ans.end()){//检查重复排列 
        		ans.push_back(str);
			} 
			return;
		}
    	for(int i = n; i <str.length();i++){   	
    		char temp = str[i];
    		str[i] = str[n];
    		str[n] = temp;
    		PermuteRecurse(str,n+1,ans);
    		temp = str[i];
    		str[i] = str[n];
    		str[n] = temp;
		}		
	}
	vector<string> PermutationOne(string str) {
        vector<string> ans;
        string one;
        if(str.length() == 0) return ans;
		PermuteRecurseOne(str,one, 0, ans);
		sort(ans.begin(),ans.end());//按字典序输出 
		return ans;   
        
    }
	void PermuteRecurseOne(string str,string one, int n, vector<string> &ans){
        if(n == str.length()){
        	if(find(ans.begin(),ans.end(),str) == ans.end()){//检查重复排列 
        		cout<<"str:"<<str<<endl;
        		cout<<"one:"<<one<<endl;
				ans.push_back(str);
			} 
			return;
		}
    	for(int i = n; i <str.length();i++){   	
    		char temp = str[i];
    		str[i] = str[n];
    		str[n] = temp;
    		PermuteRecurseOne(str,one+temp,n+1,ans);
    		temp = str[i];
    		str[i] = str[n];
    		str[n] = temp;
		}		
	}
    
};

int main(){
	string a = "abc";
	Solution s;
	vector<string> ans = s.PermutationOne(a);
	for(int i = 0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	
	return 0;
}
