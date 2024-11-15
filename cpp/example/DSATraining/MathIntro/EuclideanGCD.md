# <center><font size = 6>最大公约数&最小公倍数 欧几里得算法<br></font>
## <center><font size = 5>欧几里得算法(辗转相除法)</font>
已知两数a和b，求两数的最大公约数 和 最小公倍数
### GCD
***证明：gcd = gcd(b,a%b)***
设a > b, a % b = a - kb, 其中 **k = a / b(向下取整)**， 例如：7 % 3 = 7 - 2 * 3

>*定义 | 为 能整除*

$\qquad$(1) 若d是（a,b）的公约数，则 d | a 且 d | a, 则 d 也 | （a % b）故 d 也是（b , a%b）的公约数。
$\qquad$（2）若d是（b , a%b）的公约数，则 d | b 且 d | (a-kb)，则d | (a - kb + kb) = d | a。故d也是（a,b）的公约数。所以(a,b)和（b,a%b）的公约数是相同的，故最大公约数也相同。

$\qquad$**所以（a , b）与（a , a % b）的公约数是相同的，故最大公约数也相同**
$\qquad$递归求解，直至 a % b == 0, 此时 b 就是最大公约数

### LCM
***证明：lcm[a,b]=a∗b/gcd(a,b)***

>d为最大公约数

设 p = ad, q = bd，则lcm(p,q) = abd ~~***d***~~

### 故存在*gcd * lcm = a * b*