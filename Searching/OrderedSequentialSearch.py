def Ordered_Sequential_Search(alist, item):
    '''
    Searches alist sequentially for finding item
    and stops if it finds a number > item
    '''
    for pos, num in enumerate(alist):
        if num == item:
            return True, pos
        else:
            if num > item:
                break
    pos = -1
    return False, pos

def main():
    alist = [1, 2, 4, 5, 6, 7, 8, 11, 15, 16, 17, 23, 28]
    print(Ordered_Sequential_Search(alist, 8))
    print(Ordered_Sequential_Search(alist, 9))

main()
