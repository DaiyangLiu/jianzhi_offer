#include <iostream>
#include <string>
using namespace std;

class Solution{
	public:
		int NumberOfNumberToSTring(int n){
			if(n<=0) return -1;
			
			string nstr = to_string(n);
			cout<<nstr<<endl;
			if(nstr.size() == 1) return 1;
			
			int length = nstr.size();
			int * count = new int[length];//全部置零 
			int i = length-1;
			while(i>=0){
				if(i ==(length -1) ){
					count[i] = 1;
				}else{
					count[i] = count[i+1]; 
				}
				
				if(i<(length-1)){
					//算g(i,i+1)是否小于等于25  且 大于等于  10 
					int num = (nstr[i]-'0')*10;
					num += nstr[i+1]-'0';
					cout<<"num="<<num<<endl;
					if(num>=10&&num<=25){
						if(i == (length-2)){
							count[i] ++;
						}else{
							count[i] += count[i+2];
						}
					} 
				}
					
				i--;
			}
			
			int result = count[0];
			delete [] count;
			
			return result;
		}
}; 

int main(){
	Solution s;
	
	cout<<s.NumberOfNumberToSTring(12258)<<endl;
	return 0;
} 
