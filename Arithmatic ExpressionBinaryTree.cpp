#include <iostream>
#include <string>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    string val;
    Node *left, *right;
 
    Node(string val)
    {
        this->val = val;
        this->left = this->right = NULL;
    }
};
 
// Utility function to check if a given node is a leaf node
bool isLeaf(Node* node) {
    return (node->left == NULL && node->right == NULL);
}
 
// Function to apply an operator 'op' to values 'x' and 'y' and return the result
double process(string op, double x, double y)
{
    if (op == "+") { return x + y; }
    if (op == "-") { return x - y; }
    if (op == "*") { return x * y; }
    if (op == "/") { return x / y; }
 
    return 0;
}
 
// Recursive function to evaluate a binary expression tree
double evaluate(Node* root)
{
    // base case: invalid input
    if (root == NULL) {
        return 0;
    }
 
    // the leaves of a binary expression tree are operands
    if (isLeaf(root)) {
        return stod(root->val);
    }
 
    // recursively evaluate the left and right subtree
    double x = evaluate(root->left);
    double y = evaluate(root->right);
 
    // apply the operator at the root to the values obtained in the previous step
    return process(root->val, x, y);
}
 
int main()
{
    Node* root = new Node("+");
    root->left = new Node("*");
    root->right = new Node("/");
    root->left->left = new Node("-");
    root->left->right = new Node("5");
    root->right->left = new Node("21");
    root->right->right = new Node("7");
    root->left->left->left = new Node("10");
    root->left->left->right = new Node("5");
 
    cout << "The value of the expression tree is " << evaluate(root) << endl;
 
    return 0;
}
