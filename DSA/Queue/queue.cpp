#include<bits/stdc++.h>
using namespace std;

class Queue {
	private:
		vector<int> arr;
		int p_start;
	public:
		Queue() {p_start = 0;}
		bool enQueue(int x) {
			arr.push_back(x);
			return true;
		}
		bool deQueue() {
			if(arr.size() == 0) {
				return false;
			}
			p_start++;
			return true;
		}
		int Front() {
			return arr[p_start];
		}
		bool isEmpty() {
			return arr.size() ? false : true;
		}
};

int main() {
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	if (!q.isEmpty()) {
        cout << q.Front() << endl;
    	}
    	q.deQueue();
    	if (!q.isEmpty()) {
        	cout << q.Front() << endl;
    	}
    	q.deQueue();
    	if (!q.isEmpty()) {
        	cout << q.Front() << endl;
    	}
	return 0;
}



