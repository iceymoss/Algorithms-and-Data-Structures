#include <iostream>
#include <queue>
#include <cassert>
using namespace std;

//套用模板函数
template <typename Key, typename Value>
class BST {
private:
    //构造节点Node
    struct Node {
        Key key;
        Value value;
        Node *left;
        Node *right;

        Node(Key key, Value value) {
            this->key = key;
            this->value = value;
            //初始值为空
            this->left = this->right = NULL;
        }
        Node(Node *node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
        }
    };

    //根节点
    Node *root;
    //节点数量
    int count;

public:
    BST() {
        //初始值为空
        root = NULL;
        count = 0;
    }

    ~BST() {
        distroy(root);
    }

    int size() {
        return count;
    }

    bool isEmpty() {
        return count == 0;
    }

    //插入操作
    void insert(Key key, Value value) {
        //向根节点中插入key， value
        root = insert(root, key, value);
    }

    //在树中寻找是否存在key
    bool contain(Key key) {
        return contain(root, key);
    }

    //找到key相应的节点并且返回value的地址
    Node *seacher(Key key, Value value) {
        return seacher(root, key, value);
    }

    //前序遍历,传入节点，打印节点相应信息
    void preOrder() {
        return preOrder(root);
    }

    //中序遍历，以节点为node的节点为根节点
    void inOrder() {
        return inOrder(root);
    }

    //后序遍历，以node为根节点的二分搜索树进行前序遍历，打印节点相应信息
    void postOrder() {
        return postOrder(root);
    }

    //层序遍历
    void levelOrder(){
        queue<Node*> q;
        q.push(root);
        //队列不为空的情况
        while(!q.empty()){
            Node *node  = q.front();
            q.pop();

            cout<<node->key<<endl;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }

    // 寻找二分搜索树的最小的键值
     Node* minmum(){
        assert(count != 0);
        Node* minnode = minmum(root);
        return minnode->left;
    }

    // 寻找二分搜索树的最大的键值
    Node* maxmum(){
        assert(count != 0);
        Node* maxnode = maxmum(root);
        return maxnode ->right;
    }

    //删除最小值的node
    void removeMin(){
        if(root)
            root = removeMin(root);
    }

    //删除最大值的node
    void removeMax(){
        if(root)
            root = removeMax(root);
    }

    //删除二分搜索树中值的任意节点
    void remove( Key key){
        root = remove(root, key);
    }

private:
    //插入操作
    //向以node为根节点的二分搜索树中，插入节点（key，value),使用递归算法
    //返回插入新节点后的二分搜索树的根
    Node *insert(Node *node, Key key, Value value) {
        if (node == NULL) {
            count++;
            return new Node(key, value);
        }

        if (key == node->key) {
            node->value = value;
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else //key < node->key
            node->left = insert(node->left, key, value);
    }

    //在二分搜索树中查找key，存在返回trun不存在返回false
    bool contain(Node *node, Key key) {
        //元素不存在
        if (key == NULL)
            return false;
        //元素存在
        if (key == node->key)
            return true;

        else if (key > node->key)
            return contain(node->right, key);

        else
            return contain(node->left, key);
    }

    //在二分搜索树中找到相应元素并返回该元素的地址
    Value *seacher(Node *node, Key key) {
        if (key == NULL)
            return NULL;
        //找到key 返回value的地址
        if (key == node->key)
            return &(node->value);

        else if (key > node->key)
            return seacher(node->right, key);

        else
            return seacher(node->left, key);
    }

    //前序遍历，以node为根节点的二分搜索树进行前序遍历，打印节点相应信息
    void preOrder(Node *node) {
        if (node != NULL) {
            //不一定用打印，还可以对node->key和node->value进行操作
            cout << node->key << endl;

            preOrder(node->left);

            preOrder(node->right);
        }
    }

    //中序遍历，以node为根节点的二分搜索树进行前序遍历，打印节点相应信息
    void inOrder(Node *node) {
        if (node != NULL) {
            inOrder(node->left);

            cout << node->key << endl;

            inOrder(node->right);
        }
    }

    //后序遍历，以node为根节点的二分搜索树进行前序遍历，打印节点相应信息
    void postOrder(Node *node) {
        if (node != NULL) {
            postOrder(node->left);

            postOrder(node->right);

            cout << node->key << endl;
        }
    }

    //析构函数的实现,其本质是后序遍历
    void distroy(Node *node) {
        if (node != NULL) {
            distroy(node->left);
            distroy(node->right);

            delete node;
            count--;

        }
    }
    // 寻找二分搜索树的最小的键值
    Node* minmum(Node* node){
            if(node != NULL){
                minmum(node->left);
            }
            return node;
    }
    // 寻找二分搜索树的最大的键值
    Node* maxmum(Node* node){
        if(node != NULL){
            maxmum(node->right);
        }
        return node;
    }

    // 从二分搜索树中删除最小值所在的节点
    Node* removeMin(Node* node){
        if(node->left == NULL){
            Node* NODE = node->right;
            delete node;
            count--;
            return NODE;
        }
        node->left = removeMax(node->left);
        return node;
    }
    //从二分搜索树中删除最大值所在的节点
    Node* removeMax(Node* node){
        if(node->right == NULL){
            Node* NODE = node->left;
            delete node;
            count--;
            return NODE;
        }
        node->right = removeMax(node->right);
        return node;
    }

    //删除二分搜索树中值的任意节点
    Node* remove(Node* node, Key key){
        //判断node是否为空
        if(node == NULL) {
            return NULL;
        }

       //先找到需要删除的值的node
        else if(key < node->key) {
            node->left =  remove(node->left, key);
            return node;
        }

        else if(key > node->key) {
            node->right = remove(node->right, key);
            return node;
        }

        //这里就找到了需要delete的node
        else {   //key == node->key)

            // 待删除节点左子树为空的情况
            if(node->left == NULL){
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }
            // 待删除节点右子树为空的情况
            if(node->right == NULL){
                Node* leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            // 待删除节点左右子树都不为为空的情况
            Node *succeer =new Node(minmum(node->right)); //找到最小key值的节点返回给succeer
            count ++;
            succeer->right = removeMin(node->right); //将最小key值的node删除，并将返回值给succeer的右孩子

            succeer->left = node->left;
            delete node;
            count--;
            return succeer;
        }

    }

};
void shuffle( int arr[], int n ){

    srand( time(NULL) );
    for( int i = n-1 ; i >= 0 ; i -- ){
        int x = rand()%(i+1);
        swap( arr[i] , arr[x] );
    }
}


// 测试 remove
int main() {

    srand(time(NULL));
    BST<int,int> bst = BST<int,int>();

    // 取n个取值范围在[0...n)的随机整数放进二分搜索树中
    int n = 10000;
    for( int i = 0 ; i < n ; i ++ ){
        int key = rand()%n;
        // 为了后续测试方便,这里value值取和key值一样
        int value = key;
        bst.insert(key,value);
    }
    // 注意, 由于随机生成的数据有重复, 所以bst中的数据数量大概率是小于n的

    // order数组中存放[0...n)的所有元素
    int order[n];
    for( int i = 0 ; i < n ; i ++ )
        order[i] = i;
    // 打乱order数组的顺序
    shuffle( order , n );

    // 乱序删除[0...n)范围里的所有元素
    for( int i = 0 ; i < n ; i ++ )
        if( bst.contain( order[i] )){
            bst.remove( order[i] );
            cout<<"After remove "<<order[i]<<" size = "<<bst.size()<<endl;
        }

    // 最终整个二分搜索树应该为空
    cout << bst.size() << endl;

    return 0;
}
