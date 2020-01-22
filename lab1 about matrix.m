clear all
clc
m = input('input m');
n = input('input n');
q = input('input q');
A = zeros(m,n);
for i = 1:m
    for j = 1:n
        A(i,j) = mod(q + i * n + j,m * n);
    end
end
disp('A=')
disp(A)                        %����һ��m*n�ľ���A
order_number = input('order number');
if order_number == 2             %ע��=��==
    a = input('input a');
    i = input('input i');
    j = input('input j');
    if a == 1
        x = A(:,i);
        A(:,i) = A(:,j);
        A(:,j) = x;
    else                          %ע�⻻��
        x = A(i,:);
        A(i,:) = A(j,:);
        A(j,:) = x;
    end
    disp('B=')
    disp(A)
elseif order_number == 3         %Ŀǰ����ʵ�����·�ת����ʱ��90�����ҷ�ת˳ʱ��90
    B = A';
    B = fliplr(A);
    disp('B=')
    disp(B)
elseif order_number == 4
    for i = 1:m
        y = strrep(num2str(A(i,:)),' ','');
        c = str2double(y);
        L = floor(log(c) / log(2)) + 1;
        C = zeros(1,L);
        for t = 1:L
            C(1,t) = mod(c,2);
            c = (c - mod(c,2)) / 2;
        end
        C = C(L:-1:1);
        y=strrep(num2str(C),' ','');
        disp(y)
    end
end
 
