#include <iostream>
#include <vector>

struct Node {
  char data;
  Node *next;
};

class LinkedList {
public:  // property
  int size() {
    Node *head = root;
    int count = 0;
    while (head->next) {
      count++;
      head = head->next;
    }
    return count;
  }

public: // Functionalities
  void printList() {
    Node *head = root;
    while (head->next) {
      head = head->next;
      printf("%d ", head->data);
    }
    std::cout << std::endl;
  }

public:
  Node *root;

  // Construct Node

  Node *makeNode(char data) {
    Node *node = new Node;
    node->data = data;
    node->next = nullptr;
    return node;
  }

  void fromArray(std::vector<char> data){
    Node* head = root;
    int n = data.size();
    for(int i=0; i<n; i++){
      head->next = makeNode(data[i]);
      head = head->next;
    }
  }

  // Init

  LinkedList() { root = makeNode('*'); }
  LinkedList(std::vector<char> data){
    root = makeNode('*');
    fromArray(data);
  }

  // Insert

  void insertAtEnd(char data) {
    Node* head = root;
    while (head->next) {
      head = head->next;
    }
    Node* newNode = makeNode(data);
    head->next = newNode;
  }

  void insertAtFront(char data) {
    Node *head = root->next;
    Node *newNode = makeNode(data);
    newNode->next = head;
    root->next = newNode;
  }

  void insertAt(int index, char data){
    Node* head = root;
    if(!head->next){
      std::cout << "Index Out Of Range!" << std::endl;
      return;
    }

    for(int i=0; i<index; i++){
      head = head->next;
      if(!head->next){
        std::cout << "Index Out Of Range!" << std::endl;
        return;
      }
    }

    Node* node = makeNode(data);
    Node* next = head->next;
    head->next = node;
    node->next = next;
  }

  // Free

  void deleteAt(int index) {
    Node *temp = root;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
      if (!temp->next) {
        std::cout << "Index Out Of Range!" << std::endl;
        return;
      }
    }
    Node *head = temp->next;
    Node *next = head->next;
    temp->next = next;
    free(head);
  }

  void freeAll(int size) {
    Node* head;
    Node *temp = root->next;
    for (int i = 0; i < size-1; i++) {
      head = temp;
      temp = temp->next;
      free(head);
    }
    free(temp);
    root->next = nullptr;
  }
};

int main() {
  LinkedList list;
  list.insertAtEnd(10);
  list.insertAtEnd(5);
  list.insertAtEnd(6);
  list.insertAtEnd(7);
  list.insertAtFront(11);
  list.insertAtFront(1);
  list.printList();
  list.insertAt(0, 3);
  list.printList();

  std::vector<char> data = {1, 2, 3, 4};
  LinkedList InitList(data);
  InitList.printList();
}
