def linear_search(alist, item):
    '''
    Sequentially search alist for the given item
    '''
    for pos, num in enumerate(alist):
        if num == item:
            return True, pos
    pos = -1
    return False, pos

def main():
    alist = [1,4,6,3,2,7,7,4,2,1]
    print(linear_search(alist, 2)) # True, 4
    print(linear_search(alist, 12)) # False, -1

main()
