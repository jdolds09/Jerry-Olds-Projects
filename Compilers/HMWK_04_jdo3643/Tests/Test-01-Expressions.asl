@ Dalio, Brian A.
@ dalioba
@ 2020-05-03
@-----------------------------------------------------------

@ Just some expressions.
a = 0 & 1 | 0 & 1;  @ If AND happens first, answer is 0.  If OR, 1.

b = 1 & 1 # 1 & 1; @ If XOR happens first, answer is 0.  If AND, 1.

c = 1 # 3 + 5 # 1;  @ If PLUS happens first, answer is 0.  If XOR, 1.

d = 1 + 2 * 3 + 4;  @ If TIMES happens first, answer is 11.  If PLUS, 21.
f = 1 - 2 * 3 - 4;  @ If TIMES happens first, answer is -9.  If MINUS, 1.

g = 1 + 4 / 2 + 3;  @ If DIVIDE happens first, answer is 6.  If PLUS, 1.
h = 1 - 4 / 2 - 3;  @ If DIVIDE happens first, answer is -4.  If MINUS, 3.

i = 1 + 5 % 3 + 2;  @ If MODULUS happens first, answer is 5.  If PLUS, 1.
j = 8 - 5 % 4 - 2;  @ If MODULUS happens first, answer is 5.  If MINUS, 1.

k = 2 * 3 ^ 4 * 5;  @ If EXPONENTIATION happens first, answer is 810.  If TIMES, 3656158440062976.
l = 128 / 2 ^ 6 / 2;  @ If EXPONENTIATION happens first, answer is 1.  If DIVIDE, 262144.
m = 5 % 3 ^ 6 % 2;  @ If EXPONENTIATION happens first, answer is 1.  If MODULUS, 8.

n = 2 ^ 3!;  @ If FACTORIAL happens first, answer is 64.  If EXPONENTIATION, 40320.
o = 2 ^ 36$;  @ If SQUARE_ROOT happens first, answer is 64.  If EXPONENTIATION, 262144.

p = -1.5!;  @ If UMINUS happens first, answer is an error.  If FACTORIAL, -1.3293403881791372.
q = -25$;  @ If UMINUS happens first, answer is an error.  If SQUARE_ROOT, -5.

r = ~3!  @ If NOT happens first, answer is 1.  If FACTORIAL, 0.
