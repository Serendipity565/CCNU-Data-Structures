#include <iostream>
#include <vector>
using namespace std;

// 找出数组中未出现的最小正整数
int FindFirstMissingNumber(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ve(n + 1); // 用来标记1~n是否出现
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] > 0 && nums[i] <= n)
        {
            ve[nums[i]] = 1; // 标记nums[i]出现
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        if (ve[i] == 0)
        {
            return i; // 返回第一个未出现的正整数
        }
    }
    return n + 1; // 如果1~n都出现了，则返回n+1
}

int main()
{
    vector<int> nums = {-5, 3, 2, 3};
    cout << "未出现的最小正整数是: " << FindFirstMissingNumber(nums) << endl;

    vector<int> nums2 = {1, 2, 3};
    cout << "未出现的最小正整数是: " << FindFirstMissingNumber(nums2) << endl;

    return 0;
}
