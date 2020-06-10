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
void endinsert(int b) {
  node *ptr1, *ptr2;
  ptr2 = new node;
  ptr2->roll = b;
  ptr1 = head;
  while (ptr1->link != NULL) {
    ptr1 = ptr1->link;
  }
  ptr2->link = NULL;
  ptr1->link = ptr2;
}
int main() {
  int n, b, a;
  cout << "enter size\n";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    insert(a);
  }
  display();
  cout << "enter last node\n";
  cin >> b;
  endinsert(b);
  display();
  return 0;
}