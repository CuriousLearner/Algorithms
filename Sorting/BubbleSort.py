def Bubble_Sort(alist):
    '''
    Sorting the alist through Bubble Sort
    '''
    for passnum in range(len(alist)-1, 0, -1):
        for i in range(passnum):
            if alist[i] > alist[i+1]:
                alist[i], alist[i+1] = alist[i+1], alist[i]
    return alist

def main():
    alist = [6, 4, 2, 1, 7, 9, 6, 23, 21, 56, 90, 3]
    print(Bubble_Sort(alist))

main()
