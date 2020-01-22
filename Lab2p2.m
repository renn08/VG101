function w=Lab2p2(imagename,a)
img=imread(imagename);                     %注意输入a=1，输入文件名加''
y=length(img(:,1,:));                      %纵向长
x=length(img(1,:,:));                      %横向长
t=zeros(y,x/2,3);
w=zeros(y/2,x/2,3);
for n=1:3
 img1=im2double(img(:,:,n));
 for ii=1:y
    imga = [ones(1, a) * img1(ii,1),img1(ii,:)];
    imgs = zeros(1, x + a);
     for i = 1 : (2* a + 1)
	      imgs = imgs + imga; 
	      imga = [imga(2:length(imga)),imga(length(imga))]; 
     end
    initial = imgs(1:x) / (2 * a + 1);
    myoutput1 = initial(1:2:x);
    t(ii,:,n)=myoutput1;
 end
 g=t(:,:,n);
 for jj=1:x/2
    IMGA=[ones(a,1)*g(1,jj);g(:,jj)];     %分号用于纵向拼接
    IMGS = zeros( y + a,1);
     for i = 1 : (2* a + 1)
	      IMGS = IMGS + IMGA; 
	      IMGA = [IMGA(2:length(IMGA));IMGA(length(IMGA))];
     end
     INITIAL=IMGS(1:y)/(2*a+1);
     MYOUTPUT1=INITIAL(1:2:y);
     w(:,jj,n)=MYOUTPUT1;
 end
end
w=im2uint8(w);
imwrite(w,'output.bmp')
end