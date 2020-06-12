/*

Reverse bits of a given 32 bits unsigned integer.



Example 1:

Input: 00000010100101000001111010011100
Output: 00111001011110000010100101000000
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.
Example 2:

Input: 11111111111111111111111111111101
Output: 10111111111111111111111111111111
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.


Note:

Note that in some languages such as Java, there is no unsigned integer type. In this case, both input and output will be given as signed integer type and should not affect your implementation, as the internal binary representation of the integer is the same whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above the input represents the signed integer -3 and the output represents the signed integer -1073741825.


Follow up:

If this function is called many times, how would you optimize it?

Solution one is easy to understand, two is excellent but hard to understand;



Step 0.
abcd efgh ijkl mnop qrst uvwx yzAB CDEF <-- n

Step 1.
                    abcd efgh ijkl mnop <-- n >> 16, same as (n & 0xffff0000) >> 16
qrst uvwx yzAB CDEF                     <-- n << 16, same as (n & 0x0000ffff) << 16
qrst uvwx yzAB CDEF abcd efgh ijkl mnop <-- after OR

Step 2.
          qrst uvwx           abcd efgh <-- (n & 0xff00ff00) >> 8
yzAB CDEF           ijkl mnop           <-- (n & 0x00ff00ff) << 8
yzAB CDEF qrst uvwx ijkl mnop abcd efgh <-- after OR

Step 3.
     yzAB      qrst      ijkl      abcd <-- (n & 0xf0f0f0f0) >> 4
CDEF      uvwx      mnop      efgh      <-- (n & 0x0f0f0f0f) << 4
CDEF yzAB uvwx qrst mnop ijkl efgh abcd <-- after OR

Step 4.
  CD   yz   uv   qr   mn   ij   ef   ab <-- (n & 0xcccccccc) >> 2
EF   AB   wx   st   op   kl   gh   cd   <-- (n & 0x33333333) << 2
EFCD AByz wxuv stqr opmn klij ghef cdab <-- after OR

Step 5.
 E C  A y  w u  s q  o m  k i  g e  c a <-- (n & 0xaaaaaaaa) >> 1
F D  B z  x v  t r  p n  l j  h f  d b  <-- (n & 0x55555555) << 1
FEDC BAzy xwvu tsrq ponm lkji hgfe dcba <-- after OR
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for ( int i = 0; i < 32; ++i )
        {
            res = ( res << 1 ) + ( n >> i & 1 );
        }
        return res;
    }
};

//Convert 16 base to 2 base easy to understand
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = ( n >> 16 ) | ( n << 16 );
        n = ( ( n & 0xff00ff00 ) >> 8 ) | ( ( n & 0x00ff00ff ) << 8  );
        n = ( ( n & 0xf0f0f0f0 ) >> 4 ) | ( ( n & 0x0f0f0f0f ) << 4  );
        n = ( ( n & 0xcccccccc ) >> 2 ) | ( ( n & 0x33333333 ) << 2  );
        n = ( ( n & 0xaaaaaaaa ) >> 1 ) | ( ( n & 0x55555555 ) << 1  );
        return n;
    }
};
