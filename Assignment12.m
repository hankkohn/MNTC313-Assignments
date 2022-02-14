%MNTC313 A12 starter code
%User input statements have been provided to acquire the % payload in the
%bucket, the incline angle and the friction coefficient
%These statements have been formatted for AutoGradr - please do not alter
%them.

%If you run the program in MATLAB, you will be able to input values in the
%command window
clc;

height = input('Enter controlled-descent height (m):');
fprintf('\n');
rho = input('Enter fluid density (kg/m^3):');
fprintf('\n');

%store constants as variables for future use
A = pi*(3.7/2)^2;
m = 15600;
g = 9.8;
C = 1.0;
tDuration = 60;
dt = 1;

%first while loop runs through dt values of 1, 0.1, and 0.01
while dt >= 0.01
    %reset the following constants for each new dt
    y = 10000;
    yd = -1500/3.6;
    tGas = 0; %keeps track of how long the rocket has been on the gas for
    t = 0;
    
    %second while loop performs calculations until the rocket reaches sea level
    while y >= 0
        %check if the rocket is below controlled descent height and that it has been on the gas for <60s
        %adjust applied force accordingly
        if (y <= height) && (tGas <= tDuration)
            Fa = 174850;
            tGas = tGas + dt;
        else
            Fa = 0;
        end
        
        %direction of drag must be opposite direction of motion
        if yd < 0
            ydd = (Fa + 0.5*C*rho*A*yd^2)/m - g;
        else
            ydd = (Fa - 0.5*C*rho*A*yd^2)/m - g;
        end
        
        y = y + yd*dt;
        yd = yd + ydd*dt;
        
        t = t + dt;
    end
    
    t = t - dt; %line 53 increments t once more after rocket reaches sea level, this line corrects that
    fprintf('dt = %.2f s, Total time = %.0f s, Position = %.0f m\n', dt, t, y);
    dt = dt*0.1; %adjust dt to next value
end

yd = yd*3.6;
fprintf('landing speed: %.0f km/h\n', abs(yd));
if abs(yd) > 10
    fprintf('Non-successful landing\n');
else
    fprintf('Successful landing\n');
end
