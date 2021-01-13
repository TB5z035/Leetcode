class Solution:
    def findKthBit(self, n: int, k: int) -> str:
        if k == 1 and n == 1:
            return '0'
        elif k == (1 << (n - 1)):
            return '1'
        elif k < (1 << (n - 1)):
            return self.findKthBit(n-1, k)
        else:
            res = self.findKthBit(n-1, (1 << n)-k)
            return '0' if res == '1' else '1'


if __name__ == '__main__':
    s = Solution()
    print(s.findKthBit(4, 11))
