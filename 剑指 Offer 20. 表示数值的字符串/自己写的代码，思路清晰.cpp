class Solution {
public:
    bool isDecimal(string s) {
        size_t n = s.size();
        if(n == 0) return false;
        size_t l = 0, r = 0, k = 0 , m = 0 , x = 0;
        if(s[l] == '+' || s[l] == '-') l++;
        while(l < n && s[l] >= '0' && s[l] <= '9') l++, x++; //x记录数字个数
        if(l < n && s[l] == '.') k++, l++; //k记录‘.’个数
        size_t y = l;
        while((y < n && s[y] >= '0' && s[y] <= '9')) m++, y++; //m记录数字个数
        if((x >= 1 && k == 1 && l == n) || (x >= 1 && k == 1 && m >= 1 && y == n) || (k == 1 && x == 0 && m >= 1 && y == n)) 
            return true;
        return false;
    }

    bool isInt(string s) {
        if(s.size() == 0) return false;
        size_t l = 0 , r = 0;
        if(s[l] == '+' || s[l] == '-') l++;
        while(s[l] >= '0' && s[l] <= '9') l++, r++; //r记录数字个数
        if(l == s.size() && r >= 1) return true;
        return false;
    }

    bool isNumber(string s) {
        size_t n = s.size();
        if(n == 0) return false; // 空串
        size_t l = 0, r = n - 1;
        while(l <= r && s[l] == ' ') l++;
        if(l > r) return false;
        while(l <= r && s[r] == ' ') r--;
        size_t idx_e = s.find('e');
        size_t idx_E = s.find('E');
        if(l > r || (idx_e != string::npos && idx_E != string::npos)) return false; // s里面都是空格 + 有e和E
        if((idx_e != string::npos && idx_E == string::npos)){ // 只有e或E
            if(l == idx_e) return false; // e or E前面为空串
            string str1 = s.substr(l,idx_e - l);
            if(r == idx_e){
                return false;
            }else{
                string str2 = s.substr(idx_e + 1,r - idx_e);
                return (isDecimal(str1) || isInt(str1)) && isInt(str2);
            }
        }else if(idx_E != string::npos && idx_e == string::npos){
            if(l == idx_E) return false; // e or E前面为空串
            string str1 = s.substr(l,idx_E - l);
            if(r == idx_E){
                return false;
            }else{
                string str2 = s.substr(idx_E + 1,r - idx_E);
                return (isDecimal(str1) || isInt(str1)) && isInt(str2);
            }
        }      
        else{ // e和E都没有
            string str1 = s.substr(l,r-l+1);
            return isInt(str1) || isDecimal(str1);
        }
        return false;
    }
};