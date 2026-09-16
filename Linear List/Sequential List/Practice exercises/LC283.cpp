//移动零
// 1. 我写的 快慢指针+后续数组值归零--两趟
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[k++] = nums[i];
            }
        }                                          // STL算法
        for (int i = k; i < nums.size(); i++) {    // 用 fill 替代手写循环
                                                   // fill(nums.begin() + k, nums.end(), 0);
            nums[i] = 0;
        }
    }
};
// 2. 交换法
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                if (i != k) {
                    swap(nums[k], nums[i]);
                }
                k++;
            }
        }
    }
};
