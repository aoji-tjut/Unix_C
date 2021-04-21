class Solution
{
public:
    int add(int a, int b)
    {
        //不用加法的加法运算 = 不进位加法 + 只进位加法 = 异或运算 + 与运算后向左进一位。
        //又为了消除上式中的加号，需要用一个while循环来判断，当不再进位时跳出循环。
        while(b != 0)
        {
            int not_carry = a ^b;
            int carry = ((unsigned int)(a & b) << 1);
            a = not_carry;
            b = carry;
        }

        return a;
    }
};