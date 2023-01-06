//Time Complexity: O(N^2)
//Space Complextiy: O(1)
void helper(int x,stack<int>&st)
{
    if(st.empty() || x>st.top())
    {
        st.push(x);
        return;
    }
    int num=st.top();
    st.pop();
    helper(x,st);
    st.push(num);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
    if(stack.empty()) return;
    int x=stack.top();
    stack.pop();
    sortStack(stack);
    helper(x,stack);
    
}