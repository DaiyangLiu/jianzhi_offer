#include <cstdio>
#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        bool flag = False;
        if(length==0){
        	return flag;
		}
		for(int i=0;i<length;i++){
			
			
		}
    }
};
 
int main(){
    //获取控制台端输入
	//每一行为一个输入单元
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
		
		//将vector中的数字转移到一个数组中，便于传入duplicate函数
		int size = temp_arr.size();
		int* arr = new int[size];
		for(int i=0;i<size;i++){
			arr[i] = temp_arr[i];
		}
		temp_arr.clear();
		if(temp_arr.size()==0){
			cout<<"已清空vector\n";
		}
		
		for(int i=0;i<size;i++){
			cout<<arr[i]<<" ";
		}
		cout<<"\n----------------------\n";
		
		bool flag = False;
		int* duplication;
		flag = duplicate(int arr[], int size, int* duplication);
		 
	}
	return 0;
}
