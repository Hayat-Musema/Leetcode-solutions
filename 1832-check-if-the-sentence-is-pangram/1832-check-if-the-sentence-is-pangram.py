class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        letters=["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
        sent_as_arr=list(sentence)
        for element in letters:
            if element not in sent_as_arr:
                return False
            
        return True
        