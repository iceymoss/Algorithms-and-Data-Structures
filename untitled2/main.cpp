#include <iostream>
using namespace std;
const int MAX = 10;

int main()
{
    int var[MAX] = {500, 100, 200,20,53,1000,35,976,4778,4322};
    int *ptr;

    //指针中的数组地址
    ptr = var;
    for (int i = 0; i < MAX; i++)
    {
        cout << "var[" << i <<"]的内存地址为：";
        cout << ptr << endl;
        cout << "var[" << i << "] 的值为 ";
        cout << *ptr << endl;
        cout << &ptr << endl;
        //移动到下一位置
        ptr++;
    }
    return 0;
}