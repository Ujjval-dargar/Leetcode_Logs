from typing import List


class Solution:

    def count(self, a: List[int], x: int) -> int:
        ans = 0
        for i in a:
            if i == x:
                ans += 1
        return ans

    def majorityElement(self, nums: List[int]) -> int:
        n = len(nums)

        if n == 1:
            return nums[0]

        x = nums[: n // 2]
        y = nums[n // 2 :]

        l = self.majorityElement(x)
        r = self.majorityElement(y)

        cl = self.count(nums, l)
        cr = self.count(nums, r)

        if cl > n / 2:
            return l
        if cr > n / 2:
            return r

        return -1
