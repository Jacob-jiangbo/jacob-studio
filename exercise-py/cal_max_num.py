#!/usr/bin/python

import itertools

def ltoi(numlist):
    """ Transfer list to integer"""
    return int(''.join(map(str, numlist)))

def cal_max_num(num_list, num):
    """ Calulate max num via sublist 

    Args:
        num_list: a integer list
        num: part of sublist

    """
    max_num = 0

    items = list(itertools.combinations(set(num_list), num))
    
    for list_one in items:
        list_one = list(list_one)
        list_another = list(set(num_list) - set(list_one))
        
        list_another.sort(reverse=True)
        list_one.sort(reverse=True)

        temp_num = ltoi(list_one) * ltoi(list_another)
        
        if max_num < temp_num:
            max_num = temp_num
            final_list_one = list_one
            final_list_another = list_another

    print 'Max num is %d, one list is %r, the another list is %r' % (max_num, final_list_one, final_list_another)

if __name__ == '__main__':
    cal_max_num([5,6,7,8,9], 2)

