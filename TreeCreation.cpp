#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int n):data(n),left(nullptr),right(nullptr){
        cout << "Node creted Succesfully" << endl;
    }
};

class BinaryTree{
    public:
    TreeNode* root;
    
    BinaryTree(){
        root = nullptr;
    }
    
    void buildTree(){
        int data;
        cout << "Enter the root data value" << endl;
        cin >> data;
        if(data == -1){
            root = nullptr;
            return;
        }
        root = new TreeNode(data);
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            int rightData,leftData;
            cout << "Enter the left of " << current->data << ":   " << endl;
            cin >> leftData;
            cout << "Enter the right of " << current->data << ":   " << endl;
            cin >> rightData;
            if(leftData != -1){
                current -> left = new TreeNode(leftData);
                q.push(current->left);
            }
            if(rightData != -1){
                current -> right =new TreeNode(rightData);
                q.push(current->right);
            }
        }
        
    }
    
    void insert(int val){
        TreeNode* newNode = new TreeNode(val);
        if(!root){
            root = newNode;
            return
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current -> left){
                q.push(current->left);
            }else{
                current -> left = newNode;
                return;
            }
            
            if(current -> right){
                q.push(current->right);
            }else{
                current -> right = newNode;
                return;
            }
        }
    }
    
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        inorder(root->left);
        cout << root -> data << endl;
        inorder(root -> right);
    }
    
    void levelorder(TreeNode* root){
        if(!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            cout << current -> data <<" ";
            if(current->left) q.push(current->left);
            if(current->right) q.push(current -> right);
        }
        
    }
    
    void printlevelorder(){
        levelorder(root);
    }
    
};
int main(){
    cout << "---------Construction Of Tree------------" << endl;
    BinaryTree tree1;
    tree1.buildTree();
    BinaryTree tree2;
    tree2.buildTree();
    tree2.printlevelorder();
    
}
