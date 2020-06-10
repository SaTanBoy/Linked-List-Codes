#include <bits/stdc++.h>
using namespace std;
struct node {
  int roll;
  node *link;
};
node *head = NULL;
void insert(int a) {
  node *temp;
  temp = new node;
  temp->roll = a;
  temp->link = head;
  head = temp;
}
void display() {
  node *temp;
  temp = head;
  while (temp != NULL) {
    cout << temp->roll << " ";
    temp = temp->link;
  }
}
void dlt(int pos, int n) {
  node *ptr1, *ptr2;
  ptr1 = head;
  if (pos == 1) {

    head = ptr1->link;
    free(ptr1);
  } else if (pos == n) {
    ptr2 = ptr1->link;
    while (ptr2->link != NULL) {
      ptr2 = ptr2->link;
      ptr1 = ptr1->link;
    }
    ptr1->link = NULL;
    free(ptr2);
  } else {
    int ctr = 1;
    ptr2 = ptr1->link;
    while (ctr != pos - 1) {
      ptr2 = ptr2->link;
      ptr1 = ptr1->link;
      ctr++;
    }
    ptr1->link = ptr2->link;
    free(ptr2);
  }
}
int main() {
  int n, b, a, pos;
  cout << "enter size\n";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    insert(a);
  }
  display();
  cout << endl << "enter the position of the node to be deleted" << endl;
  cin >> pos;
  dlt(pos, n);
  display();
  return 0;
}