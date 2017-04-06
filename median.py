def findM(nums1, nums2):
    alist = []
    m = 0
    n = 0
        
    while m < len(nums1) and n < len(nums2):
        if nums1[m] <= nums2[n]:
            alist.append(nums1[m])
            m = m + 1
        else:
            alist.append(nums2[n])
            n = n + 1
                
    while m < len(nums1): # it means the nums2 run out
        alist.append(nums1[m])
        m = m + 1
            
    while n < len(nums2): # it means the nums1 run out
        alist.append(nums2[n])
        n = n + 1
        
    l = len(alist)
    if l % 2 == 0:
        median = (alist[l//2] + alist[l//2 + 1])/2.
        return median
            
    if l % 2 != 0:
        median = alist[l//2]
        return median


a = [1,3,4,5]
b = [4, 5, 7, 9, 20]
s = findM(a, b)
print(s)
