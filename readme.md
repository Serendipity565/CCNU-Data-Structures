# CCNU-Data-Structures

《数据结构及应用算法教程》（严蔚敏 陈文博 编著）刘巍老师上机实验参考代码

## 第二单元：线性表

### 第一次实验：顺序表与集合合并

顺序表

* [顺序表的 12 种操作函数](https://github.com/serendipity565/CCNU-Data-Structures/blob/main/Unit2/Experiment1/SQListFunction.cpp)
* [顺序表的头文件](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit2/Experiment1/head.h)
* [用顺序表求两个集合的交集](https://github.com/serendipity565/CCNU-Data-Structures/blob/main/Unit2/Experiment1/SetFunction.cpp)
* [主函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit2/Experiment1/test.cpp)

### 第二次实验：单链表与集合合并

单链表

* [单链表的几种操作函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit2/Experiment2/LinkList.cpp)
* [单链表的头文件](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit2/Experiment2/head.h)
* [用单链表进行集合操作](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit2/Experiment2/SetFunction.cpp) (这里集合合并分为两个函数，只合并以及去重)
* [主函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit2/Experiment2/test.cpp)

### 第三次实验：线性表的应用（1.单链表的第一个公共节点；2.链表合并成递增有序链表）

线性表

* [头文件](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit2/Experiment3/head.h)
* [操作函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit2/Experiment3/LinkList.cpp)
* [主函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit2/Experiment3/test.cpp)

## 第三单元：排序

### 第四次实验：利用双向链表实现学生信息排序

双向链表

* [头文件](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit3/Experiment4/head.h)
* [操作函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit3/Experiment4/LinkList.cpp)
* [主函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit3/Experiment4/test.cpp)

## 第四单元：栈和队列

### 第五次实验：栈的实现与应用（判断出入栈顺序是否成立）

顺序栈

* [头文件](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment5/head.h)
* [栈相关函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment5/StackFunction.cpp)
* [主函数实现应用](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment5/test.cpp)

链栈

* [链栈相关函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment5/LinkStackFunction.cpp)

### 第六次实验

1. 括号配对检测：编写一个程序，通过输入表达式字符串，判别其中的开闭括号是否配对。
2. 回文检测：编写一个程序，通过输入表达式字符串，判别字符串是否是回文。
3. 递归算法找最大最小值：线性表 A(1……，n)，元素是整数，写出递归算法，求 A 中的最大和最小元素。

* [头文件](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment6/head.h)
* [栈相关函数(与上次实验相同)](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment6/StackFunction.cpp)
* [功能操作函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment6/Function.cpp)
* [主函数实现](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment6/test.cpp)

### 第七次实验

队列

1. 循环队列的表示与实现
2. 双端队列的表示与实现
3. 应用：已知n个整数，序号从1开始，在这n个数中存在满足如下条件的两个数：两个数相等，且它们之间的数不小于这两个数，在这n个数中可能存在多组满足上述条件的两个数，请设计算法找出满足上述条件的两个数序号之差的最大数。例如在(1，2，3，2，1)中，满足条件的两组数(1，1)和(2，2)，序号之差的最大值是4。

* [头文件](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment7/head.h)
* [循环队列](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment7/SeQueueFunction.cpp)
* [双端队列](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment7/DeQueueFunction.cpp)
* [主函数及应用的实现函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment7/test.cpp)

### 第八次实验

1. 堆栈的应用：中缀表达式求值

* [主函数及应用的实现函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment8/test.cpp)

### 第九次实验

1. 栈和队列的应用：停车场管理系统

* [头文件](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment9/head.h)
* [循环队列](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment9/SeQueueFunction.cpp)(在第七次实验的循环队列上对遍历队列`QueueTraverse`进行修改，并删去放入队列元素`EnQueue`的自动扩容功能)
* [栈](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment9/StackFunction.cpp)(在第七次实验的循环队列上对遍历队列`StackTraverse`进行修改，并删去放入栈顶元素`Push`的自动扩容功能)
* [主函数及应用的实现函数](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit4/Experiment9/test.cpp)

## 第五单元：串和数组

### 第十二次实验

稀疏矩阵

1. 假设稀疏矩阵A和B(具有相同大小m*n)都采用三元组存储，编写程序计算C=A+B，要求C也采用三元组存储。

* [稀疏矩阵](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit5/Experiment12/MatricesFunction.cpp)
* [主函数以及测试](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit5/Experiment12/test.cpp)

## 第六单元：树

### 第十次实验

二叉树(链式)

* [二叉树(链式)](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit6/Experiment10/TreeFunction.cpp)
* [主函数以及测试](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit6/Experiment10/test.cpp)

### 第十一次实验

1. 编写程序，根据给定先序遍历和中序遍历的结果创建二叉树。例如：先序遍历为ABCDEFGH，中序序列为CBEDFAGH，输出为后序遍历的结果为：CEFDBHGA
2. 以二叉链表为二叉树的存储结构，交换二叉树每个节点的左孩子和右孩子。
3. 编写程序，根据给定的字符序列（先序），创建二叉树，判断此二叉树是不是平衡二叉树。
平衡二叉树定义：可以是空树；假如不是空树，任何一个结点的左子树与右子树都是平衡二叉树，并且高度之差的绝对值不超过 1。
4. 已知二叉树采用二叉链表存储,编写程序据给定的字符序列（先序）生成二叉树，返回二叉树T的结点总数

* [二叉树相关函数(同上一次实验)](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit6/Experiment11/TreeFunction.cpp)
* [主函数、相关实现函数以及测试](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit6/Experiment11/test.cpp)

### 第十三次实验

1. 直观输出二叉树

这里我提供了两种思路，一种是类似于终端查看文件夹的树状结构，另一种是将二叉树转换为数组，再打印数组以实现树的直观输出

* [二叉树相关函数(同之前实验)](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit6/Experiment13/TreeFunction.cpp)
* [实现函数以及测试](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit6/Experiment13/test.cpp)

### 第十四次实验

1. 设计程序判断有n个节点的无头节点的单链表，是否存在环？若有环返回环的入口指针。如图所示为单链表，请查询是否有环，如果有环，返回指针P。
2. 给定一个含 n（n≥1）个整数的数组，请设计一个在时间上尽可能高效的算法，找出数组中未出现的最小正整数。(考虑：n个元素的数组可以存放的最小的正整数是从1起到n止。)

* [第一题](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit3/Experiment14/1.cpp)
* [第二题](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit3/Experiment14/2.cpp)

## 第七单元：图

### 第十五次实验

1. 二叉树的带权路径长度(WPL)是二叉树中所有叶结点的带权路径长度之和。给定一棵二叉树T，采用二叉链表存储，结点结构为：其中叶结点的weight域保存该结点的非负权值。设root为指向T的根结点的指针，请设计求T的WPL的算法。
2. 基于深度优先搜索策略设计算法，判别以邻接矩阵存储的有向图中是否存在由顶点vi到vj的路径(vi不等于vj)。
3. 基于深度优先搜索策略设计算法，判别以邻接矩阵存储的有向图中是否存在由顶点vi到vj的路径(vi不等于vj)。

* [第一题](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit7/Experiment15/1.cpp)
* [第二题](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit7/Experiment15/2.cpp)
* [第三题](https://github.com/Serendipity565/CCNU-Data-Structures/blob/main/Unit7/Experiment15/3.cpp)
