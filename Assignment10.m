% clear all preexisting variables (clear workspace)
% this way goldM, sulfurM,arsenicM and cutoffConditions do not flip-flop between 1x10 and 10x1 matrices each time the code runs
clear;

% input data from text file into variables
sampleID = dlmread('goldDataA.txt', '\t', [0 0 9 0]);
sampleLength = dlmread('goldDataA.txt', '\t', [0 1 9 1]);
sampleRad = dlmread('goldDataA.txt', '\t', [0 2 9 2]);
sampleDens = dlmread('goldDataA.txt', '\t', [0 3 9 3]);
goldC = dlmread('goldDataA.txt', '\t', [0 4 9 4]);
sulfurC = dlmread('goldDataA.txt', '\t', [0 5 9 5]);
arsenicC = dlmread('goldDataA.txt', '\t', [0 6 9 6]);

% calculate mass of gold, sulfur, and arsenic in each sample
% also check if each sample meets the cutoff conditions, store answer as "Y" or "N"
for i = 1:1:10
    goldM(i) = (sampleRad(i))^2*pi*sampleLength(i)*sampleDens(i)*goldC(i);
    sulfurM(i) = (sampleRad(i))^2*pi*sampleLength(i)*sampleDens(i)*sulfurC(i);
    arsenicM(i) = (sampleRad(i))^2*pi*sampleLength(i)*sampleDens(i)*arsenicC(i);
    if (goldC(i) >= 1) && (sulfurC(i) < 5) && (arsenicC(i) < 1)
        cutoffConditions(i) = "Y";
    else
        cutoffConditions(i) = "N";
    end 
end

% sampleID, goldM, sulfurM, arsenicM, and cutoffConditions must all be 10x1 variables for the code on line 36 to work.
% apply the transpose function to the following 4 variables to change them from 1x10 variables to 10x1 variables
goldM = transpose(goldM);
sulfurM = transpose(sulfurM);
arsenicM = transpose(arsenicM);
cutoffConditions = transpose(cutoffConditions);

% concatenate the 5 required variables into a 10x5 matrix
% this links them together so that the sortrows function can be used to sort the rows of the matrix based on the values in column 2
matrix = [sampleID, goldM, sulfurM, arsenicM, cutoffConditions];
sortedMatrix = sortrows(matrix, 2, 'descend');

% search for the maximum value of goldM in the unsorted array. store its index
idx_max = 1;
for i = 2:1:10
    if goldM(i) > goldM(idx_max)
        idx_max = i;
    end
end
maxValue = goldM(idx_max); % save the maximum value of goldM based on its index

% print the required ouput to screen
% use nested for loops that print each value in a given row before moving down to the next row
% the if statements are required so that different formats can be used depending on the column of the entry
fprintf('ID, Gold Mass [g], Sulfur Mass [Kg], Arsenic Mass [Kg], Cutoff conditions? (Y/N)\n');
for i = 1:10
    for j = 1:5
        if j == 1
            fprintf('%.0f, ', sortedMatrix(i,j));
        elseif j == 5
            fprintf('%c', sortedMatrix(i,j));
        else
            fprintf('%.2f, ', sortedMatrix(i,j));
        end
    end
    fprintf('\n');
end
fprintf('Max mass: %.2f g at ID %d\n', maxValue, idx_max); % print the maximum value of goldM