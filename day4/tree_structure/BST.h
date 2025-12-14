#include "Node.h"

class employee
{
private:
    Node* root = NULL;

    // ====== DELETE NODE IN BST ======
    Node* delNode(Node* node, int key)
    {
        if (node == NULL)
            return NULL; // Key not found

        // Search for the key
        if (key < node->ID)
            node->left = delNode(node->left, key);
        else if (key > node->ID)
            node->right = delNode(node->right, key);

        else
        {
            // ====== CASE 1: No left child ======
            if (node->left == NULL)
            {
                Node* temp = node->right;
                delete node;
                return temp; // Replace deleted node
            }

            // ====== CASE 2: No right child ======
            if (node->right == NULL)
            {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // ====== CASE 3: Two children ======
            // Get inorder successor (smallest in right subtree)
            Node* succ = getSuccessor(node);

            // Copy successor's data into this node
            node->ID = succ->ID;
            node->name = succ->name;
            node->age = succ->age;
            node->work = succ->work;

            // Delete successor from right subtree
            node->right = delNode(node->right, succ->ID);
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
        int balance = getBalance(node);

        // Left-Left case
        if (balance > 1 && getBalance(node->left) >= 0)
            return RR(node);

        // Left-Right case
        if (balance > 1 && getBalance(node->left) < 0)
        {
            node->left = LR(node->left);
            return RR(node);
        }

        // Right-Right case
        if (balance < -1 && getBalance(node->right) <= 0)
            return LR(node);

        // Right-Left case
        if (balance < -1 && getBalance(node->right) > 0)
        {
            node->right = RR(node->right);
            return LR(node);
        }

    }

    // ====== GET NODE HEIGHT IN BST ======

    int getHeight(Node* node)
    {
        return node ? node->height : 0;
    }
    // ====== GET NODE BALANCE IN BST ======
    int getBalance(Node* node)
    {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* RR(Node* y)
    {
        Node* x = y->left;
        Node* z = x->right; // right child of x

        x->right = y;
        y->left = z;

        y->height = max(getHeight(y->left), getHeight(y->right))+1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* LR(Node* x)
    {
        Node* y = x->right;
        Node* z = y->left;

        y->left = x;
        x->right = z;


        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

     // ====== INSERT NODE HELPER (RECURSIVE) ======
    Node* insertNode(Node* node, int key)
    {
        // Normal BST insertion
        if (node == NULL)
            return new Node(key);

        if (key < node->ID)
            node->left = insertNode(node->left, key);
        else if (key > node->ID)
            node->right = insertNode(node->right, key);
        else
            return node; // Duplicate key

        // Update height
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        // Get balance factor
        int balance = getBalance(node);

        // Left-Left case
        if (balance > 1 && key < node->left->ID)
            return RR(node);

        // Right-Right case
        if (balance < -1 && key > node->right->ID)
            return LR(node);

        // Left-Right case
        if (balance > 1 && key > node->left->ID)
        {
            node->left = LR(node->left);
            return RR(node);
        }

        // Right-Left case
        if (balance < -1 && key < node->right->ID)
        {
            node->right = RR(node->right);
            return LR(node);
        }

        return node;
    }

public:
    // ====== INSERT NODE IN BST ======
    void Insert(int key)
    {
        root = insertNode(root, key);
    }

    // ====== SEARCH NODE ======
    Node* Search(int key, Node* current = NULL)
    {
        if (current == NULL) current = root;
        if (current == NULL) return NULL;   // Empty tree

        if (current->ID == key)
            return current;

        if (key < current->ID)
            return Search(key, current->left);

        return Search(key, current->right);
    }

    // ====== DELETE FROM ROOT ======
    void Delete(int key)
    {
        root = delNode(root, key);
    }

    // ====== GET INORDER SUCCESSOR ======
    // Smallest node in the right subtree
    Node* getSuccessor(Node* node)
    {
        Node* current = node->right;
        while (current != NULL && current->left != NULL)
            current = current->left;
        return current;
    }

    // ====== GET MAX (right-most node) ======
    Node* GetMax(Node* node = NULL)
    {
        if (root == NULL)
            return NULL;  // Empty tree

        if (node == NULL)
            node = root;

        while (node->right != NULL)
            node = node->right;

        return node; // Largest key
    }

    // ====== GET MIN (left-most node) ======
    Node* GetMin(Node* current = NULL)
    {
        if (current == NULL)
            current = root;

        if (current == NULL)
            return NULL; // Empty tree

        while (current->left != NULL)
            current = current->left;

        return current; // Smallest key
    }
};
