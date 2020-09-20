#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (x < minValue){
            
            lastMinValue = minValue;
            lastMinValueVector.push_back(lastMinValue);
            minValue = x;
        }
        data.push_back(x);
    }
    
    void pop() {
        int  topValue = top();
        if (topValue == minValue) {
            
            minValue = lastMinValueVector.back();
            lastMinValueVector.pop_back();
        }
        data.pop_back();
               
    }
    
    int top() {
        return data[data.size()-1];
    }
    
    int getMin() {
        minValue = INT_MAX;
        for (int i = 0; i < data.size(); i++){
            if( minValue > data[i]){
                minValue = data[i];
            }
        }
        return minValue;
    }

private:
    int minValue = INT_MAX;
    int lastMinValue = INT_MAX;
    vector<int> data;               // store elements
    vector<int> lastMinValueVector;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

/*
["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]] */

int main(){
	int x = 0;
	MinStack* minStack = new MinStack();
	minStack->push(2147483646);
	minStack->push(2147483646);
	minStack->push(2147483647);


	cout << "LONG_MAX:" << LONG_MAX << endl;
	cout << "LONG_MIN:" << LONG_MIN << endl;

	cout << "INT_MAX:" << INT_MAX << endl;
	cout << "INT_MIN:" << INT_MIN << endl;

	x = minStack->top();
	cout << "expected: 2147483647 == " << x << endl;

	minStack->pop();
	x = minStack->getMin();   

	cout << "expected: 2147483646 == " << x << endl;

	minStack->pop();

	x = minStack->getMin();   
	cout << "expected: 2147483646 == " << x << endl;
	
	minStack->pop();

	minStack->push(2147483647);
	cout << x << endl;

	x = minStack->top();
	cout << x << endl;

	x = minStack->getMin();   
	cout << x << endl;

	minStack->push(-2147483648);
	cout << x << endl;

	x = minStack->top();
	cout << x << endl;

	x = minStack->getMin();   
	cout << x << endl;

	minStack->pop();

	x = minStack->getMin();   
	cout << x << endl;

	return 0;
}
