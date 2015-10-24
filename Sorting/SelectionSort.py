def Selection_Sort(alist):
    '''
    Sorting alist via Selection Sort
    '''
    for fillslot in range(len(alist)-1, 0, -1):
        positionOfMax = 0
        for i in range(1, fillslot+1):
            if alist[i] > alist[positionOfMax]:
                positionOfMax = i
        alist[fillslot], alist[positionOfMax] = alist[positionOfMax], alist[fillslot]
    return alist

def main():
    alist = [3, 45, 56, 1, 12, 67, 97, 22, 3]
    print(Selection_Sort(alist))

main()
