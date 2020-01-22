function Oputarr= myscan(Oriarr,smin,smax)
%methods1
l=length(Oriarr);
Oputarr=zeros(1,l);
 for i=1:l
     if Oriarr(1,i)<=smin
        Oputarr(1,i)=0;
     elseif Oriarr(1,i)<=smax
        Oputarr(1,i)=((Oriarr(1,i)-smin)/(smax-smin))*255;
     else 
        Oputarr(1,i)=255; 
     end
 end                                        %仅对一维成立
 %图像优化处理
 %Oputarr=Oriarr;
 %Oputarr(Oputarr<smin)=smin;
 %Oputarr(Oputarr>smax)=smax;
 %Oputarr=255*(Oputarr-smin)/(smax-smin);   %对多维亦成立
 
