#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

template <typename T>
class QueueWithMax{
	public:
		QueueWithMax():currentIndex(0){
		}
		
		void push_back(T number){
			while(!maximums.empty() && number >= maximums.back().number){
			    maximums.pop_back();
			}
			InternalData d{number,currentIndex};
			maximums.push_back(d);
			data.push_back(d);
			currentIndex++;
		}
		void pop_front(){
			if(data.empty())
			    throw "queue is empty";
			if(data.front().index == maximums.front().index){
				maximums.pop_front();
			}
			data.pop_front();
		}
		T max() const{
			if(maximums.empty())
			    throw "queue is empty";
			
			return maximums.front().number;  
		}
	private:
	    struct InternalData{
	    	T number;
	    	int index;
		}; 
		
		int currentIndex;
		deque<InternalData> data;
		deque<InternalData> maximums;
};

int main(){
	QueueWithMax<int> q;
	vector<int> data = {2,3,4,2,6,2,5,1};
	
	for(int i =0;i<data.size();i++){
		q.push_back(data[i]);
		cout<<q.max()<<" ";
	}
	return 0;
} 
