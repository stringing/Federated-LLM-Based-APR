%Ships pursuit
clc
clear
t=240;
x0=zeros(1,1);y0=zeros(1,1);
x1=zeros(1,1);y1=zeros(1,1);
dt=0.01;
u=8;v=12;
x1(1,1)=12;
i=1;
while abs(x0(1,i)-x1(1,i)) > 1e-4
   d=sqrt((x1(1,i)-x0(1,i))^2+(y1(1,i)-y0(1,i))^2);
   cosx=(x1(1,i)-x0(1,i))/d;
   sinx=(y0(1,i)-y1(1,i))/d;
   x0(1,1+i)=0;
   y0(1,1+i)=y0(1,i)+u*dt;
   x1(1,1+i)=x1(1,i)-v*dt*cosx;
   y1(1,1+i)=y1(1,i)+v*dt*sinx;
   plot(x0(1,i),y0(1,i),'bo',x1(1,i),y1(1,i),'ro')
   hold on
   pause(0.1)
   i=i+1;











