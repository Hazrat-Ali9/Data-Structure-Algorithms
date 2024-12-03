'''
The functions associated with stack are:

empty() – Returns whether the stack is empty – Time Complexity : O(1)
size() – Returns the size of the stack – Time Complexity : O(1)
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
pop() – Deletes the top most element of the stack – Time Complexity : O(1)
'''

'''Implementation using list:'''
print('----------Implementation using list-------------')
stack = []

stack.append('January')
stack.append('February')
stack.append('March')
stack.append('April')

print(stack)

print(stack.pop())
print(stack)

print(stack.pop())
print(stack)

print(stack.pop())
print(stack)

print(stack.pop())
print(stack)


'''Implementation using collections.deque'''
print('----------Implementation using collections.deque-------------')
from collections import deque

stack_de = deque()

stack_de.append('Book')
stack_de.append('pen')
stack_de.append('College')
stack_de.append('University')

print(stack_de)

print(stack_de.pop())
print(stack_de)

print(stack_de.pop())
print(stack_de)

print(stack_de.pop())
print(stack_de)

print(stack_de.pop())
print(stack_de)


'''Exaple Of Stack Implementation'''
print('-------------Exaple Of Stack Implementation---------------')

class Stack():
    def __init__(self):
        self.items = []

    def push(self,item):
        self.items.append(item)

    def pop(self):
        return self.items.pop()

    def is_emppty(self):
        return self.items == []

    def peek(self):
        if not self.is_emppty():
            return self.items[-1]

    def get_stack(self):
        return self.items

myStack = Stack()
myStack.push('Java')
myStack.push('Python')
myStack.push('Dart')
myStack.push('JavaScript')

print(myStack)

print('----test----')
print(myStack.peek())
print(myStack.is_emppty())
print(myStack.get_stack())



