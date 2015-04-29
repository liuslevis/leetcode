class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        
        line = s.split()
        if len(line) == 0:
            return ""
        if len(line) == 1:
            return str(line[0])
        line.reverse()
        return reduce(lambda x,y:x+' '+y, line).strip()