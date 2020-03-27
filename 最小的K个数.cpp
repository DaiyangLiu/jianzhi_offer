#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> result;
		if(input.size() == 0) return result;
		if(input.size() < k) return input;
		
		int start = 0,end = input.size()-1;
		int index = Partition(input,start,end);
		cout<<"index: "<<index<<endl;
		cout<<"k: "<<k<<endl;
		while(index != k){
			cout<<"index:"<<index<<"-----------------"<<endl; 
			if(index<k){
				index = Partition(input,index+1,end);
			}else if(index>k){
				index = Partition(input,start,index-1);
			}
		}
		PrintNumbers(input);
		for(int i =0;i<k;i++){
			result.push_back(input[i]);
		}
		return result;
    }
    
    int Partition(vector<int> &numbers, int start, int end){
    	if(start == end) return start;
    	
    	int index = start + rand()%(end-start);
    	
    	swap(numbers[index],numbers[end]);
    	PrintNumbers(numbers);
    	int small = start-1;
    	for(int i =start;i < end;i++){
    		if(numbers[i]<numbers[end]){
    			small ++;
    			if(small < i){
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
    
};

void PrintNumbers(vector<int> numbers){
		for(int i =0;i<numbers.size();i++){
			cout<<numbers[i]<<" ";
		}
		cout<<endl;
	}

int main(){
	vector<int> input={4,5,1,6,2,7,3,8};
	Solution s;
	vector<int> leastk = s.GetLeastNumbers_Solution(input,4);
	PrintNumbers(leastk);
	return 0;
}
