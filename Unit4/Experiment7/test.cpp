#include <iostream>
#include "SeQueueFunction.cpp"
#include "DeQueueFunction.cpp"
using namespace std;

// 计算最大序号差
int findMaxIndexDifference(vector<int> &nums)
{
    map<int, DouQueue> lastIndex;
    int ans = 0;

    // 初始化队列并记录每个数字的出现位置
    for (int i = 0; i < nums.size(); ++i)
    {
        if (lastIndex.find(nums[i]) == lastIndex.end() || lastIndex[nums[i]].head == nullptr)
        {
            DouQueue q;
            InitQueue(q);
            lastIndex[nums[i]] = q;
        }
        EnQueueTail(lastIndex[nums[i]], i);
    }

    // 遍历每个队列，计算最大序号差
    for (auto &pair : lastIndex)
    {
        int x = pair.first;
        DouQueue &pos = pair.second;
        if (QueueLength(pos) > 1)
        {
            int first;
            DeQueueHead(pos, first);
            int second;

            while (QueueLength(pos) > 0)
            {
                GetHead(pos, second);

                bool judge = true;
                for (int k = first + 1; k < second; ++k)
                {
                    if (nums[k] < x)
                    {
                        judge = false;
                        break;
                    }
                }

                if (judge)
                {
                    ans = max(ans, second - first);
                }
                else
                {
                    first = second;
                }
                DeQueueHead(pos, second);
            }
        }
    }

    return ans;
}

int main()
{
    SeQueue q;

    // 初始化队列
    InitQueue(q);
    cout << "初始化队列完成." << endl;

    // 入队
    for (int i = 1; i <= 25; ++i)
    {
        EnQueue(q, i);
        cout << "入队: " << i << endl;
    }

    // 遍历队列
    cout << "当前队列: ";
    QueueTraverse(q);

    // 获取队列长度
    cout << "当前队列长度: " << QueueLength(q) << endl;

    // 获取队头元素
    ElemType head;
    if (GetHead(q, head))
    {
        cout << "队头元素: " << head << endl;
    }
    else
    {
        cout << "获取队头元素失败." << endl;
    }

    // 出队
    for (int i = 1; i <= 25; ++i)
    {
        ElemType e;
        if (DeQueue(q, e))
        {
            cout << "出队: " << e << endl;
        }
        else
        {
            cout << "出队失败." << endl;
        }
    }

    // 再次遍历队列
    cout << "当前队列: ";
    QueueTraverse(q);

    // 清空队列
    ClearQueue(q);
    cout << "队列已清空." << endl;

    // 判断队列是否为空
    if (QueueEmpty(q))
    {
        cout << "队列为空." << endl;
    }
    else
    {
        cout << "队列不为空." << endl;
    }

    // 销毁队列
    DestroyQueue(q);
    cout << "队列已销毁." << endl;

    cout << endl;

    vector<int> nums1 = {1, 2, 3, 2, 1};
    int maxDiff = findMaxIndexDifference(nums1);
    cout << "nums1最大序号差: " << maxDiff << endl;

    vector<int> nums2 = {1, 2, 0, 2, 1};
    maxDiff = findMaxIndexDifference(nums2);
    cout << "nums2最大序号差: " << maxDiff << endl;

    vector<int> nums3 = {1, 0, 1, 2, 1};
    maxDiff = findMaxIndexDifference(nums3);
    cout << "num3最大序号差: " << maxDiff << endl;

    return 0;
}
