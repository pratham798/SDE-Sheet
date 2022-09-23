// Time Complexity: O(N)
// Space Complexity: O(amount)

int findMinimumCoins(int amount) 
{
    // Write your code here
    vector<int>coins={1000,500,100,50,20,10,5,2,1};
    int count=0,i=0;
    while(amount>0)
    {
        if(amount>=coins[i])
        {
            int limit=amount/coins[i];
            amount=amount-(coins[i]*limit);
            count+=limit;
        }
        else
        {
            while(coins[i]>amount) i++;
        }
    }
    return count;
}