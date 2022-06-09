class Solution {
public:
    bool isNumber(string s) {
        typedef pair<char,int> charint;
        typedef unordered_map<char,int> unmap;
        vector<unmap> states = {
            unmap{charint(' ',0), charint('s',1),charint('d',2),charint('.',4)},
            unmap{charint('d',2),charint('.',4)},
            unmap{charint('d',2),charint('.',3),charint('e',5),charint(' ',8)},
            unmap{charint('d',3),charint('e',5),charint(' ',8)},
            unmap{charint('d',3)}, // 状态3，只有为数据时才可以重复
            unmap{charint('s',6), charint('d',7)},
            unmap{charint('d',7)},
            unmap{charint('d',7), charint(' ',8)},
            unmap{charint(' ',8)}
        };
        char cur;
        int curSt = 0;
        for(char c:s)
        {
            if(c == '+' || c == '-')
            {
                cur = 's';
            }else if(c >= '0' && c <= '9'){
                cur = 'd';
            }else if(c == 'e' || c == 'E'){
                cur = 'e';
            }else if(c == ' ' || c == '.'){
                cur = c;
            }else{
                cur = '?';
            }
            if(!states[curSt].count(cur)) return false;
            curSt = states[curSt][cur];
        }
        return curSt == 2 || curSt == 3 || curSt == 7 || curSt == 8;
    }
};