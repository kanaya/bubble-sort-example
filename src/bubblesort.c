#include <stdio.h>
#include <stdlib.h>

struct node {
  int num;
  struct node *next;
};

struct node *init(void) {
  struct node *node = (struct node *)calloc(1, sizeof(struct node));
  node->next = NULL;
  return node;
}

void append(struct node *top, const int num) {
  struct node *node = (struct node *)calloc(1, sizeof(struct node));
  struct node *p = top;
  node->num = num;
  node->next = NULL;
  while (p->next != NULL) {
    p = p->next;
  }
  p->next = node;
  return;
}

void swap(struct node *n0) {
  struct node *n1 = n0->next;
  struct node *n2 = n1->next;
  struct node *n3 = n2->next;
  n0->next = n2;
  n2->next = n1;
  n1->next = n3;
}

void swap_if_n1_gt_n2(struct node *n0) {
  struct node *n1 = n0->next;
  struct node *n2 = n1->next;
  if (n1->num > n2->num) {
    swap(n0);
  }
}

int length(struct node *top) {
  int count = 0;
  while (top) {
    ++count;
    top = top->next;
  }
  return count;
}

void sort(struct node *top) {
  int l = length(top);
  int i;
  for (i = 0; i < l; ++i) {
    struct node *t = top;
    while (t && t->next && t->next->next) {
      swap_if_n1_gt_n2(t);
      t = t->next;
    }
  }
}

void print(struct node *top) {
  struct node* p = top;
  printf(">> ");
  while (p->next != NULL) {
    printf("%d ", p->next->num);
    p = p->next;
  }
  printf("\n");
  return;
}

int main(void) {
  struct node *top = init();
  int i;
  srand(1234567890);
  for (i = 0; i < 10000; ++i) {
    int n = rand() % 1000;
    append(top, n);
  }
  print(top);
  
  sort(top);
  print(top);
  return 0;
}
