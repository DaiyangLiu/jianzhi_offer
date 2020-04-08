#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        //第一次翻转 ，全部翻转 
		string rstr = Reverse(str);
		cout<<"1: "<<rstr<<endl;
		//第二次翻转，翻转 单词内部
		int begin = 0, range = 0,i=0;
		while(i <= str.size()){//加上=，保证最后一个单词也能被翻转 
			if(i<str.size() && rstr[i]!=' '){
				range++;
				i++; 
			}else{
				string word(rstr,begin,range);
				word = Reverse(word);
				cout<<"word: "<<word<<endl;
				rstr.replace(begin,range,word);
				//更新begin指向位置，range大小
				 while(i<str.size()){
				 	if(rstr[i]==' '){
				 		i++;
					 }else{
					 	break;
					 }
				 }
				 begin = i;
				 range = 0;
				 if(i == str.size()) break;//如果处理到了最后一个单词， 则直接跳出循环 
			}
		}
		return rstr;
		    
    }
    
    string Reverse(string str){
    	string tmp;
    	for(int i = str.size()-1;i>=0;i--){
    		tmp+=str[i];
		}
		return tmp;
	} 
};

int main(){
	Solution s;
	string ans = s.ReverseSentence("We are students. So funny  you.   ");
	cout<<ans<<endl;
	return 0;
}
