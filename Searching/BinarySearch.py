def Binary_Search(alist, item):
    '''
    To find item in alist using Binary Search
    '''
    first = 0
    last = len(alist) - 1
    while first <= last:
        mid = (first + last) / 2
        if item == alist[mid]:
            pos = mid
            return True, pos
        elif item < alist[mid]:
            last = mid - 1
        else:
            first = mid + 1
    return False, -1

def main():
    alist = [1, 2, 4, 5, 6, 7, 8, 11, 15, 16, 17, 23, 28]
    print(Binary_Search(alist, 19)) # False, -1
    print(Binary_Search(alist, 5))  # True, 3

main()
