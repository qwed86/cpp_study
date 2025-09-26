/*
在界面上输入超女数据后，按下列要求选出妃子、宫女和嬷嬷。
妃子：1）年龄18-25岁；2）身高165-178cm；3）身材火辣；4）颜值漂亮。
宫女：1）年龄18-30岁；2）身高160-165cm；3）身材火辣或者普通；4）颜值漂亮。
嬷嬷：1）年龄35-40岁；2）身高155-165cm；3）身材普通或者飞机场；4）颜值一般。
其它要求：
1）超女数据用结构体表示；
    struct st_girl {
        int age;
        int height;
        string sc;     // C++风格字符串。
        //char sc[31];  // C风格字符串。
        bool yz;	// true-漂亮；false-一般。
    } stgirl;
2）先输入超女全部的数据项，然后才进行选秀；
3）用逻辑表达式组合判断条件，不要用嵌套if语句。
*/
/*
strcmp(a, b) 比较两个 C 字符串（以 \0 结尾的 char[]）。
返回值：
0 表示 完全相等
<0 表示 a < b（按字典序）
>0 表示 a > b*/

#include <iostream>
#include <string.h>
using namespace std;
struct st_girl
{
    int age;    // 年龄
    int height; // 身高
    // string sc;  // C++风格字符串。
    char sc[31]; // C风格字符串。
    bool yz;     // true-漂亮；false-一般。
} stgirl;

main()
{ // 初始化结构体（string不能用memset）
    memset(&stgirl.age, 0, sizeof(stgirl));
    cout << stgirl.age << stgirl.height << stgirl.sc << stgirl.yz << endl; // 验证初始化效果
    // 输入超女数据

    cout << "请分别输入超女以下数据:" << endl;
    cout << "年龄：";
    cin >> stgirl.age;
    cout << "身高：";
    cin >> stgirl.height;
    cout << "身材(hot，general，plane)：";
    cin >> stgirl.sc;
    cout << "颜值(true-漂亮；false-一般)：";
    cin >> stgirl.yz;
    cout << stgirl.age << stgirl.height << stgirl.sc << stgirl.yz << endl;

    if ((18 <= stgirl.age && stgirl.age <= 25) &&
        (165 <= stgirl.height && stgirl.height <= 178) &&
        (strcmp(stgirl.sc, "hot") == 0) && (stgirl.yz))
    {
        cout << "妃子" << endl;
    }

    else if ((18 <= stgirl.age && stgirl.age <= 30) &&
             (160 <= stgirl.height && stgirl.height <= 165) &&
             ((strcmp(stgirl.sc, "hot") == 0) || (strcmp(stgirl.sc, "hot") == 0)) && (stgirl.yz))
    {
        cout << "宫女" << endl;
    }

    else if ((35 <= stgirl.age && stgirl.age <= 40) &&
             (155 <= stgirl.height && stgirl.height <= 165) &&
             ((strcmp(stgirl.sc, "hot") == 0) || (strcmp(stgirl.sc, "hot") == 0)) && (!stgirl.yz))
    {
        {
            cout << "嬷嬷" << endl;
        }
    }

    else
        cout << "不在范围内" << endl;
}