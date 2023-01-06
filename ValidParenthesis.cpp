// Approach 1 (map+heap)
//Time Complexity: O(N)
//Space Complextiy: O(N)

bool isValidParenthesis(string exp)
{
    // Write your code here.
    stack<char>st;
    for(int i=0;i<exp.size();i++)
    {
        if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
        {
            st.push(exp[i]);
            continue;
        }
        if(!st.empty() and (exp[i]=='}' and st.top()=='{'||exp[i]==']' and st.top()=='['||exp[i]==')' and st.top()=='('))
        {
            st.pop();
        }
        else return false;
    }
    if(!st.empty()) return false;
    return true;
}