#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

// BstNode
// 结构体声明
typedef struct BstNode{
    int data;
    struct BstNode* left;
    struct BstNode* right;
}Node;

// 自定义函数列表
Node *getNewNode(int data);
Node *insertData(Node* root, int data);
bool search(Node* root, int data);
Node * inOrderTree(Node *root);


int main() {
    int test;

    // rootPtr = NULL;
    Node *rootPtr = NULL;
/*
 * 测试所用树的结构如下
 *                 15
               /        \
             10          20
           /    \       /   \
         8       14   18     22
       /  \                   \
     2    null                 30

*/
    // 测试数据填充
    // 测试，将测试数据依次插入，验证算法正确
    rootPtr = insertData(rootPtr, 15);
    rootPtr = insertData(rootPtr, 20);
    rootPtr = insertData(rootPtr, 10);
    rootPtr = insertData(rootPtr, 8);
    rootPtr = insertData(rootPtr, 22);
    rootPtr = insertData(rootPtr, 14);
    rootPtr = insertData(rootPtr, 18);
    rootPtr = insertData(rootPtr, 2);
    rootPtr = insertData(rootPtr, 30);

    inOrderTree(rootPtr);

    // 测试主体
    printf("Which data do you want to find?\n");
    scanf("%d",&test);
    if(search(rootPtr,test) == true){
        printf("Get it!\n");
    } else {
        printf("Sorry,can't find it!\n");
    }

    return 0;
}

// 中序遍历
Node * inOrderTree(Node *root){
    if(root == NULL){
        printf("Empty Node!\n");
        return false;
    }
    inOrderTree(root->left);
    printf("%d\n",root->data);
    inOrderTree(root->right);
}

// 得到节点将要写入的数据
Node *getNewNode(int insertData){
    Node *newNode = (Node*) malloc(sizeof (Node));
    newNode->data = insertData;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入
Node *insertData(Node* root, int data){
    // 如果rootPtr为空，赋值给根节点,简单的创建一个有数值的根节点，即创建一棵树
    // 1.在此对数据的修改仅在此函数的数据域中，需要将数据用return返回
    // 2.方法二是将函数写为: void insertData(Node** root,int data); 不过可能会难以理解
    if(root == NULL){
        root = getNewNode(data);
    } else if (data <= root->data){
        root->left = insertData(root->left, data);
    } else {
        root->right = insertData(root->right, data);
    }
    return root;
}

// 查找
bool search(Node* root, int data){
    // 如果根节点为空，返回false
    if(root == NULL){
        return false;
    } else if (root->data == data) {
        return true; // 如果根节点与所查找的数据相同，返回true
    } else if (data <= root->data) {
        return search(root->left, data);
        // 如果根节点与所查找的数据不同但是小于根节点，则向根节点的左侧查找
    } else {
        return search(root->right, data);
        // 如果根节点与所查找的数据不同但是大于根节点，则向根节点的右侧查找
    }
}