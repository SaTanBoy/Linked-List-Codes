#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  node *next, *prev;
};
node *head = NULL;
void insert(int a) {
  node *temp;
  temp = new node;
  temp->data = a;
  temp->next = head;
  temp->prev = NULL;
  if (head != NULL) {
    temp->next->prev = temp;
  }
  head = temp;
}
void display() {
  node *temp;
  temp = head;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
}
void endinsert(int b) {
  node *temp, *ptr;
  temp = new node;
  temp->data = b;
  ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }
  ptr->next = temp;
  temp->next = NULL;
  temp->prev = ptr;
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
  cout << "enter the last element\n";
  cin >> b;
  endinsert(b);
  display();
  return 0;
}