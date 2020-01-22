function[BMI,status]=ComputeBMI(weight_kg, height_cm)        
BMI=round(weight_kg/(height_cm/100)^2,1);                    
if BMI <18.5                                                              
    status=1;
    fprintf('Underweight!');
elseif BMI<=24.9
    status=2;
    fprintf('Normal or Healthy Weight!');
elseif BMI<=29.9
    status=3;
    fprintf('Overweight!');
elseif 30.0<= BMI
    status=4;
    fprintf('Obese!');
end