//65. 有效数字
//有效数字（按顺序）可以分成以下几个部分：
//一个 小数 或者 整数
//（可选）一个 'e' 或 'E' ，后面跟着一个 整数
//小数（按顺序）可以分成以下几个部分：
//（可选）一个符号字符（'+' 或 '-'）
//下述格式之一：
//至少一位数字，后面跟着一个点 '.'
//至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
//一个点 '.' ，后面跟着至少一位数字
//整数（按顺序）可以分成以下几个部分：
//（可选）一个符号字符（'+' 或 '-'）
//至少一位数字
//部分有效数字列举如下：["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
//部分无效数字列举如下：["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
//给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。
//
//示例 1：
//输入：s = "0"
//输出：true
//示例 2：
//输入：s = "e"
//输出：false
//示例 3：
//输入：s = "."
//输出：false
//
//提示：
//1 <= s.length <= 20
//s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，或者点 '.' 。
#include "LeetCode65.hpp"
bool Solution::isNumber(string s){
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == 'e' || s[i] == 'E') {
            return (isDecimal(s.substr(0, i)) || isInteger(s.substr(0, i))) && isInteger(s.substr(i + 1, s.size() - 1));
        }
    }
    return isDecimal(s) || isInteger(s);
}
bool Solution::isDecimal(string s){
    //一个符号字符（'+' 或 '-'）
    if (s.size() && s[0] == '+' || s[0] == '-') {
        s.erase(0, 1);
    }
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            if (i == 0) {
                return isInteger(s.substr(i + 1, s.size() - 1));
            } else if (i == s.size() - 1) {
                return i >= 1 && isInteger(s.substr(0, i));
            } else {
                return isInteger(s.substr(0, i)) && isInteger(s.substr(i + 1, s.size() - 1));
            }
        }
    }
    return false;
}
bool Solution::isInteger(string s){
    //一个符号字符（'+' 或 '-'）
    if (s.size() && s[0] == '+' || s[0] == '-') {
        s.erase(0, 1);
    }
    return isIntegerWithoutSing(s);
}

bool Solution::isNumber(char c){
    return c == '0' || c == '1' || c == '2' || c == '3' || c == '4'
    || c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
}

