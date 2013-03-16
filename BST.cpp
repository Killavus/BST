/**
 * Simple Binary Search Tree Implementation.
 *
 * Author: Marcin Grzywaczewski [killavus@gmail.com]
 * Institute of Computer Science, Wrocław, Poland
 *
 * 2013
 **/

#include "BST.h"

#include <cstdlib>

bool BST::empty() const {
  return root == NULL;
}

void BST::insert(int key, double value) {
  if(empty())
    root = new Node(key, value);
  else {
    Node *parent = findParent(key);

    // Not the multiset.
    if(key == parent->key())
      return;
    
    Node *newNode = new Node(key, value);
    if(key < parent->key())
      parent->left = newNode;

    if(key > parent->key())
      parent->right = newNode;

    newNode->parent = parent;
  }
}

void BST::drop(int key) {
  if(empty())
    return;

  Node *keyNode = findParent(key);

  if(keyNode->key() == key) {
    Node *successor = findSuccessor(keyNode);

    if(successor == NULL) { // No right subtree.
      if(root != keyNode) {
        if(keyNode->parent->left == keyNode)
          keyNode->parent->left = keyNode->left;
        else
          keyNode->parent->right = keyNode->left;
      }
      else root = keyNode->left;
    }
    else replaceWithSuccessor(keyNode, successor);
    
    keyNode->parent = NULL;
    keyNode->left   = NULL;
    keyNode->right  = NULL;
    delete keyNode;
  }
}

const Node* BST::find(int key) const {
  Node *node = findParent(key);

  if(node->key() == key)
    return node;
  else
    return NULL;
}

Node* BST::findParent(int key) const {
  Node *cursor = root;
  
  while(true) {
    if(key < cursor->key()) {
      if(cursor->left) cursor = cursor->left;
      else break;
    }
    else if(key > cursor->key()) {
      if(cursor->right) cursor = cursor->right;
      else break;
    }
    else break;
  }
  
  return cursor;
}

void BST::sort(int result[], int *len) const {
  int ptr = 0;
  *len = 0;

  if(empty())
    *len = 0;
  else inOrderPut(root, result, &ptr, len);
}

void BST::inOrderPut(Node *cursor, int result[], int *ptr, int *len) const {
  if(cursor->left)
    inOrderPut(cursor->left, result, ptr, len);

  result[(*ptr)++] = cursor->key();
  (*len)++;

  if(cursor->right)
    inOrderPut(cursor->right, result, ptr, len);
}

Node* BST::findSuccessor(Node *node) const {
  Node *cursor = node->right;
  while(cursor && cursor->left)
    cursor = cursor->left;

  return cursor;
}

void BST::replaceWithSuccessor(Node *node, Node *nodeSuccessor) {
  // Node's parent:
  if(node != root) {
    if(node->parent->left == node)
      node->parent->left = nodeSuccessor;
    else
      node->parent->right = nodeSuccessor;
  }
  else
    root = nodeSuccessor;

  // Node successor's parent:
  if(nodeSuccessor->parent->left == nodeSuccessor)
    nodeSuccessor->parent->left = NULL;
  else
    nodeSuccessor->parent->right = NULL;

  nodeSuccessor->parent = node->parent;

  // Node's children:
  nodeSuccessor->left = node->left;
  Node *mostRightChild = nodeSuccessor->right;

  // 1. Right subtree of node is NOW bigger than successor.
  // 2. The most right child of successor 
  //    is still SMALLER than node's right subtree.
  while(mostRightChild && mostRightChild->right)
    mostRightChild = mostRightChild->right;
  mostRightChild->right = node->right;
}
