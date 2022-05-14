def myAppend(lst, elem):
    lst.append(elem)
    return lst

def flatten(lst, accum):
    if not lst:
        return accum
    if not isinstance(lst[0], list):
        return flatten(lst[1:], myAppend(accum, lst[0]))
    if isinstance(lst[0], list):
        accum = flatten(lst[0], accum)
    return flatten(lst[1:], accum)

if __name__ == '__main__':
    lst = [[1,2,3,4,[[5],[3,-2,[6,[1,[11,2,123,[127,[1],7],43]],110]]],[-1,[[[[3]]]]]],6,[11],7,8,9,10]
    print(lst[1:])
    result = flatten(lst, [])
    print(result)
    print(len(result))
