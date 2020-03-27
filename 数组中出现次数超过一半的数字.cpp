#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	if(numbers.size() == 0) return 0;
	    //ʹ�� Partition�Ļ�����ʱֹͣ 
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
	    //�������λ���Ƿ�ռ�����һ���
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
    	//start �����ַ�Χ��һ�����ֵ��±꣬ end�����ַ�Χ�����һ�����ֵ��±�
		if(start == end) return start;		
		
		int index = start + rand()%(end-start); // (start+end) /2;  //��� 
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
	    
	    //�������λ���Ƿ�ռ�����һ���
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
    // {3,3,4,3,6,6,5,7,3,3,3,3}; �������������ʱ��ܳ�������Ҳ���н�� 
    vector<int> numbers = {3,3,4,3,6,6,5,7,3,3,3,3}; //
	Solution s;
	int morek = s.MoreThanHalfNum_Solution(numbers);
	cout<<"morek: "<<morek<<endl;
	return 0;
}
