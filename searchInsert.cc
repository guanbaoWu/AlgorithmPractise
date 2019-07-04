#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = 0;
        int mid = 0;
        
        if (nums.size() == 0)
            return 0;
        
        end = nums.size() - 1;
        mid = (end - start)/2;
        
        while(start < end)
        {   
            if (target == nums[start + mid])
            {
                return start + mid;
            }
            else if (target > nums[start + mid])
            {
                start += mid + 1;
            }
            else if (target < nums[start + mid])
            {
                end -= mid - 1;
            }
            
            mid = (end - start)/2;
        }
        
        if (target <= nums[start])
            return start;
        else
            return start + 1;
        
        
    }
};

int main()
{
    int a[] = {1,3,5,6};
    vector<int> v(a, a+sizeof(a)/sizeof(a[0]));
    
    Solution s;
    
    cout << s.searchInsert(v, 1);
    
    return 0;
}