bool Solution::isIntegerWithoutSing(string s){
    if (s.size() && isNumber(s[0])) {
        s.erase(0, 1);
        while (s.size()) {
            if (!isNumber(s[0])) {
                return false;
            }
            s.erase(0, 1);
        }
        return true;
    }
    return false;
}
//方法一：确定有限状态自动机
//预备知识
//确定有限状态自动机（以下简称「自动机」）是一类计算模型。它包含一系列状态，这些状态中：
//有一个特殊的状态，被称作「初始状态」。
//还有一系列状态被称为「接受状态」，它们组成了一个特殊的集合。其中，一个状态可能既是「初始状态」，也是「接受状态」。
//起初，这个自动机处于「初始状态」。随后，它顺序地读取字符串中的每一个字符，并根据当前状态和读入的字符，按照某个事先约定好的「转移规则」，从当前状态转移到下一个状态；当状态转移完成后，它就读取下一个字符。当字符串全部读取完毕后，如果自动机处于某个「接受状态」，则判定该字符串「被接受」；否则，判定该字符串「被拒绝」。
//注意：如果输入的过程中某一步转移失败了，即不存在对应的「转移规则」，此时计算将提前中止。在这种情况下我们也判定该字符串「被拒绝」。
//一个自动机，总能够回答某种形式的「对于给定的输入字符串 S，判断其是否满足条件 P」的问题。在本题中，条件 P 即为「构成合法的表示数值的字符串」。
//自动机驱动的编程，可以被看做一种暴力枚举方法的延伸：它穷尽了在任何一种情况下，对应任何的输入，需要做的事情。
//自动机在计算机科学领域有着广泛的应用。在算法领域，它与大名鼎鼎的字符串查找算法「KMP 算法」有着密切的关联；在工程领域，它是实现「正则表达式」的基础。
//问题描述
//在 C++ 文档 中，描述了一个合法的数值字符串应当具有的格式。具体而言，它包含以下部分：
//
//符号位，即 +、− 两种符号
//整数部分，即由若干字符 0−9 组成的字符串
//小数点
//小数部分，其构成与整数部分相同
//指数部分，其中包含开头的字符 e（大写小写均可）、可选的符号位，和整数部分
//在上面描述的五个部分中，每个部分都不是必需的，但也受一些额外规则的制约，如：
//
//如果符号位存在，其后面必须跟着数字或小数点。
//小数点的前后两侧，至少有一侧是数字。
//思路与算法
//根据上面的描述，现在可以定义自动机的「状态集合」了。那么怎么挖掘出所有可能的状态呢？一个常用的技巧是，用「当前处理到字符串的哪个部分」当作状态的表述。根据这一技巧，不难挖掘出所有状态：
//初始状态
//符号位
//整数部分
//左侧有整数的小数点
//左侧无整数的小数点（根据前面的第二条额外规则，需要对左侧有无整数的两种小数点做区分）
//小数部分
//字符 e
//指数部分的符号位
//指数部分的整数部分
//下一步是找出「初始状态」和「接受状态」的集合。根据题意，「初始状态」应当为状态 0，而「接受状态」的集合则为状态 2、状态 3、状态 5 以及状态 8。换言之，字符串的末尾要么是空格，要么是数字，要么是小数点，但前提是小数点的前面有数字。
//
//最后，需要定义「转移规则」。结合数值字符串应当具备的格式，将自动机转移的过程以图解的方式表示出来：
//比较上图与「预备知识」一节中对自动机的描述，可以看出有一点不同：
//我们没有单独地考虑每种字符，而是划分为若干类。由于全部 10 个数字字符彼此之间都等价，因此只需定义一种统一的「数字」类型即可。对于正负号也是同理。
//在实际代码中，我们需要处理转移失败的情况。为了处理这种情况，我们可以创建一个特殊的拒绝状态。如果当前状态下没有对应读入字符的「转移规则」，我们就转移到这个特殊的拒绝状态。一旦自动机转移到这个特殊状态，我们就可以立即判定该字符串不「被接受」。
//代码
//可以很简单地将上面的状态转移图翻译成代码：
//class Solution {
//public:
//    enum State {
//        STATE_INITIAL,
//        STATE_INT_SIGN,
//        STATE_INTEGER,
//        STATE_POINT,
//        STATE_POINT_WITHOUT_INT,
//        STATE_FRACTION,
//        STATE_EXP,
//        STATE_EXP_SIGN,
//        STATE_EXP_NUMBER,
//        STATE_END
//    };
//
//    enum CharType {
//        CHAR_NUMBER,
//        CHAR_EXP,
//        CHAR_POINT,
//        CHAR_SIGN,
//        CHAR_ILLEGAL
//    };
//
//    CharType toCharType(char ch) {
//        if (ch >= '0' && ch <= '9') {
//            return CHAR_NUMBER;
//        } else if (ch == 'e' || ch == 'E') {
//            return CHAR_EXP;
//        } else if (ch == '.') {
//            return CHAR_POINT;
//        } else if (ch == '+' || ch == '-') {
//            return CHAR_SIGN;
//        } else {
//            return CHAR_ILLEGAL;
//        }
//    }
//
//    bool isNumber(string s) {
//        unordered_map<State, unordered_map<CharType, State>> transfer{
//            {
//                STATE_INITIAL, {
//                    {CHAR_NUMBER, STATE_INTEGER},
//                    {CHAR_POINT, STATE_POINT_WITHOUT_INT},
//                    {CHAR_SIGN, STATE_INT_SIGN}
//                }
//            }, {
//                STATE_INT_SIGN, {
//                    {CHAR_NUMBER, STATE_INTEGER},
//                    {CHAR_POINT, STATE_POINT_WITHOUT_INT}
//                }
//            }, {
//                STATE_INTEGER, {
//                    {CHAR_NUMBER, STATE_INTEGER},
//                    {CHAR_EXP, STATE_EXP},
//                    {CHAR_POINT, STATE_POINT}
//                }
//            }, {
//                STATE_POINT, {
//                    {CHAR_NUMBER, STATE_FRACTION},
//                    {CHAR_EXP, STATE_EXP}
//                }
//            }, {
//                STATE_POINT_WITHOUT_INT, {
//                    {CHAR_NUMBER, STATE_FRACTION}
//                }
//            }, {
//                STATE_FRACTION,
//                {
//                    {CHAR_NUMBER, STATE_FRACTION},
//                    {CHAR_EXP, STATE_EXP}
//                }
//            }, {
//                STATE_EXP,
//                {
//                    {CHAR_NUMBER, STATE_EXP_NUMBER},
//                    {CHAR_SIGN, STATE_EXP_SIGN}
//                }
//            }, {
//                STATE_EXP_SIGN, {
//                    {CHAR_NUMBER, STATE_EXP_NUMBER}
//                }
//            }, {
//                STATE_EXP_NUMBER, {
//                    {CHAR_NUMBER, STATE_EXP_NUMBER}
//                }
//            }
//        };
//
//        int len = s.length();
//        State st = STATE_INITIAL;
//
//        for (int i = 0; i < len; i++) {
//            CharType typ = toCharType(s[i]);
//            if (transfer[st].find(typ) == transfer[st].end()) {
//                return false;
//            } else {
//                st = transfer[st][typ];
//            }
//        }
//        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
//    }
//};
//复杂度分析
//时间复杂度：O(n)，其中 n 为字符串的长度。我们需要遍历字符串的每个字符，其中状态转移所需的时间复杂度为 O(1)。
//空间复杂度：O(1)。只需要创建固定大小的状态转移表。
