# Author: Andrew Hsu

import math

str_num = input().strip()
nums = [int(c) for c in str_num]

def rotate_recur(nums, l_ind, r_ind, moves, carries, l_carry, res):
    next_l_carry = False
    l_num = nums[l_ind]
    if l_carry:
        l_num += 1
    if l_num == 10:
        l_num = 0
        next_l_carry = True
    r_num = nums[r_ind]
    if carries:
        moves_without_carrying = l_num + 10 - r_num
        moves_with_carrying = moves_without_carrying - 1

        if l_ind == 0:
            res[0] = min(res[0], moves + moves_without_carrying)
            return

        rotate_recur(nums, l_ind - 1, r_ind + 1, moves + moves_without_carrying, False, next_l_carry, res)
        rotate_recur(nums, l_ind - 1, r_ind + 1, moves + moves_with_carrying, True, next_l_carry, res)
    else:
        if l_num < r_num:
            return
        moves_without_carrying = max(l_num, r_num) - min(l_num, r_num)

        if l_ind == 0:
            res[0] = min(res[0], moves + moves_without_carrying)
            return

        rotate_recur(nums, l_ind - 1, r_ind + 1, moves + moves_without_carrying, False, next_l_carry, res)

        if r_num < 9:
            moves_with_carrying = max(l_num, r_num + 1) - min(l_num, r_num + 1)
            rotate_recur(nums, l_ind - 1, r_ind + 1, moves + moves_with_carrying, True, next_l_carry, res)


start = math.ceil(len(nums) / 2)
res = [float('inf')]
if len(nums) > 1:
    rotate_recur(nums, len(nums) - start - 1, start, 0, False, res)
else:
    res[0] = 0
print(res[0])
