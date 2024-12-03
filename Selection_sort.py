def selectionSort(itemList):
    n = len(itemList)

    for i in range(n-1):
        minValueIndex = i

        for j in range(i+1,n):
            if itemList[j] < itemList[minValueIndex]:
                minValueIndex = j

            if minValueIndex != i:
                temp = itemList[i]
                itemList[i] = itemList[minValueIndex]
                itemList[minValueIndex] = temp

    return itemList

el = [21,6,9,33,3]
print(selectionSort(el))

