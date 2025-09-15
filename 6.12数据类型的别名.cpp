#include <iostream>         // 包含头文件。
using namespace std;        // 指定缺省的命名空间。

int main()
{
    // 1）为名称复杂的类型创建别名，方便书写和记忆。
	
    // 语法：typedef 原数据类型名 别名;
    typedef unsigned int uint;
    typedef long long llong;
    typedef unsigned long long ullong;
    uint a; llong b; ullong c;
    cout<<sizeof(a)<<endl; cout<<sizeof(b)<<endl; cout<<sizeof(c)<<endl;

    // 2）创建与平台无关的数据类型，提高程序的兼容性。
    // 在VS中，short是两个字节，int是四个字节，long也是四个字节，long long是八个字节。
	typedef short         int16_t;    // 16位的整数。
	typedef int             int32_t;    // 32位的整数。
	typedef long long       int64_t;    // 64位的整数。
	// 在Linux中，short是两个字节，int是四个字节，long也是八个字节，long long也是八个字节。
	typedef short         int16_t;    // 16位的整数。
	typedef int             int32_t;    // 32位的整数。
	typedef long          int64_t;    // 64位的整数。
    // 在程序源代码中，只使用别名int16_t、int32_t、int64_t，不使用原名。写在头文件里
    
}