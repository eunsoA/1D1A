def solution(a, b, c, d):
    nums = [a,b,c,d]
    unique_nums = list(set(nums))
    count_dict = {num:nums.count(num) for num in unique_nums}
    
    if len(unique_nums) == 1: # 네 숫자가 모두 같은 경우
        return 1111*unique_nums[0]
    elif len(unique_nums) == 2: # 2개의 숫자가 같은 경우
        if 3 in count_dict.values() : # 3:1
            p = max(unique_nums, key = lambda x : count_dict[x])
            q = min(unique_nums, key = lambda x : count_dict[x])
            return  (10 * p + q)**2
        else : # 2:2
            p, q = unique_nums
            return (p+q) * abs(p-q)
            
    elif len(unique_nums) == 3: # 2 / 1 / 1
        p = max(unique_nums, key = lambda x : count_dict[x])
        q,r = [i for i in unique_nums if i!=p]
        return q*r
    else : # 네개의 숫자가 다 다른 경우
        return min(nums)