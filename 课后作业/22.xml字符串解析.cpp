#include <iostream>
#include <string.h>
using namespace std;
// 解析xml字符串。
// xmlbuffer：待解析的xml字符串。
// fieldname：字段名。
// value：字段的值。
// ilen：字段值的最大长度，超出ilen的内容将会被丢弃，缺省取值0，表示不限长度。
// 返回值：如果xmlbuffer中存在fieldname的数据项，返回true，否则返回false。
// 注意，调用该函数的时候，必须保证value足够大，否则可能会造成内存泄漏。
// <bh>3</bh><name>西施</name><sex>女</sex><age>18</age><yz>漂亮</yz>

bool xmlbuffer(const char *xmlbuf, const char *fieldname, char *value, const size_t ilen = 0)
{
    if (xmlbuf == 0 || value == 0)
        return false; // 对形参进行合法性检查。
    size_t fieldnamelen = strlen(fieldname);
    char *sfieldname = new char[fieldnamelen + 3]; // 动态分配字段名开始标签的内存。
    char *efieldname = new char[fieldnamelen + 4]; // 动态分配字段名结束标签的内存。
    memset(sfieldname, 0, fieldnamelen + 3);
    memset(efieldname, 0, fieldnamelen + 4);
    strcpy(sfieldname, "<");
    strcat(sfieldname, fieldname);
    strcat(sfieldname, ">");
    strcpy(efieldname, "</");
    strcat(efieldname, fieldname);
    strcat(efieldname, ">");                  // name变为<name>和<name/>
    char *start = strstr(xmlbuf, sfieldname); // 搜索在xml字符串中，出现<name>的位置。
    char *end = strstr(xmlbuf, efieldname);   // 搜索在xml字符串中，出现</name>的位置。
    if (start == 0 || end == 0)
    {
        delete[] sfieldname;
        delete[] efieldname;
    }
    size_t valuelen = end - start - fieldnamelen - 2;
    // 从xml字符串中截取字段的值。
    strncpy(value, start + fieldnamelen + 2, valuelen);
    *(value+valuelen) = 0; // strncpy不会在dest后追加0
    delete[] sfieldname; delete[] efieldname;
    return true;
}

int main()

{ 
    char sex[21];
    xmlbuffer("<name>西施</name><sex>X</sex>", "sex", sex);
    cout << "sex=" << sex << endl;
}