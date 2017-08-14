function g = sigmoid(z, type)
%SIGMOID Compute sigmoid functoon
%   J = SIGMOID(z) computes the sigmoid of z.

if type == 1
    g = 1.0 ./ (1.0 + exp(-z));
else
    g = tanh(z);
end
