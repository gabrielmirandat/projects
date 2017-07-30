n = 100;
x = 5*sin(2*pi*10.*[0:0.001:0.2]);
x = 5*sin(2*pi*10.*[0:0.001:0.2]);

for i = 1:n 
    r = randn(1,length(x));
    x1(i,:) = x + r; 
end

y = sum(x1)/n;

figure; plot(y);