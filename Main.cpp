/**
 * Simple Binary Search Tree Implementation - Testing Program.
 *
 * Author: Marcin Grzywaczewski [killavus@gmail.com]
 * Institute of Computer Science, Wrocław, Poland
 *
 * 2013
 **/

#include <cstdio>
#include "BST.h"

int main(void) {
  char C = 'X';
  int sizeCounter = 0;

  BST tree;
  while(C != 'Q') {
    scanf("%c", &C);

    int k;
    double v;
    if(C == 'I') {
      scanf("%d %lf", &k, &v);
      tree.insert(k, v);
      sizeCounter += 1;
    }
    else if(C == 'D') {
      scanf("%d", &k);
      tree.drop(k);
    }
    else if(C == 'F') {
      scanf("%d", &k);
      const Node* n = tree.find(k);
      if(n)
        printf("%d %lf\n", n->key(), n->value());
      else
        printf("Not found.\n");
    }
    else if(C == 'S') {
      int t[sizeCounter], len;
      tree.sort(t, &len);
      for(int i = 0; i < len; ++i)
        printf("%d ", t[i]);
      printf("\n");
    }
  }

  return 0;
}
