#include<iostream>
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node* newNode(int data)
    {
        Node *node = new Node;
        node->data=data;
        node->left=nullptr;
        node->right=nullptr;

        return node;
    }
};

class BST
{
    Node *root = nullptr;
public:
    void inOrder(Node *temp)
    {
      if(temp != nullptr)
        {
          inOrder(temp->left);
          printf("%d ",temp->data);
          inOrder(temp->right);
        }

    }
    void mirror(Node *temp)
    {
        Node *curr = temp;
        if(curr == nullptr)
            return;
        Node *t = curr->left;
        curr->left=curr->right;
        curr->right=t;

        if(curr->left)
            mirror(curr->left);
        if(curr->right)
            mirror(curr->right);

    }
};

int main()
{
    BST b;
    Node n;
    Node *root = n.newNode(1);
    root->left = n.newNode(2);
    root->right = n.newNode(3);
    root->left->left = n.newNode(4);
    root->left->right = n.newNode(5);

    std::cout<<"Inorder before mirror: "<<std::endl;
    b.inOrder(root);
    b.mirror(root);
    std::cout<<"\nInorder After mirror: "<<std::endl;
    b.inOrder(root);
}