#include <stdio.h>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) 
    {
        int i = 0;
        int find = 0;
        vector<int> result;
        unordered_map<int,int> _map;
        unordered_map<int,int>::const_iterator it;

        for(i = 0; i < static_cast<int>(nums.size()); ++i)
        {
            find = target - nums[i];
			it = _map.find(find);
            if ( it != _map.end() && it->second != i)
            {
                result.push_back(i);
                result.push_back(it->second);
            }
            
            _map[nums[i]] = i;
            
        }
        
        return result;
    }
};

int main()
{
	vector<int> nums = {2, 7, 11, 15};
	int target = 17;
	
	vector<int> result = Solution::twoSum(nums, target);
	
	if (result.size() == 0)
	{
		printf("not found Solution\n");
	}
	else
	{
		for(vector<int>::iterator it = result.begin();
			it != result.end(); ++it)
		{
			printf("i = %d\n", *it);
		}

	}
	

	printf("sizeof(class):%d\n", sizeof(Solution));
	return 0;
}



