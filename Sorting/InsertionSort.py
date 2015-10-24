def Insertion_Sort(alist):
    '''
    Sorting alist via Insertion Sort
    '''
    for index in range(1, len(alist)):
        currentValue = alist[index]
        position = index
        while position > 0 and alist[position-1] > currentValue:
            alist[position] = alist[position-1]
            position = position - 1
        alist[position] = currentValue
    return alist

def main():
    alist = [3, 45, 56, 1, 12, 67, 97, 22, 3]
    print(Insertion_Sort(alist))

main()
