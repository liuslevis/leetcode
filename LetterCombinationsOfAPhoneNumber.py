class Solution:
    # @param {string} digits
    # @return {string[]}
    def letterCombinations(self, digits):
        res = []
        if len(digits) < 1:
            return res

        lettersOfBtn = ["", "", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"]
        for digit in digits:
            if len(res) == 0:
                for letter in lettersOfBtn[int(digit)]:
                    res.append(letter)
            else:
                tmpRes = []
                for eachRes in res:
                    for letter in lettersOfBtn[int(digit)]:
                        tmpRes.append(eachRes+letter)
                res = tmpRes
        
        return res