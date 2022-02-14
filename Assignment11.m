%%MNTC313 A11 Starter Code%%

%%Please DO NOT change the user input format
%%It has been formatted to work properly with the Octave Engine

clc

a = input('Enter a:');
fprintf('\n');
b = input('Enter b:');
fprintf('\n');

f = @(x) 1.8.^(0.045.*x)-1;

%evaluate the true value of the integral, print result
trueForce = quadgk(f,a,b);
fprintf('True value: %.0f N\n', trueForce);

N = 10;
while N <= 100000 %use a while loop to perform the same set of calculations with different N values each time
    xValues = linspace(a,b,N); %generate N equally spaced x values from a to b
    yValues = f(xValues); %evaluate f at each value of x
    dx = (b - a)/N; %determine the width of each rectangle
    force = sum(yValues*dx); %sum the areas of N rectangles
    percentError = (abs(force - trueForce)/trueForce)*100; %apply the percent error formula
    fprintf('N = %d, F = %.0f N, Error %% = %.2f\n', N, force, percentError); %use '%%' to output a percent character
    N = N*10; %multiply N by 10 to get the desired N value for the next iteration of the loop
end

%calculate force in the exact same manner as above, this time using fixed values instead of variables because the building size is given
xValues = linspace(450,500,10000);
yValues = f(xValues);
dx = (500 - 450)/10000;
avgForce = sum(yValues*dx);

%calculate area and then pressure using the formula for pressure, output results
area = 50*50;
pressure = (avgForce/area)/1000; %calculate and convert from Pa to kPa
fprintf('Average pressure between 450 and 500 m: %.1f kPa\n', pressure);