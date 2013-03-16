/**
 * Simple Binary Search Tree Implementation - Header Files.
 *
 * Author: Marcin Grzywaczewski [killavus@gmail.com]
 * Institute of Computer Science, Wrocław, Poland
 *
 * 2013
 **/
#ifndef __BST_H__
#define __BST_H__
#include <cstdlib>

class Node {
  public:
    Node(int __key, double __value) : _key(__key), _value(__value), 
      parent(NULL), left(NULL), right(NULL) {}

    ~Node() {
      delete left;
      delete right;

      if(parent) {
        if(parent->left == this)
          parent->left = NULL;

        if(parent->right == this)
          parent->right = NULL;
      }
    }

    Node *parent, 
         *left, 
         *right;

    int key() const {
      return _key;
    }

    double value() const {
      return _value;
    }

  protected:
    int _key;
    double _value;
};

class BST {
  public:
    BST() : root(NULL) {}
    bool empty() const;

    void insert(int key, double value);
    void drop(int key);

    const Node* find(int key) const;
    void sort(int result[], int *len) const;

  protected:
    Node* findParent(int key) const;
    Node* findSuccessor(Node *node) const;

    Node *root;
    void inOrderPut(Node *cursor, int result[], int *ptr, int *len) const;
    void replaceWithSuccessor(Node *node, Node *nodeSuccessor);
};
#endif //__BST_H__
