#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    string LeftRotateString(string str, int n) {
    	if(str.size()==0) return "";
        string lstr = Reverse(str);
        
        string str1(lstr,0,str.size()-n);
        str1 = Reverse(str1);
        
        string str2(lstr,str.size()-n);
        str2 = Reverse(str2);
        
        return str1+str2;
    }
    
    string Reverse(string str){
    	string tmp;
    	for(int i= str.size()-1;i>=0;i--){
    		tmp+=str[i];
		}
		return tmp;
	} 
};

int main(){
	Solution s;
	cout<<s.LeftRotateString("abcXYZdef",3)<<endl;
	cout<<s.LeftRotateString("abcdefg",2)<<endl;
    cout<<s.LeftRotateString("ab",2)<<endl;	
    cout<<s.LeftRotateString("ab",1)<<endl;
    cout<<s.LeftRotateString("ab",0)<<endl;
	return 0;
}
