#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if(numbers.size() == 0) return 0;
	    //使用 Partition的话，何时停止 
	    int middle = numbers.size()/2;
	    int start =0, end = numbers.size()-1;
	    int index = Partition(numbers,start,end);
	    cout<<"index: "<<index<<endl;
	    cout<<"middle: "<<middle<<endl;
	    
	    int debugnum = 10;

	    while(index != middle && debugnum){
	    	cout<<"----------------------------"<<endl; 
	    	cout<<"in index: "<<index<<endl;
	    	if(index < middle){
	    		index = Partition(numbers,index + 1,end);
			}else if(index > middle){
				index = Partition(numbers,start,index-1);
			}	
			cout<<"out index: "<<index<<endl;
			//debugnum--;
		}
	    
	    cout<<"end the partition"<<endl;
	    PrintNumbers(numbers);
	    //检验该中位数是否占数组的一半多
	    int count = 0;
		for(int i = 0; i<numbers.size();i++){
			if(numbers[i] == numbers[index]){
				count++;
			}
		} 
		cout<<numbers[index]<<" "<<count<<endl;
		if(count <= numbers.size()/2){
			return 0;
		}
	    
	    return numbers[index];
	    
    }
    
    int Partition(vector<int> &numbers, int start,int end){
    	//start 是数字范围第一个数字的下标， end是数字范围的最后一个数字的下标
		if(start == end) return start;		
		
		int index = start + rand()%(end-start); // (start+end) /2;  //随机 
		//cout<<"out index: "<<index<<endl;
		swap(numbers[index],numbers[end]);
		PrintNumbers(numbers);
		
		int small = start-1;
		for(int i =start;i<end;i++){
			if(numbers[i] < numbers[end]){
				small++;
				if(small < i ){
					swap(numbers[small],numbers[i]);
				}
			}
		}
		
		small++;
		swap(numbers[small],numbers[end]);
		
		return small;		
	}
	
	void PrintNumbers(vector<int> numbers){
		for(int i =0;i<numbers.size();i++){
			cout<<numbers[i]<<" ";
		}
		cout<<endl;
	}
	
	int MoreThanHalfNum_Solution_2(vector<int> numbers) {
    	if(numbers.size() == 0) return 0;
	 
	    int result=numbers[0];
	    int times=1;
	    for(int i =1;i<numbers.size();i++){
	    	if(times == 0){
	    		result = numbers[i];
	    		times++;
			}else if(numbers[i] == result){
				times++;
			}else{
				times--;
			}
		}
	    
	    //检验该中位数是否占数组的一半多
	    int count = 0;
		for(int i = 0; i<numbers.size();i++){
			if(numbers[i] == result){
				count++;
			}
		} 
		if(count <= numbers.size()/2){
			return 0;
		}
	    
	    return result;	    
    }
	
};

int main(){
//vector<int> numbers = {1,2,3,2,2,2,5,4,2};
//    vector<int> numbers = {5,4,2,3,6,1}; 
//    vector<int> numbers = {};
   // vector<int> numbers = {1};
    //vector<int> numbers = {2,2};
    // {3,3,4,3,6,6,5,7,3,3,3,3}; 这个用例的运行时间很长，但是也会有结果 
    vector<int> numbers = {3,3,4,3,6,6,5,7,3,3,3,3}; //
	Solution s;
	int morek = s.MoreThanHalfNum_Solution(numbers);
	cout<<"morek: "<<morek<<endl;
	return 0;
}
