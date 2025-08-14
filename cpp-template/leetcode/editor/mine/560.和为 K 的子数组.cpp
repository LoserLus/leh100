/*
 * @lc app=leetcode.cn id=560 lang=cpp
 * @lcpr version=30202
 *
 * [560] 和为 K 的子数组
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include "../common/ListNode.cpp"
#include "../common/TreeNode.cpp"

using namespace std;

// @lc code=start
class Solution
{
public:
	int subarraySum(vector<int> &nums, int k)
	{
        if(nums.size()==1) return k==nums[0]?1:0;
		unordered_map<int, int> hashmap;
		int sum = 0;
		int res = 0;
        hashmap[sum] = 1;
        for(int i = 0;i<nums.size();i++)
        {
            sum+=nums[i];
            // presum[i+1] = sum;
            auto it = hashmap.find(sum-k);
			if (it != hashmap.end())
                {
                    res+=it->second;
                }
           it = hashmap.find(sum);
            if (it != hashmap.end())
                {
                    hashmap[sum] += 1;
                }
            else
                {
                    hashmap[sum] = 1;
                }
        }
		return res;
		// for (int i = 1; i < presum.size(); i++)
		// 	{
		// 		auto it = hashmap.find(presum[i]-k);
		// 		if (it != hashmap.end())
		// 			{
		// 				res += it->second;
		// 			}
				
		// 	}
		// return res;
	}
	// int get_presum(vector<int>& pre_sums, size_t left,size_t right)
	// {
	//     int sum =0;
	//     if(left==0) return pre_sums[right];
	//     return pre_sums[right]-pre_sums[left-1];
	// }
	// int subarraySum(vector<int>& nums, int k) {
	//     if(nums.size()==1) return k==nums[0]?1:0;
	//     vector<int> pre_sums(nums.size(),0);
	//     pre_sums[0] = nums[0];
	//     for(size_t i=1;i<nums.size();i++)
	//     {
	//         pre_sums[i]=pre_sums[i-1]+nums[i];
	//     }
	//     size_t cnt = 0;
	//     for(size_t left=0;left<nums.size();left++)
	//     {
	//         for(size_t right=left;right<nums.size();right++)
	//         {
	//             int sum = get_presum(pre_sums,left,right);
	//             if(sum==k) cnt++;
	//         }
	//     }
	//     return cnt;
	// int cnt = 0;
	// int sum = 0;
	// for(size_t left=0,right=0;right<nums.size();right++)
	// {
	//     sum+=nums[right];
	//     while(sum>k)
	//     {
	//         sum-=nums[left];
	//         left++;
	//     }

	//     if(sum==k) cnt++;
	// }
	// return cnt;

	// }
};
// @lc code=end

int main()
{
	Solution solution;
	// your test code here
	vector<int> input({1,1,-1,1,-1});
	int k = 1;
	int res = solution.subarraySum(input, k);
	cout << res << endl;
}

/*
// @lcpr case=start
// [1,1,1]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3]\n3\n
// @lcpr case=end

 */
