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
void rem(int pos) {
  int x = 1;
  node *ptr;
  ptr = head;
  if (pos == 1) {
    head = head->next;
    head->prev = NULL;
    delete ptr;
  } else {
    while (x < pos) {
      ptr = ptr->next;
      x++;
    }
    if (ptr->next == NULL) {
      ptr->prev->next = NULL;
      delete ptr;
    } else {
      ptr->prev->next = ptr->next;
      ptr->next->prev = ptr->prev;
      delete ptr;
    }
  }
}
int main() {
  int n, a;
  cout << "enter size\n";
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    insert(a);
  }
  display();
  int pos;
  cout << "\nenter the position to be deleted";
  cin >> pos;
  rem(pos);
  display();
  return 0;
}