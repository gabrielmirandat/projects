% clear everything
close all
clear all
clc

% Example Transfer Function: G(s) = R/(R + Ls -s/C)
R1 = 1000; L1 = 0.0485422; C1 = 0.0000000052182;
R2 = 1000; L2 = 0.14403; C2 = 0.00000000175862;
R3 = 1000; L3 = 0.016711; C3 = 0.0000000151576;

% Numerator and Denominator
num1 = [-R1]; den1 = [L1-1/C1 -R1];
num2 = [-R2]; den2 = [L2-1/C2 -R2];
num3 = [-R3]; den3 = [L3-1/C3 -R3];

% Transfer Function
G1 = tf(num1, den1);
G2 = tf(num2, den2);
G3 = tf(num3, den3);

% Plot Frequency Response
%bode(G1),grid
%bode(G1,G2),grid
bode(G1,G2,G3),grid