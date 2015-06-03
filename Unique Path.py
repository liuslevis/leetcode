# Recursive method, 7 RTE  1 WA  1 AC
# notice: need to write python more preciesly
class Solution:
    # @param {integer} m
    # @param {integer} n
    # @return {integer}
    def __init__(self):
        self.dic = {}
    def query_uniquePaths(self, m, n):
        if m == 0 and n == 0:
            return 1
        if m < 0 or n < 0:
            return 0
            
        key = "%d,%d"%(m,n)
        if key in self.dic.keys():
            return self.dic[key]
        else:
            a = self.query_uniquePaths(m-1, n) if m-1 >= 0 else 0
            b = self.query_uniquePaths(m, n-1) if n-1 >= 0 else 0
            self.dic[key] = a+b
            return a+b
            
    def uniquePaths(self, m, n):
        return self.query_uniquePaths(m-1,n-1)
        