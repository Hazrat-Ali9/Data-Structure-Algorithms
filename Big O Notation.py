'''
The efficiency and accuracy of algorithms have to be analysed to compare them and choose a specific algorithm for certain scenarios. The process of making this analysis is called Asymptotic analysis. It refers to computing the running time of any operation in mathematical units of computation.

For example, the running time of one operation is computed as f(n) and may be for another operation it is computed as g(n2). This means the first operation running time will increase linearly with the increase in n and the running time of the second operation will increase exponentially when n increases. Similarly, the running time of both operations will be nearly the same if n is significantly small.

Usually, the time required by an algorithm falls under three types −

Best Case − Minimum time required for program execution.

Average Case − Average time required for program execution.

Worst Case − Maximum time required for program execution.
'''

'''----------Constant Complexity-----------'''

def constant_algo(items):
    result = items[0]*items[0]
    print()

constant_algo([2,4,5,6])



'''----------Linear Complexity------------'''

def linear_algo(items):
    for item in items:
        print(item)

linear_algo([4,5,7,9])


'''----------Quardratic Complexity-----------'''

def quadratic_algo(items):
    for item in items:
        for item2 in items:
            print(item, ' ' , item)
quadratic_algo([3,4,6,8,9])

'''----------Complex Algorithm------------------'''

def complex_algo(items):

    for i in range(5):
        print('Python is awesome')

    for item in items:
        print(item)

    print('Big O')

complex_algo([4,5,7.6])


'''---------- Worst vs Best Case Complexity --------------'''
def search_algo(num, items):
    for item in items:
        if item == num:
            return True
        else:
            return False
nums = [2, 4, 6, 8, 10]

print(search_algo(2, nums))