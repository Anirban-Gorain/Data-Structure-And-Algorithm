#include<bits/stdc++.h>
using namespace std;

class Queue {

	int front, rear;
	vector<int> arr;

	public:

	Queue()
	{
		front = 0;
		rear = 0;
		arr.resize(100001);
	}

	// Enqueue (add) element 'e' at the end of the queue.
	void enqueue(int e)
	{
		if(rear==10001)
			return;

		arr[rear]=e;
		rear++;
	}

	// Dequeue (retrieve) the element from the front of the queue.
	int dequeue()
	{
		int frontElem=arr[front++];

		if(front>rear)
		{
			frontElem=-1;
			front=rear=0;
		}

		return frontElem;
	}
};

int main(void)
{

    #ifndef ONLINE_JUDGE
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/input.txt", "r", stdin);
        freopen("C:/Users/Anirban Gorain/Desktop/DSA/output.txt", "w", stdout);
    #endif

    

    return 0;

}