#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 判断链表是否有环，并返回环的入口节点
ListNode *detectCycle(ListNode *head)
{
    if (!head)
    {
        return nullptr;
    }

    ListNode *slow = head, *fast = head;

    // 快慢指针移动，检测是否有环
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // 有环，找环的入口
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // 返回环的入口节点
        }
    }

    return nullptr; // 没有环
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(3);
    ListNode *fourth = new ListNode(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second; // 形成环，第四个节点指向第二个节点

    ListNode *cycleStart = detectCycle(head);
    if (cycleStart)
    {
        cout << "环的入口节点值是: " << cycleStart->val << endl;
    }
    else
    {
        cout << "链表没有环" << endl;
    }

    return 0;
}
