function w=Lab2p3(imagename,X,Y)
img=imread(imagename);                     %注意输入a=1，输入文件名加''
y=length(img(:,1,:));                      %纵向长
x=length(img(1,:,:));                      %横向长
p=(400/X-floor(400/X))/2;
p1=floor((400/X)+1);
q=(300/Y-floor(300/Y))/2;
q1=floor((300/Y)+1);
t=zeros(y,X,3);
w=zeros(Y,X,3);
for n=1:3
 img1=im2double(img(:,:,n));
 for ii=1:y
    imga = [ones(1, p1) * img1(ii,1),img1(ii,:)];
    imgs = zeros(1, x + p1);
     for i = 1 : (2* p1 + 1)
         if i==1
             imgs=imga*p+imgs;
             imga = [imga(2:length(imga)),imga(length(imga))];
         elseif i==2* p1 + 1
             imgs=imga*p+imgs;
             imga = [imga(2:length(imga)),imga(length(imga))];
         else
	      imgs = imgs + imga; 
	      imga = [imga(2:length(imga)),imga(length(imga))];
         end
     end
    initial = imgs(1:x) / (2 * p1 + 1);
    myoutput1 = initial(round(linspace(1,400,X)));
    t(ii,:,n)=myoutput1;
 end
 g=t(:,:,n);
 for jj=1:x/2
    IMGA=[ones(q1,1)*g(1,jj);g(:,jj)];     %分号用于纵向拼接
    IMGS = zeros( y + q1,1);
     for i = 1 : (2* q1 + 1)
         if i==1
          IMGS = IMGS + IMGA*q; 
	      IMGA = [IMGA(2:length(IMGA));IMGA(length(IMGA))]; 
         elseif i==2* q1 + 1
          IMGS = IMGS + IMGA*q; 
	      IMGA = [IMGA(2:length(IMGA));IMGA(length(IMGA))];
         else
          IMGS = IMGS + IMGA;
          IMGA = [IMGA(2:length(IMGA));IMGA(length(IMGA))];
         end
     end
     INITIAL=IMGS(1:y)/(2*q1+1);
     MYOUTPUT1=INITIAL(round(linspace(1,300,Y)));
     w(:,jj,n)=MYOUTPUT1;
 end
end
w=im2uint8(w);
imwrite(w,'output.bmp')
end