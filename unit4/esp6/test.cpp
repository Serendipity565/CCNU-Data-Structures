#include "Function.cpp"

using namespace std;

int main()
{
    string str1 = "(12+45)";
    string str2 = "23=[87a-45b(5*6)]";
    string str3 = "23=[87a-(45b]5*6)";

    if (CheckBalancedBrackets(str1))
    {
        cout << str1 << "：配对" << endl;
    }
    else
    {
        cout << str1 << "：不配对" << endl;
    }

    if (CheckBalancedBrackets(str2))
    {
        cout << str2 << "：配对" << endl;
    }
    else
    {
        cout << str2 << "：不配对" << endl;
    }

    if (CheckBalancedBrackets(str3))
    {
        cout << str3 << "：不配对" << endl;
    }
    else
    {
        cout << str3 << "：配对" << endl;
    }

    string str4 = "123654";
    string str5 = "12321";

    if (CheckPalindrome(str4))
    {
        cout << str4 << "：是回文" << endl;
    }
    else
    {
        cout << str4 << "：不是回文" << endl;
    }

    if (CheckPalindrome(str5))
    {
        cout << str5 << "：是回文" << endl;
    }
    else
    {
        cout << str5 << "：不是回文" << endl;
    }

    vector<int> values = {3, 5, 1, 8, 7, 2, 6};
    int max_value = FindMax(values, 0, values.size() - 1);
    int min_value = FindMin(values, 0, values.size() - 1);

    cout << "最大值：" << max_value << endl;
    cout << "最小值：" << min_value << endl;

    return 0;
}
