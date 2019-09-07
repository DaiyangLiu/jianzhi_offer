#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    //���鳤��Ϊn+1 , �������ֶ���1~n�ķ�Χ�ڣ������ڸ������У��϶������ظ����ִ��ڵġ�
	 
    bool duplicate(int numbers[], int length, int* duplication) {
    	if(numbers==nullptr || length<=0){
    		return false;
		}
		for(int i=0;i<length;i++){
			if(numbers[i]<1 || numbers[i]>length-1){
				return false;
			}
		}
		
		int small = 1,large=length-1;

		int mid;
		while(true){
			mid = floor((large+small)/2);
			int small_count = 0, large_count = 0;
			cout<<"small: "<<small<<" large: "<<large<<endl;
			cout<<"mid: "<<mid<<endl;
			for(int i=0;i<length;i++){
				if(numbers[i]<= mid && numbers[i]>=small){
					small_count++;
				}else if(numbers[i]<= large && numbers[i]>mid){
					large_count++;
				}
			}
			cout<<"small_count: "<<small_count<<" large_count: "<<large_count<<endl;
			if(large-small<=1){
				if(large_count>small_count){
					*duplication=large;
				    return true;
				}else{
					*duplication=small;
				    return true;
				}
				
			}
			//mid
			if(small_count > large_count){
				large=mid;
			}else{
				small=mid+1;
			}
		}
    }
};
 
int main(){
    //��ȡ����̨������
	//ÿһ��Ϊһ�����뵥Ԫ
	string str;
	int num;
	vector<int> temp_arr;
	
	while (getline(cin, str)){
		stringstream ss(str);
		int num;

		while (ss >> num){
			cout << num << ' ';
			temp_arr.push_back(num);
		}
		cout << endl;
		
		//��vector�е�����ת�Ƶ�һ�������У����ڴ���duplicate����
		int size = temp_arr.size();
		int* arr = new int[size];
		for(int i=0;i<size;i++){
			arr[i] = temp_arr[i];
		}
		temp_arr.clear();
		if(temp_arr.size()==0){
			cout<<"�����vector\n";
		}
		
		for(int i=0;i<size;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n----------------------\n";
		
		bool flag = false;
		cout<<"init flag: "<<flag<<endl;
		int duplication;
		Solution s;
		cout<<"address arr:"<<&arr<<endl;
		cout<<"address duplication: "<<&duplication<<endl;
		flag = s.duplicate(arr, size, &duplication);
		cout<<"flag: "<<flag<<endl;
		cout<<"duplication: "<<duplication<<endl;
		cout<<"address duplication: "<<&duplication<<endl;	 
	}
	return 0;
}
