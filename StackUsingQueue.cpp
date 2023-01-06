// Approach 1 (2 Queues)
//Time Complexity: O(N)
//Space Complextiy: O(2N)
class Stack {
	// Define the data members.

   public:
    queue<int>q1,q2;
    Stack() {
        // Implement the Constructor.
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(!q1.size()) return true;
        return false;
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    int pop() {
        // Implement the pop() function.
        if(isEmpty()) return -1;
        int popped=q1.front();
        q1.pop();
        return popped;
    }

    int top() {
        // Implement the top() function.
        if(isEmpty()) return -1;
        return q1.front();
    }



//Approach 2 (Single Queue) 
//Time Complexity: O(N)
//Space Complextiy: O(N)
class Stack {
	// Define the data members.

   public:
    queue<int>q;
    Stack() {
        // Implement the Constructor.
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return q.size();
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(!q.size()) return true;
        return false;
    }

    void push(int element) {
        // Implement the push() function.
        q.push(element);
        for(int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        // Implement the pop() function.
        if(isEmpty()) return -1;
        int popped=q.front();
        q.pop();
        return popped;
    }

    int top() {
        // Implement the top() function.
        if(isEmpty()) return -1;
        return q.front();
    }
};