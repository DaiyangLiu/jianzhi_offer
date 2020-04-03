#include <cstdio>
#include <iostream>
#include <string> 
using namespace std;


//如果当前字符流没有存在出现一次的字符，返回#字符。 
class Solution
{
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
        if(chash[ch] == 0){
        	chash[ch] = index++;
            cout<<"insert "<<ch<<" "<<chash[ch]<<endl;
		}else{
			if(chash[ch] > 0){
				for(int i =0;i<256;i++){
				    if(i == ch) continue;
					if(chash[i]>chash[ch]){
						cout<<i<<" "<<chash[i]<<endl;
						chash[i]--;
					}
				}
			}
			chash[ch] = -2;	
			index--;
		}
		
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	for(int i =0;i<256;i++){
    		if(chash[i] == 1){
    			return i;
			}
		}
		return '#';
    }
    private: 
    int chash[256]={0};
    int index = 1;

};

int main(){
	Solution s;
	char c;
	while(cin>>c){
		s.Insert(c);
		cout<<"ans:" <<s.FirstAppearingOnce()<<endl;
	}
	
	return 0;
}
