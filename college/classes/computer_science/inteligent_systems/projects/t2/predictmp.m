function p = predictmp(Theta1, Theta2, X, activation)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);

% You need to return the following variables correctly 
p = zeros(size(X, 1), 1);

h1 = sigmoid([ones(m, 1) X] * Theta1', activation);
h2 = sigmoid([ones(m, 1) h1] * Theta2', activation);

%h2 represents the network output for all output neurons
[dummy, p] = max(h2, [], 2);

function g = sigmoid(z, type)
%SIGMOID Compute sigmoid function
%   J = SIGMOID(z) computes the sigmoid of z.

if type == 1
    g = 1.0 ./ (1.0 + exp(-z));
else
    g = tanh(z);
end