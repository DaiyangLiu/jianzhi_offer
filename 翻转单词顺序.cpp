#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        //��һ�η�ת ��ȫ����ת 
		string rstr = Reverse(str);
		cout<<"1: "<<rstr<<endl;
		//�ڶ��η�ת����ת �����ڲ�
		int begin = 0, range = 0,i=0;
		while(i <= str.size()){//����=����֤���һ������Ҳ�ܱ���ת 
			if(i<str.size() && rstr[i]!=' '){
				range++;
				i++; 
			}else{
				string word(rstr,begin,range);
				word = Reverse(word);
				cout<<"word: "<<word<<endl;
				rstr.replace(begin,range,word);
				//����beginָ��λ�ã�range��С
				 while(i<str.size()){
				 	if(rstr[i]==' '){
				 		i++;
					 }else{
					 	break;
					 }
				 }
				 begin = i;
				 range = 0;
				 if(i == str.size()) break;//������������һ�����ʣ� ��ֱ������ѭ�� 
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
