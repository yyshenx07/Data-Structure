//删除有序数组中的重复项
//快慢指针 我写的
class Solution {
public://时间复杂度O(n) 空间O(1)
    int removeDuplicates(vector<int>& nums) { 
        int k=0;
        for(int i=0;i<nums.size()-1;i++)   //size() 越界[i+1]
        {
            if(nums[i]!=nums[i+1])//这里[i++]会让i叠加
            {
                nums[k++]=nums[i];
            }
        }
        nums[k++] = nums[nums.size() - 1];   // ← 补上最后一个
        return k;
    }
};

//deepseek's answer
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;   // 空数组特判

        int k = 0;                        // k 指向最后一个保留的元素
        for (int i = 1; i < nums.size(); i++) {       //递增的非跳跃可以[k]=[i]
            if (nums[i] != nums[k]) {     // 遇到新元素
                k++;                      // 先挪位置
                nums[k] = nums[i];        // 再写进去
            }
        }
        return k + 1;                     // 长度 = 下标 + 1
    }
};
//方法2：相邻比较法
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] != nums[i + 1]) {
                nums[k++] = nums[i];
            }
        }
        nums[k++] = nums[nums.size() - 1];  // 补最后一个
        return k;
    }
};
