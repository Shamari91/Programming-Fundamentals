
namespace stackwithlinkedlist
{

struct Node
{
  Node(const int data) : _next(nullptr), _data(data) { }

  Node* _next;
  int _data;
};

class Stack
{
public:
  Stack() : _root(nullptr) {}

  void push(const int element);
  void pop();
  bool isEmpty() const;
  int peek() const;

private:
  Node* _root;
};

void Stack::push(const int element) {
  Node* node = new Node(element);
  node->_next = _root;
  _root = node;
}

void Stack::pop() {
  if (isEmpty()) {
    return;
  }

  Node* temp = _root;
  _root = _root->_next;
  delete temp;
}

int Stack::peek() const {
  if (isEmpty()) {
    return 0;
  }

  return _root->_data;
}

bool Stack::isEmpty() const {
  return !_root;
}

}

int main()
{
  using namespace stackwithlinkedlist;
  Stack stack;
  
  stack.push(1);
  stack.push(2);
  stack.push(3);

  stack.pop();

  stack.peek();

  stack.isEmpty();
}