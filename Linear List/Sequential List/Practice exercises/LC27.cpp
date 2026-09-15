//移除元素
//1.暴力删除 覆盖元素
//我手写的，问题1：length复杂化 问题2：未添加i--;
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
/*分析：
外层循环最多执行 n 次（n 为数组长度）
每遇到一个 val，内层循环要搬动后面所有元素，最坏搬 n 次
如果数组全是 val，每次都要搬剩余全部元素：
第 1 次删：搬 n-1 次
第 2 次删：搬 n-2 次
…
第 n 次删：搬 0 次
总次数 = (n-1) + (n-2) + ... + 1 = n(n-1)/2 ≈ n²/2
结论：时间复杂度 O(n²)
最好的情况：数组里没有 val，外层走 n 次，内层不执行 → O(n)
最坏的情况：数组全是 val → O(n²)
平均情况：O(n²)（因为只要有一定比例的 val，就会退化）*/

//2.快慢指针
//notes：core:快的探路，慢的记录
int k = 0;
for(int i = 0; i < nums.size(); i++) {
    if(nums[i] != val) {
        nums[k++] = nums[i];
    }
}
return k;
/*分析：
只有一层循环，每个元素恰好被访问一次
合格元素最多被写一次，不合格元素不写
总操作次数 ≤ 2n（读 n 次 + 写最多 n 次）
结论：时间复杂度 O(n)，与数据分布无关*/

//3.首尾指针
int i = 0, j = nums.size() - 1;
while(i <= j) {
    if(nums[i] == val) {
        nums[i] = nums[j];
        j--;
    } else {
        i++;
    }
}
return i;
/*分析：
i 只增不减，j 只减不增，两者相遇时循环结束
每个元素最多被访问一次（要么 i 扫过，要么被 j 用来填补）
总操作次数 ≤ n
结论：时间复杂度 O(n)，与数据分布无关*/
