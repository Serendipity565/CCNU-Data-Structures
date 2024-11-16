#include "SeQueueFunction.cpp"
#include "StackFunction.cpp"

using namespace std;

SeQueue que; // 过道队列
SqStack sta; // 车库
SqStack tmp; // 缓冲栈

void Menu()
{
    char choice;
    cout << "##############################" << endl;
    cout << "#       停车场管理系统       #" << endl;
    cout << "#      进入停车场(输入A)     #" << endl;
    cout << "#      离开停车场(输入D)     #" << endl;
    cout << "#       退出系统(输入0)      #" << endl;
    cout << "##############################" << endl;
}

void show()
{
    cout << "当前停车场状态:有" << StackLength(sta) << "量车" << endl;
    cout << "------------------------------" << endl;
    StackTraverse(sta);
    cout << "------------------------------" << endl;
    cout << "当前过道情况:有" << QueueLength(que) << "量车" << endl;
    cout << "------------------------------" << endl;
    QueueTraverse(que);
    cout << "------------------------------" << endl;
}

int main()
{
    InitQueue(que);
    InitStack(sta);
    InitStack(tmp);

    char op;
    ElemType car;
    Menu();
    show();
    while (1)
    {
        cout << "请输入操作:";
        cin >> op;
        op = toupper(op);
        if (op == 'A')
        {
            cout << "请输入车牌:";
            cin >> car;
            if (StackLength(sta) == sta.stacksize)
            {
                cout << "车位已满,无法进入!存入过道" << endl;
                EnQueue(que, car);
            }
            else
            {
                Push(sta, car);
            }
            show();
        }
        else if (op == 'D')
        {
            cin >> car;
            ElemType now;
            while (!StackEmpty(sta))
            {
                Pop(sta, now);
                if (now == car)
                {
                    break;
                }
                else
                {
                    Push(tmp, now);
                }
            }
            if (now != car)
            {
                cout << "找不到此车辆!" << endl;
            }
            while (!StackEmpty(tmp))
            {
                Pop(tmp, now);
                Push(sta, now);
            }
            if (!QueueEmpty(que))
            {
                DeQueue(que, now);
                Push(sta, now);
            }
            show();
        }
        else if (op == '0')
        {
            break;
        }
        else
        {
            cout << "输入不合法,请重新输入!" << endl;
        }
    }
    DestroyQueue(que);
    DestroyStack(sta);
    DestroyStack(tmp);
}