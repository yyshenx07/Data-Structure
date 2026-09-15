//移除元素
//1.暴力删除 覆盖元素
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //int length=0;
        //for(int i:nums)
        //{
        //    length++;
        //}
        int length = nums.size();   // ← 换掉那个循环
        int count = 0;
        for(int i = 0; i < length; i++)
        {
            if(nums[i] == val)
            {
                count++;
                for(int j = i; j < length - 1; j++)
                {
                    nums[j] = nums[j+1];
                }
                i--;                // ← 关键的一行(漏掉会跳元素)
            }
        }
        return length - count;
    }
};
