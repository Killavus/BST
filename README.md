Binary Search Tree
------------------

Compilation:
------------

`g++ Main.cpp BST.cpp -o <your executable name>`

Purpose:
--------

Mainly educational. Clean and rather simple implementation of a binary search
tree data structure. It's interface consists of these methods:
* `drop(key)` - delete the node of a given key
* `insert(key, value)` - insert the node of a given key. If a node exists in a
  tree already, it WON'T be added.
* `find(key)` - returns a node of a given key.
* `sort(table, length_ptr)` - returns a length and a table with sorted values 
  of keys.

License:
--------

Public domain.

