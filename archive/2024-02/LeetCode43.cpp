//43. 字符串相乘
//给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
//注意：不能使用任何内置的 BigInteger 库或直接将输入转换为整数。
//
//示例 1:
//输入: num1 = "2", num2 = "3"
//输出: "6"
//示例 2:
//输入: num1 = "123", num2 = "456"
//输出: "56088"
//
//提示：
//1 <= num1.length, num2.length <= 200
//num1 和 num2 只能由数字组成。
//num1 和 num2 都不包含任何前导零，除了数字0本身。
#include "LeetCode43.hpp"
string Solution::multiply(string num1, string num2){
    string result;
    result.resize(num1.size() + num2.size());
    for(size_t i = 0; i < num1.size() + num2.size(); i++){
        result[i] = '0';
    }
    int n1 = 0, n2 = 0, carry = 0, mul = 0;

    for(int i = num2.size() - 1; i >= 0; i--){
        for(int j = num1.size() - 1; j >= 0; j--){
            mul = (num2[i] - 48) * (num1[j] - 48) + carry + (result[i + j + 1] - 48);
            carry = mul / 10;
            result[i + j + 1] = mul % 10 + 48;
        }
        if(carry){
            result[i] = result[i] + carry;
            carry = 0;
        }
    }
    while(result.size() != 0 && result[0] == '0'){
        result.erase(result.begin());
    }
    return result == "" ? "0" : result ;
}
//方法一：做加法
//如果 num1 和 num2 之一是 0，则直接将 0 作为结果返回即可。
//如果 num1 和 num2 都不是 0，则可以通过模拟「竖式乘法」的方法计算乘积。从右往左遍历乘数，将乘数的每一位与被乘数相乘得到对应的结果，再将每次得到的结果累加。这道题中，被乘数是 num1 ，乘数是 num2 。
//需要注意的是，num2 除了最低位以外，其余的每一位的运算结果都需要补 0。
//对每次得到的结果进行累加，可以使用「415. 字符串相加」的做法。
//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        if (num1 == "0" || num2 == "0") {
//            return "0";
//        }
//        string ans = "0";
//        int m = num1.size(), n = num2.size();
//        for (int i = n - 1; i >= 0; i--) {
//            string curr;
//            int add = 0;
//            for (int j = n - 1; j > i; j--) {
//                curr.push_back(0);
//            }
//            int y = num2.at(i) - '0';
//            for (int j = m - 1; j >= 0; j--) {
//                int x = num1.at(j) - '0';
//                int product = x * y + add;
//                curr.push_back(product % 10);
//                add = product / 10;
//            }
//            while (add != 0) {
//                curr.push_back(add % 10);
//                add /= 10;
//            }
//            reverse(curr.begin(), curr.end());
//            for (auto &c : curr) {
//                c += '0';
//            }
//            ans = addStrings(ans, curr);
//        }
//        return ans;
//    }
//
//    string addStrings(string &num1, string &num2) {
//        int i = num1.size() - 1, j = num2.size() - 1, add = 0;
//        string ans;
//        while (i >= 0 || j >= 0 || add != 0) {
//            int x = i >= 0 ? num1.at(i) - '0' : 0;
//            int y = j >= 0 ? num2.at(j) - '0' : 0;
//            int result = x + y + add;
//            ans.push_back(result % 10);
//            add = result / 10;
//            i--;
//            j--;
//        }
//        reverse(ans.begin(), ans.end());
//        for (auto &c: ans) {
//            c += '0';
//        }
//        return ans;
//    }
//};
//复杂度分析
//时间复杂度：O(mn+n^2)，其中 m 和 n 分别是 num1 和 num2 的长度。需要从右往左遍历 num2 ，对于 num2 的每一位，都需要和 num1 的每一位计算乘积，因此计算乘积的总次数是 mn。字符串相加操作共有 n 次，相加的字符串长度最长为 m+n，因此字符串相加的时间复杂度是 O(mn+n^2)。总时间复杂度是 O(mn+n^2)。
//空间复杂度：O(m+n)，其中 m 和 n 分别是 num1 和 num2 的长度。空间复杂度取决于存储中间状态的字符串，由于乘积的最大长度为 m+n，因此存储中间状态的字符串的长度不会超过 m+n。
//
//方法二：做乘法
//方法一的做法是从右往左遍历乘数，将乘数的每一位与被乘数相乘得到对应的结果，再将每次得到的结果累加，整个过程中涉及到较多字符串相加的操作。如果使用数组代替字符串存储结果，则可以减少对字符串的操作。
//令 m 和 n 分别表示 num1 和 num2 的长度，并且它们均不为 0，则 num1 和 num2 的乘积的长度为 m+n−1 或 m+n。简单证明如下：
//如果 num1 和 num2 都取最小值，则 num1=10^m−1 ，num2=10^(n−1) ，num1×num2=10^(m+n−2) ，乘积的长度为 m+n−1；
//如果 num1 和 num2 都取最大值，则 num1=10^m−1 ，num2=10^n−1 ，num1×num2=10^(m+n)−10^m−10^n+1，乘积显然小于 10^(m+n) 且大于 10^(m+n−1) ，因此乘积的长度为 m+n。
//
//由于 num1 和 num2 的乘积的最大长度为 m+n，因此创建长度为 m+n 的数组 ansArr 用于存储乘积。对于任意 0≤i<m 和 0≤j<n，num1[i]×num2[j] 的结果位于 ansArr[i+j+1]≥10，则将进位部分加到 ansArr[i+j]。
//最后，将数组 ansArr 转成字符串，如果最高位是 0 则舍弃最高位。
//class Solution {
//public:
//    string multiply(string num1, string num2) {
//        if (num1 == "0" || num2 == "0") {
//            return "0";
//        }
//        int m = num1.size(), n = num2.size();
//        auto ansArr = vector<int>(m + n);
//        for (int i = m - 1; i >= 0; i--) {
//            int x = num1.at(i) - '0';
//            for (int j = n - 1; j >= 0; j--) {
//                int y = num2.at(j) - '0';
//                ansArr[i + j + 1] += x * y;
//            }
//        }
//        for (int i = m + n - 1; i > 0; i--) {
//            ansArr[i - 1] += ansArr[i] / 10;
//            ansArr[i] %= 10;
//        }
//        int index = ansArr[0] == 0 ? 1 : 0;
//        string ans;
//        while (index < m + n) {
//            ans.push_back(ansArr[index]);
//            index++;
//        }
//        for (auto &c: ans) {
//            c += '0';
//        }
//        return ans;
//    }
//};
//复杂度分析
//时间复杂度：O(mn)，其中 m 和 n 分别是 num1 和 num2 的长度。需要计算 num1 的每一位和 num2 的每一位的乘积。
//空间复杂度：O(m+n)，其中 m 和 n 分别是 num1 和 num2 的长度。需要创建一个长度为 m+n 的数组存储乘积。
//结语
//方法二还可以用另外一种方法改写。我们把两个数相乘看成是两个多项式相乘，因为任何一个数都可以表示成为
//∑i=0 n−1 ai×10^i
//的形式，也就相当于对多项式
//A(x)=∑i=0 n−1 aix^i
//在 x=10 处求值。当两个数 Na 、Nb 相乘的时候，我们也可以认为这两个数是两个多项式
//{A(x)=∑i=0 n−1 aix^i
//⎨B(x)=∑i=0 m−1 bix^i
//相乘的结果 C(x)=A(x)×B(x) 在 x=10 处求值。我们可以这样表示 C(x)：
//C(x)=∑i=0 n+m−2 cix^i
//这里
//ci=∑k=0 i akb^i−k
//于是我们就可以顺序求解 ci ，每次 O(i) 地选取下标和为 i 的一组 (ak,bi−k)。求到 ci 序列之后，再处理进位即可得到答案。对比这两种做法：
//顺序求解 ci 的过程相当于集中计算 ci
//而方法二相当于每对 (ai,bj) 对 ci+j 算贡献（注意这里的 ai 并不是题目中的 num1[i]，ai 下标越小，代表的位权越小，而 num1[i] 下标越小，代表的位权越大）
//它们的本质是一样的，并且时间复杂度都是 O(max⁡{n,m}^2)。我们再仔细的观察 ci 的形式：
//ci=∑k=0 i akbi−k
//它揭示了多项式乘法的另一面：ci 序列其实是 ai 序列和 bi 序列的卷积，即：
//c⃗=a⃗∗b⃗
//至此，我们就可以用一种叫做快速傅立叶变换（Fast Fourier Transform，FFT）的方法来加速卷积的计算，使得时间复杂度降低到 O(clog⁡c)，这里 c 是不小于 n+m 的最小的 2 的整数幂。由于这个方法并不在面试的考纲范围内，感兴趣的同学可以自行学习。
