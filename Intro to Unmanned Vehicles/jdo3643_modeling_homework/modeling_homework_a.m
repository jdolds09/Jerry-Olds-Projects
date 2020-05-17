%Transfer function of differential equation
%H(S)= 4u/ay'''+by''+cy'+dy

a=2;
b=5;
c=3;
d=5;

num=4;
den=[a b c d];

msdsyst=tf(num,den);

%stepplot(msdsyst)

t=0:0.1:60;
u=gensig('square',2,60,0.1);

lsim(msdsyst,u,t)
axis([0 60 0 1])