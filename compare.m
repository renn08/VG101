R=75;
M=300;
N=400; 
x=150;
y=200; 
originpic=zeros(M,N);
 for i=1:M    
    for j=1:N        
        if(x-i)^2+(y-j)^2<=R^2            
            originpic(i,j)=1;
        end
        if(x-i)^2+(y-j)^2<=(R-3)^2            
            originpic(i,j)=0;
        end
    end
 end
imshow(originpic);
saveas(gcf,'originpic.bmp');
pic=imread('originpic.bmp');
Y=length(pic(:,1));                      %纵向长
X=length(pic(1,:));                      %横向长
 for ii=1:Y
    picx=pic(ii,:);
     for jj=1:X-3
         m=0.25*(sum(picx(jj:jj+3)));
         pic(ii,jj:jj+3)=[m,m,m,m];
     end
 end
 for jj=1:X
     picy=pic(:,jj);
     for ii=1:Y-3
         n=0.25*(sum(picy(ii:ii+3)));
         pic(ii:ii+3,jj)=[n;n;n;n];
     end
 end
imwrite(pic,'output.bmp');



