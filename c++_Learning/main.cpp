#include <iostream>
#include <cstring>
#include <string.h>
#include "CStudents.h"
#include "CStudent.cpp"
#include<algorithm>
using namespace std;
int main(){
    CStudents stu;
    stu.setName("xiaoyang");
    stu.setNum("a1");
    stu.setScore(90);
    cout<<"姓名："<<stu.getName()<<"学号："<<stu.getNum()<<"数学成绩："<<stu.getScore()<<endl;
    return 0;
}














/*
 * class BOOKS{
private:
    char *name[10];
    char *author[10];
    float price;
public:
    char *getname(){
        return name;
    }
    char getauthor(){
        return author;
    }
    float getprince() {
        return price;
    }
    void
};
int main(){
    BOOKS books;

}
*/





/*
class students{
private:
    int name;
    int hao;
    float sorcs;

public:
    int  getNeam(){
        return name;
    }
    int getHao(){
        return hao;
    }
    float getSorcs(){
        return sorcs;
    }

};
int main(){


}
 */






/*
//定义一个共用体
union data{
    int CL; //不能用class
    char position[10];
};
//定义一个结构体
struct person{
    char *name;
    int num;
    char job;
    //定义一个类型为cat的变量
    //在结构体中调用共用体
    union data cat;
};

int main(){
    struct person stu;
    struct person tea;

    strcpy(stu.name, "xiaoyang");
    stu.num = 20202367029;
    stu.job = 'student';
    //CL表示班级
    stu.cat.CL = 33;

    strcpy((tea.name), "liu");
    tea.num = 100;
    tea.job = 'teach';
    //表示老师的职务：prof
    strcpy(tea.cat.position, "prof" );
}
*/




/*struct taobao{ //这里的beby是合法的类型它和int， float，char具有相同的作用
    char *name;
    float price;
    int maount;
    float totoy;
};
int main(){

    struct taobao store1; //淘宝店铺1
    struct taobao store2;//淘宝店铺2

    //店铺1的相应信息
    strcpy(store1.name, "连衣裙");
    store1.price = 200;
    store1.maount = 10;
    store1.totoy = store1.price * store1.maount;
    cout<<"name:";
    //店铺2的相应信息
    strcpy(store2.name, "卫衣");
    store2.price = 200;
    store2.maount = 10;
    store2.totoy = store2.price * store2.maount;
    //将两店铺的信息输出
    cout<<"name:"<<store1.name<<"price:"<<store1.price<<"maount:"<<store1.maount<<"total:"<<store1.totoy<<endl;
    cout<<"name:"<<store2.name<<"price:"<<store2.price<<"maount:"<<store2.maount<<"total:"<<store2.totoy<<endl;
    return 0;
}
 */








/*int main() {
    char *arr;
    arr = new char[20];
    cout<<"请输入字符:";
    cin.getline(arr, 20);
    cout<<arr<<endl;

    delete []arr;
}
 */


/*int main() {

    int arr[2][3];
    int *p_arr;
    for (int i = 0; i < 2; i++) {
        for (int j=0;j<3; j++){
            cin>>arr[i][j];
        }
    }
    p_arr = &arr[0][0];
    for(int i=0; i<6; i++) {
        if (*p_arr < 60) {
            cout << *p_arr << endl;
        }
        p_arr++;
    }
}*/


/*int main(){
    int n;
    float math[n];
    float max;
    float min;
    float *p_math;
    p_math = math;
    cout<<"请输入要计算的数量："<<endl;
    cin>>n;
    for(int i=0; i<n; i++){
            cin>>math[i];
    }
    max = min = math[0];
    for(int j=0; j<n; j++){
        if(*(p_math+j) > max){
            max = *(p_math+j);
        }
        if(*(p_math+j) < min){
            min = *(p_math);
        }
    }

    cout<<max<<","<<min<<endl;

    return 0;
}
 */



/*int learn( int lever, int red, int block){
    float sum;
    if(lever==4687) {
        sum = (red + lever) - block;
    }
    else if(lever== 4787){
        sum = (red +lever) - block;
    }
    else{
        cout<<"不存在该标准尺"<<endl;
    }
    return sum;
}
int main(){
    float daan;
    int l;
    int R;
    int B;
    cout<<"请输入标准尺：";
    cin>>l;
    cin>>R;
    cin>>B;
    daan = learn(l,R,B);
    cout<<daan<<endl;

}
 */



