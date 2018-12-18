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
  SinglyLinkedList() : _head(nullptr), _tail(nullptr) {}

  void insertNode(const int element);
  void printList();

private:
  Node* _head;
  Node* _tail;
};

void SinglyLinkedList::insertNode(const int element) {
  Node* tmpNode = new Node(element);

  if (_head == nullptr) {
    _head = _tail = tmpNode;
    return;
  }

  _tail->_next = tmpNode;
  _tail = tmpNode;
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