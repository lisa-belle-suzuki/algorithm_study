class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length()==0){
            return 0;
        }
        if (haystack.length() < needle.length()){
            return -1;
        }
        for (int i=0; i<(haystack.length()-needle.length()+1); i++){
            bool isNeedleFound = true;
            for (int j=0; j<needle.length(); j++){
                if (haystack[i+j]!=needle[j]){
                    isNeedleFound = false;
                    break;
                }
            }
            if (isNeedleFound){
                return i;
            }
        }
        return -1;
    }
};