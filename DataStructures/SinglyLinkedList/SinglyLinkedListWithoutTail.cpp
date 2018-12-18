#include <cstring>
#include <iostream>

namespace linkedlist
{

struct Node
{
  Node(const int data) : _data(data), _next(nullptr) {}

  int _data;
  Node* _next;
};

class SinglyLinkedList
{
public:
  SinglyLinkedList() : _head(nullptr) {}

  void insertNode(const int element);
  void printList();

private:
  Node* _head;
};

void SinglyLinkedList::insertNode(const int element) {
  Node* createdNode = new Node(element);
  createdNode->_next = _head;
  _head = createdNode;
}

void SinglyLinkedList::printList() {
  Node* current = _head;
  while (current) {
    std::cout << current->_data << '\n';
    current = current->_next;
  }
}

}

int main()
{
  using namespace linkedlist;
  SinglyLinkedList linkedList;

  linkedList.insertNode(1);
  linkedList.insertNode(2);
  linkedList.insertNode(3);
  linkedList.insertNode(4);

  linkedList.printList();
}