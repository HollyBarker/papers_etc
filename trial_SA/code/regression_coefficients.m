Tf1=readtable('f1data.txt');
Tf2=readtable('f2data.txt');
Tx=readtable('xdata.txt');
Ty=readtable('ydata.txt');
Tz=readtable('zdata.txt');
Ta=readtable('adata.txt');
Tb=readtable('bdata.txt');
Tc=readtable('cdata.txt');
Td=readtable('ddata.txt');

N=length(Tf1.Var1);

plot(Tf1.Var1,Tx.Var1,'*')
xlabel('f1 at t=1');
ylabel('x')
figure
plot(Tf2.Var1,Ty.Var1,'*')
xlabel('f2 at t=1')
ylabel('y')


X=[ones(N,1),Tx.Var1,Ty.Var1,Tz.Var1,Ta.Var1,Tb.Var1,Tc.Var1,Td.Var1];

bf1t1=linsolve(transpose(X)*X,transpose(X)*Tf1.Var1);
bf1t2=linsolve(transpose(X)*X,transpose(X)*Tf1.Var2);
bf1t3=linsolve(transpose(X)*X,transpose(X)*Tf1.Var3);

bf2t1=linsolve(transpose(X)*X,transpose(X)*Tf2.Var1);
bf2t2=linsolve(transpose(X)*X,transpose(X)*Tf2.Var2);
bf2t3=linsolve(transpose(X)*X,transpose(X)*Tf2.Var3);

Varx=sum((Tx.Var1-mean(Tx.Var1)).^2)/(N-1);
Vary=sum((Ty.Var1-mean(Ty.Var1)).^2)/(N-1);
Varz=sum((Tz.Var1-mean(Tz.Var1)).^2)/(N-1);
Vara=sum((Ta.Var1-mean(Ta.Var1)).^2)/(N-1);
Varb=sum((Tb.Var1-mean(Tb.Var1)).^2)/(N-1);
Varc=sum((Tc.Var1-mean(Tc.Var1)).^2)/(N-1);
Vard=sum((Td.Var1-mean(Td.Var1)).^2)/(N-1);

VarXj=[1;Varx;Vary;Varz;Vara;Varb;Varc;Vard]; %included a 1 just to make matrix dimensions agree: dunno what I should actually do

Varf1t1=sum((Tf1.Var1-mean(Tf1.Var1)).^2)/(N-1);
Varf2t1=sum((Tf2.Var1-mean(Tf2.Var1)).^2)/(N-1);
 
%just continue with t=1 from now : too much data

b_sf1t1=bf1t1.*(VarXj./Varf1t1).^0.5 %ignore first entry, see above.
B_sf2t1=bf2t1.*(VarXj./Varf2t1).^0.5 %ignore first entry, see above.