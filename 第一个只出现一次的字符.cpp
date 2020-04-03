#include <cstdio>
#include <iostream>
#include <string> 
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
    	if(str.size() == 0) return -1;
        unsigned int chash[256]={0};
        int length = str.size();
        int pos =-1;
        for(int i =0;i<length;i++){
        	chash[str[i]]++;
        	cout<<str[i]<<" "<<chash[str[i]]<<endl;
		}
		for(int i = 0;i<length;i++){
			if(chash[str[i]]==1){
				pos = i;
				break;
			}
		}
		
		return pos;
    }
};

int main(){
	string str("abaccdeff");
	Solution s;
	cout<<s.FirstNotRepeatingChar(str)<<endl;
	return 0;
}
