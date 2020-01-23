class Solution {
public:
    bool isValid(string s) {
        return isOkString(s);
    }
    
    bool isClosedParentheses(char prev, char cur){
        if (prev == '(' && cur == ')'){
            return true;
        }else if (prev == '{' && cur == '}'){
            return true;
        }else if (prev == '[' && cur == ']'){
            return true;
        }else{
            return false;
        }
    }

    bool isUnmatchedClosedParentheses(char prev, char cur){
        if ((prev == '(' && cur == '}') || (prev=='(' && cur==']') ||(prev=='{' && cur==')') ){
            return true;
        }else{
            return false;
        }

    }


    bool isOkString(string givenStr){
        vector<char > charList;
        for (int i=0; i<givenStr.size(); i++){
            if (charList.size() > 0){
                char prev = charList.back();
                char cur = givenStr[i];
                if (isClosedParentheses(prev, cur)){
                    charList.pop_back();
                }else if (isUnmatchedClosedParentheses(prev, cur)){
                    return false;
                }else{
                    charList.push_back(cur);
                }
            }else{
                char cur = givenStr[i];
                if (cur == ')' || cur=='}' || cur==']'){
                    return false;
                }else{
                    charList.push_back(cur);
                }
            }
        }
        if (charList.size() > 0){
            return false;
        }else{
            return true;
        }
    }
};
