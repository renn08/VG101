function DrawCircle(x, y, radius)
M=512;
N=512; 
pic=zeros(M,N);
 for i=1:M    
    for j=1:N        
        if(x-i)^2+(y-j)^2<=radius^2            
            pic(i,j)=1;
        end
        if(x-i)^2+(y-j)^2<=(radius-1)^2            
            pic(i,j)=0;
        end
    end
 end
imshow(pic);
imwrite(pic,'circle.bmp');
end