/*int main(){
    int n;
    int sum = 0;
    //定义一个指针
    int *p;
    cout<<"请输入班级的人数：";
    cin>>n;

    p = new int[n];
    if(!p){
        return 1;
    }
    cout<<"请输入班级成绩:"<<endl;
    for(int i=0;i<n; i++){
        cin>>p[i];
    }
    for(int i=0; i<n; i++){
        sum = sum + p[i];
    }
    cout<<"班级成绩为："<<sum/n<<endl;
    delete p;
    p = NULL;
    cout<<*p<<endl;
    cout<<&p<<endl;
    cout<<p<<endl;
    return 0;
}
 */



/*
 *int average(int *arr, int n){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
    }
    return sum/n;
}
int main(){
    int num;
    int arr1[6] = {2, 4, 6, 8, 10, 12};
    num = average(arr1, 6);
    cout<<num;
}
*/



/*int main(){
    float sum=0;
    int arr[2][3];
    //声明一个指针变量
    int *p_arr;
    //将指针指向arr索引为0的位置和一维数组的不同
    p_arr=arr[0];   //如果是一维数组则是：p_arr = arr;
    //使用双重遍历给二维素组赋值
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++){
            cin>>arr[i][j];
        }
    }

    for(; p_arr<arr[0]+6; p_arr++){
        //调用指针p_arr
        sum = sum + *(p_arr);
    }
    cout<<"sum="<<sum/6;
    cout<<p_arr<<endl;
    cout<<*p_arr<<endl;
    cout<<&arr[0]<<endl;
}
 */




/*
//构造一个float型的插入排序
float sort(float arr[], int n){
    for(int i=1; i<n; i++){

        for(int j=i;j>0; j--){

            if(arr[j]<arr[j-1])
                swap(arr[j], arr[j-1]);

            else if(arr[j] >= arr[j-1])
                break;
        }
    }
    return 0;
}

int main() {
    float sum;
    float *p_arr1;
    float arr1[5];
    //将指针指向arr1
    p_arr1 = arr1;

    //将数据放入数组中
    for(int i=0; i<5; i++ ) {
        cin >> arr1[i];
    }
    //todo

    sort(p_arr1,5);
    for(int i=0; i<5; i++) {
        sum + *(p_arr1 + i);
        cout << arr1[i] << endl;
    }

}
*/





/*int main(){
    int sum = 0;
    int score[5];
    int *p_score;
    //将数组score的地址传给指针
    p_score = score;
    for(int i=0; i<5; i++){
        cin>>score[i];
    }
    for(int j=0; j<5; j++){
        //*(p_score+j)必须用括号
        sum=sum + *(p_score+j);
    }
    cout<<sum;


}
*/







/*
int main() {

    float h = 190.5;
    //定义指针
    float* ht;
    //将h的地址传给指针
    ht = &h;
    cout<<h<<endl;//190.5
    cout<<ht<<endl;//h的地址
    cout<<*ht<<endl; //190.5
    cout<<&h<<endl;//h地址
}
*/




/*char arr[5][5]; //{{' ', ' ', '*', ' ', ' '}, {' ', '*', ' ', '*', ' '}, {'*', ' ', ' ', ' ', '*'},{' ', '*', ' ', '*', ' '}, {' ', ' ', '*', ' ', ' '} };
int main(){
    for(int i=0; i<5; i++){
        for(int j=0;j<5; j++){
            //scanf能接受字符型元素
            scanf("%c", &arr[i][j]);
        }
        //回车也算是一个字符，用getchar()函数将回车字符去掉
        getchar();
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}
 */




/*
//二维数组的定义，声明和调用
int arr[3][3];
int main() {
    for (int i = 0; i < 3; i++) {

        for (int j = 0; j < 3; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for(int j=0; j<3; j++){
            cout<<arr[i][j]<<",";
        }
    }
}
*/






