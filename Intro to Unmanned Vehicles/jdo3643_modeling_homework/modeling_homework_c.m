%State space model of differential equation

time=[0 60];

x0 = [1;1;1];

[t,x]=ode45(@modeling_homework_msddyn,time,x0);

plot(t,x)