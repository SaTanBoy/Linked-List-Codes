#include <bits/stdc++.h>
using namespace std;
struct node {
  int data;
  node *next;
};
node *head = NULL;
void insert(int a) {
  node *ptr;
  node *temp = new node;
  temp->data = a;
  if (head == NULL) {
    temp->next = temp;
    head = temp;
  } else {
    temp->next = head;
    ptr = temp;
    do {
      ptr = ptr->next;
    } while (ptr->next != head);
    ptr->next = temp;
    head = temp;
  }
}
void endins(int b) {
  node *ptr = head;
  node *temp = new node;
  temp->data = b;
  do {
    ptr = ptr->next;
  } while (ptr->next != head);
  ptr->next = temp;
  temp->next = head;
}
void display() {
  node *ptr;
  ptr = head;
  do {
    cout << ptr->data << "  ";
    ptr = ptr->next;
  } while (ptr != head);
}
int main() {
  int n, b, a;
  cout << "enter size" << endl;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    insert(a);
  }
  display();
  cout << "enter last node";
  cin >> b;
  endins(b);
  display();
  return 0;
}