/*int arr[3];
//使用插入排序进行排序
//使用模板函数
template<typename T>
int Sort(T arr[], int n)
{

    for(int i = 1; i<n; i++)
    {

        int j = i;
        for(j =i; j>0; j--)
        {
            if(arr[j] > arr[j-1])
            {
                break;
            }
            else if (arr[j] < arr[j-1])
            {
                swap(arr[j], arr[j-1]);
            }
        }
    }
    return 0;
}

int main(){
    
    int arr2[5];
int arr1[5] = {4, 5, 3, 2, 1};
    Sort( arr1, 5);
    for(int i=0; i<5;i++) {
        arr2[i] = arr1[i];
        cout << arr2[i] << endl;
    }
        cout<<arr2[0]<<endl;
        cout<<arr2[4]<<endl;

}*/






/*int cj(int n){
    if(n == 1){
        return 1;
    }
    else if(n > 1){
        return n*cj(n-1);
    }
}
int main(){
    int k, q;
    cin>>k;
     q = cj(k);
     cout<<q<<endl;

}
*/



/*int prinem(int k){
    if(k < 2){
        return -1;
    }
    for(int i = 2; i < k; i++){
        if(k%i == 0)
            return 0;
    }
    return 1;
}
int main(){
    int q;
    int to;
    cin>>q;
    to=prinem(q);
    if(to == 1){
        cout<<q<<"是素数";
    }
    else if(to == 0){
        cout<<q<<"不是素数";
    }
    else
        cout<<"输入不合法";
}
//
*/




/*int sort(int arr[], int n){
    for(int i = 1; i<n; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
            int j = i;
            for(j = i ; j>1; j--) {
                if (arr[j] < arr[j - 1]) {
                    swap(arr[j], arr[j - 1]);
                }
            }

        }
        else
            break;
    }
    return 0;
}

int add(int a1, int b1){
    return a1+b1;
}

int add(int a2,int b2, int c2){
    return a2+b2+c2;
}

float add(float a3, float b3){
    return a3+b3;
}
int main() {
    int r[4] = {2, 6, 1, 2};
    sort(r[4], 4);
    for (int i = 0; i < 4; i++)
        cout << r[i] << endl;
}
     /*int k= add(a,b);
    int q = add(a, b, c);
    float w = add(e, f, d);
        cout<<q<<endl;
        cout<<w<<endl;
        cout<<k<<endl;
}*/

/*void welcom(); //函数声明
int Year(int x) {
    welcom(); //嵌套调用
    if (x % 4 == 0 && x % 100 != 0) {
        cout << x << "是闰年" << endl;
    } else {
        cout << x << "是平年" << endl;
    }
}
void welcom(){
        cout<<"$$$$$$$$$$$$$$$$$$$$"<<endl;
        cout<<"￥￥￥￥￥￥￥￥￥￥￥￥"<<endl;
    }

int max_min(int k, int j){
    if(j<k) {
        cout << k;
        return k;
    }
    else
        cout<<j<<endl;
        return j;
}

int main() {
    int q;
    cin >> q;
    Year(q);
    int k,f;
    cin>>k>>f;
    max_min(k, f);
}
 */

//函数声明
//void list();
//tam为自定义的函数
//int atm(int total, int check) {
   // list();
   // if (total - check < 0) {
    //    cout << "余额不足" << endl;
    //} else {
     //   return total - check;
    //}
      //  cout << total - check << endl;

//}
//list为自定义的函数
//*void list(){
   // cout<<"************"<<endl;
   // cout<<"*  欢迎使用！   *"<<endl;
   // cout<<"************"<<endl;
//}
//year为自定义的函数
//void year(int y){

   // if(y%4==0&&y%100!=0){
    //    cout<<y<<"是闰年"<<endl;
    //}
    //else{
    //    cout<<y<<"不是闰年"<<endl;
    //}
//}

//int main() {
   // int x;
   // cin>>x;
   // year(x);
   // cout<<x<<endl;
    //double v;
   // double sum = 0;
   // double a = 1;
   // for(int i=1; i<=64; i++){
   //     sum = sum + a;
   //     a = a*2;
   // }
   // cout<<sum<<endl;



