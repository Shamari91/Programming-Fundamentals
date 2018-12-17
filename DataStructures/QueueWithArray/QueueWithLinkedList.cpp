#include <cstring>

constexpr int size = 5;

namespace queuewithlinkedlist
{

struct Node
{
  Node(const int data) : _data(data), _next(nullptr) {}

  int _data;
  Node* _next;
};

class Queue
{
public:
  Queue() : _front(nullptr), _rear(nullptr) {}

  void enqueue(const int element);
  Node* dequeue();
  bool isEmpty() const;

private:
  Node* _front;
  Node* _rear;
};

void Queue::enqueue(const int element) {
  Node* temp = new Node(element);

  if (isEmpty()) {
    _front = _rear = temp;
    return;
  }

  _rear->_next = temp;
  _rear = temp;
}

Node* Queue::dequeue() {
  if (isEmpty()) {
    return nullptr;
  }

  Node* temp = _front;
  _front = _front->_next;
  
  if (_front == nullptr) {
    _rear = nullptr;
  }

  return temp;
}

bool Queue::isEmpty() const {
  return !_front;
}

}

int main()
{
  using namespace queuewithlinkedlist;
  
  Queue q;
  q.isEmpty();
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);
}