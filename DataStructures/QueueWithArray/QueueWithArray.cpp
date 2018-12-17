#include <cstring>

constexpr int size = 5;

namespace queuewitharray
{
class Queue
{
public:
  enum { Capacity = size + 1 };
  Queue() : _front(0), _rear(0) {
    std::memset(_array, 0, sizeof _array);
  }

  void enqueue(const int element);
  int dequeue();
  bool isEmpty() const;
  bool isFull() const;

private:
  int _array[Capacity];
  int _front;
  int _rear;
};

void Queue::enqueue(const int element) {
  if (!isFull()) {
    _array[_rear] = element;
    _rear = (_rear + 1) % Capacity;
  }
}

int Queue::dequeue() {
  if (isEmpty()) {
    return -1;
  }

  const int element = _array[_front];
  _front = (_front + 1) % Capacity;
  return element;
}

bool Queue::isEmpty() const {
  return (_rear == _front);
}

bool Queue::isFull() const {
  return  (_rear + 1) % Capacity == _front;
}

}


int main()
{
  using namespace queuewitharray;
  Queue q;
  q.isEmpty();
  q.enqueue(1);
  q.enqueue(2);
  q.enqueue(3);
  q.enqueue(4);
  q.enqueue(5);
  q.enqueue(6);
  q.isFull();

}