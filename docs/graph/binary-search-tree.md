---
title: Binary Search Tree
tags:
    - Tree
    - Binary Search
    - BST
---

A Binary tree is a tree data structure in which each node has at most two children, which are referred to as the left child and the right child.

For a binary tree to be a binary search tree, the values of all the nodes in the left sub-tree of the root node should be smaller than the root node's value. Also the values of all the nodes in the right sub-tree of the root node should be larger than the root node's value.

<figure markdown="span">
![a simple binary search tree](img/binarytree.png)
<figcaption>a simple binary search tree</figcaption>
</figure>

## Insertion Algorithm

1. Compare values of the root node and the element to be inserted.
2. If the value of the root node is larger, and if a left child exists, then repeat step 1 with root = current root's left child. Else, insert element as left child of current root.
3. If the value of the root node is lesser, and if a right child exists, then repeat step 1 with root = current root's right child. Else, insert element as right child of current root.

## Deletion Algorithm
- Deleting a node with no children: simply remove the node from the tree.
- Deleting a node with one child: remove the node and replace it with its child.
- Node to be deleted has two children: Find inorder successor of the node. Copy contents of the inorder successor to the node and delete the inorder successor.
- Note that: inorder successor can be obtained by finding the minimum value in right child of the node.

## Sample Code

```c
// C program to demonstrate delete operation in binary search tree 
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Given a non-empty binary search tree, return the node with minimum
   key value found in that tree. Note that the entire tree does not
   need to be searched. */
struct node * minValueNode(struct node* node)
{
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
```

## Time Complexity

The worst case time complexity of search, insert, and deletion operations is $\mathcal{O}(h)$ where h is the height of Binary Search Tree. In the worst case, we may have to travel from root to the deepest leaf node. The height of a skewed tree may become $N$ and the time complexity of search and insert operation may become $\mathcal{O}(N)$. So the time complexity of establishing $N$ node unbalanced tree may become $\mathcal{O}(N^2)$ (for example the nodes are being inserted in a sorted way). But, with random input the  expected time complexity is $\mathcal{O}(NlogN)$.

However, you can implement other data structures to establish Self-balancing binary search tree (which will be taught later), popular data structures that implementing this type of tree include:

- 2-3 tree
- AA tree
- AVL tree
- B-tree
- Red-black tree
- Scapegoat tree
- Splay tree
- Treap
- Weight-balanced tree
