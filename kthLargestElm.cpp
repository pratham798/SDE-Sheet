//Approach 1
//Time Complexity: O(nlogn)
//Space Complexity: O(n)

vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    sort(arr.begin(),arr.end());
    return {arr[k-1],arr[n-k]};
}

//Approach 2
//Time Complexity: O(k+(n-k)log(k))
//Space Complexity: O(n)

int minheap(vector<int> &arr, int n, int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0;i<arr.size();i++) pq.push(arr[i]);
    while(k-->1) pq.pop();
    return pq.top();
}
int maxheap(vector<int> &arr, int n, int k)
{
    priority_queue<int>pq;
    for(int i=0;i<arr.size();i++) pq.push(arr[i]);
    while(k-->1) pq.pop();
    return pq.top();
}
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Write your code here.
    int small=minheap(arr,n,k);
    int large=maxheap(arr,n,k);
    return {small,large};
}

//Approach 3(Quick sort)
//Time Complexity: O(n)
//Space Complexity: O(1)

int partition(vector<int>& arr, int left, int right) {
    int pivot = arr[left] ;
    int l = left + 1 ;
    int r = right;
    while (l <= r) {
        if (arr[l] < pivot && arr[r] > pivot) {
            swap(arr[l], arr[r]);
            l++ ;
            r-- ;
        }
        if (arr[l] >= pivot) {
            l++;
        }
        if (arr[r] <= pivot) {
            r--;
        }
    }
    swap(arr[left], arr[r]);
    return r;
}

int kth_Largest_Element(vector<int>& arr, int k) {
    int left = 0, right = arr.size() - 1, kth;
    while (1) {
        int idx = partition(arr, left, right);
        if (idx == k - 1) {
            kth = arr[idx];
            break;
        }
        if (idx < k - 1) {
            left = idx + 1;
        } else {
            right = idx - 1;
        }
    }
    return kth;
}