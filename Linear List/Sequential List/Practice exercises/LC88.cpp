//合并两个有序数组
//嘿嘿，我的lj写法，我自己都笑了
//思路：以数组一为基础，比较大小插入数组二元素（向后移动数组一元素）
class Solution {//错误代码
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                if(nums2[j]<=nums1[i])
                {
                    for(int m=nums1.size()-1;m>i;m--)
                    {
                        nums1[m]=nums1[m-1];
                    }
                    nums1[i]=nums2[j];
                }
            }
        }
    }
};
//AI帮助修改后代码
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len = m;                       // nums1 当前有效长度
        for(int j = 0; j < n; j++)         // 遍历 nums2 每个元素
        {
            int i = 0;
            while(i < len && nums1[i] <= nums2[j]) i++;   // 找插入位置
            
            for(int k = len; k > i; k--)   // 从后往前搬，腾出位置
            {
                nums1[k] = nums1[k-1];
            }
            nums1[i] = nums2[j];           // 插入
            len++;                          // 有效长度 +1
        }
    }
};
//我自己后来想的：nums2直接贴到nums1后面，然后排序算法
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];   // 直接把 nums2 放到 nums1 后面
        }
        sort(nums1.begin(), nums1.end());
    }
};
