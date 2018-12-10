#include <cstring>
#include <iostream>

constexpr int capacity = 100;

namespace stackwitharray
{
class Stack
{
public:
  Stack() : _top(-1) {
    std::memset(_array, 0, sizeof _array);
  }

  void push(const int element);
  void pop();
  int peek() const;
  bool isEmpty() const;

private:
  int _top;
  int _array[capacity];
};

void Stack::push(const int element) {
  if (_top >= capacity-1) {
    return;
  }

  _array[++_top] = element;
}

void Stack::pop() {
  if (_top < 0) {
    return;
  }
  
  --_top;
}

int Stack::peek() const {
  return _array[_top];
}

bool Stack::isEmpty() const {
  return (_top < 0);
}
}

int main()
{
  using namespace stackwitharray;
  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  stack.pop();

  std::cout << stack.peek();

  stack.isEmpty();
}