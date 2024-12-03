'''
####  Methods Available in Queue

Python provides the following methods, which are commonly used to perform the operation in Queue.

put(item) - This function is used to insert element to the queue.
get() - This function is used to extract the element from the queue.
empty() - This function is used to check whether a queue is empty or not. It returns true if queue is empty.
qsize - This function returns the length of the queue.
full() - If the queue is full returns true; otherwise false.

'''

'''Implementation Using List'''
print('-------------Implementation Using List--------------')
que = []

que.append('CSE')
que.append('EEE')
que.append('Civil')
que.append('ECE')

print(que)

print(que.pop(0))
print(que)

print(que.pop(0))
print(que)

print(que.pop(0))
print(que)

print(que.pop(0))
print(que)


'''Implementation Using List'''
print('--------------Implementation Using List----------------')
from collections import deque

q = deque()

q.append('ML')
q.append('DS')
q.append('Soft')
q.append('Networking')

print(q)

print(q.popleft())
print(q)

print(q.popleft())
print(q)

print(q.popleft())
print(q)

print(q.popleft())
print(q)


'''Implementation using queue.Queue'''
print('-------------Implementation using queue.Queue--------------')

from queue import Queue

qq = Queue(maxsize=4)

print(qq.qsize())

qq.put('a')
qq.put('b')
qq.put('c')
qq.put('d')

print(qq.full())


'''Queue Implementation'''
print('----------------Queue Implementation---------------')

# Implement Queue using List(Functions)
q=[]
def Enqueue():
    if len(q)==size: # check wether the stack is full or not
        print("Queue is Full!!!!")
    else:
        element=input("Enter the element:")
        q.append(element)
        print(element,"is added to the Queue!")
def dequeue():
    if not q:# or if len(stack)==0
        print("Queue is Empty!!!")
    else:
        e=q.pop(0)
        print("element removed!!:",e)
def display():
    print(q)
    size=int(input("Enter the size of Queue:"))
    while True:
        print("Select the Operation:1.Add 2.Delete 3. Display 4. Quit")
        choice=int(input())
        if choice==1:
            Enqueue()
        elif choice==2:
            dequeue()
        elif choice==3:
            display()
        elif choice==4:
            break
        else:
            print("Invalid Option!!!")


