def Short_Bubble_Sort(alist):
    '''
    Sorting alist using Short Bubble Sort
    '''
    passnum = len(alist) - 1
    exchangesDone = True
    while passnum > 0 and exchangesDone:
        exchangesDone = False
        for i in range(passnum):
            if alist[i] > alist[i+1]:
                exchangesDone = True
                alist[i], alist[i+1] = alist[i+1], alist[i]
        passnum = passnum - 1
    return alist

def main():
    alist=[20, 30, 40, 90, 50, 60, 70, 80, 100, 110]
    print(Short_Bubble_Sort(alist))

main()
