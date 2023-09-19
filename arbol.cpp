#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(NULL), right(NULL) {}
};

class BinaryTree {
private:
    TreeNode* root;

    void insert(TreeNode*& node, int data) {
        if (node == NULL) {
            node = new TreeNode(data);
        } else {
            if (data < node->data) {
                insert(node->left, data);
            } else {
                insert(node->right, data);
            }
        }
    }

    void preOrderTraversal(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

public:
    BinaryTree() : root(NULL) {}

    void insert(int data) {
        insert(root, data);
    }

    void displayPreOrder() {
        preOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BinaryTree tree;

    cout << "Ingrese los datos para el arbol (0 para detenerse):\n";

    while (true) {
        int data;
        cout << "Ingrese un numero: ";
        cin >> data;

        if (data == 0) {
            break;
        }

        tree.insert(data);
    }

    cout << "Recorrido en preorden del arbol binario: ";
    tree.displayPreOrder();

    return 0;
}

