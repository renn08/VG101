function ret =myeval(str)
str=strrep(str,' ','');
n=length(str);
for i=2:n
    if str(i)=='+'||...
       str(i)=='-'||...
       str(i)=='*'||...
       str(i)=='/'
        x=i;               %�ҵ����������ʵλ�ã���2��ʼ�Ա�����븺��ǰ�ĸ���                         
    break
    end
end
y=str2double(str(1:x-1));
z=str2double(str(x+1:n));
if str(x) == '+'
    ret = y + z;
elseif str(x) == '-'
    ret = y - z;
elseif str(x) == '*'
    ret = y * z;
elseif str(x) == '/'
    ret = y / z;
end                       %�˺����ɽ��ж�����������������������С���ļӼ��˳�����