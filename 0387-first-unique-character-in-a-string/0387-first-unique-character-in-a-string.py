class Solution:
    def firstUniqChar(self, s: str) -> int:
        Ns=s.lower()
        str_as_arr=list(Ns)
        for i in range(len(str_as_arr)):
            not_dup=True
            for j in range ( len(str_as_arr)):
                if i!=j and str_as_arr[i]==str_as_arr[j]:
                    not_dup=False
                    break
            if not_dup:
                return i
    
        return -1
        