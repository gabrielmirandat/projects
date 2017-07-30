function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices.
%   --já feito
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%

% Reshape nn_params back into the parameters Theta1 and Theta2, the weight matrices
% for our 2 layer neural network --já feito
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

% ====================== YOUR CODE HERE ======================
% Instructions: You should complete the code by working through the
%               following parts.
%
% Part 1: Feedforward the neural network and return the cost in the
%         variable J. After implementing Part 1, you can verify that your
%         cost function computation is correct by verifying the cost
%         computed in ex4.m
%
% Part 2: Implement the backpropagation algorithm to compute the gradients
%         Theta1_grad and Theta2_grad. You should return the partial derivatives of
%         the cost function with respect to Theta1 and Theta2 in Theta1_grad and
%         Theta2_grad, respectively. After implementing Part 2, you can check
%         that your implementation is correct by running checkNNGradients
%
%         Note: The vector y passed into the function is a vector of labels
%               containing values from 1..K. You need to map this vector into a 
%               binary vector of 1's and 0's to be used with the neural network
%               cost function.
%
%         Hint: We recommend implementing backpropagation using a for-loop
%               over the training examples if you are implementing it for the 
%               first time.
%
% Part 3: Implement regularization with the cost function and gradients.
%
%         Hint: You can implement this around the code for
%               backpropagation. That is, you can compute the gradients for
%               the regularization separately and then add them to Theta1_grad
%               and Theta2_grad from Part 2.
%

%- J = custo
%- Backpropagation para calcular Theta1_grad and Theta2_grad, checar com
%       checkNNGradients.
%- Mapear y em 1's e 0's para ser usado no custo.

%Encontrando a hipótese (h(theta))
a1 = [ones(m,1),X];
z2 = a1 * Theta1.';
a2 = [ones(m,1),sigmoid(z2)];
z3 = a2 * Theta2.';
a3 = sigmoid(z3); %a3 = h(theta)

%Ajustando y
y_ajus = eye(num_labels);
y_ajus = y_ajus(y,:);

%Calculando a regularização
%Não regularizar o Bias = primeira coluna de theta1 e theta2
regularizacao = (lambda/(2*m)) * (sum(sum((Theta1(:,2:end)).^2)) + sum(sum((Theta2(:,2:end)).^2)));

%Calculando o custo
J = ((1/m) * sum(sum(-y_ajus.*log(a3) - (1-y_ajus).*log(1 - a3)))) + regularizacao;

%Calculando grad com Backpropagation
%Once you have computed the gradient, you will be able to train the neural network by minimizing the cost 
%function J(theta) using an advanced optimizer such as fmincg.

%loop that processes one example at a time. Concretely, you should implement a for-loop for t = 1:m and
%place steps 1-4 below inside the for-loop, with the tth iteration performing the calculation on the tth 
%training example (x(t), y(t))

d3 = a3 - y_ajus;
d2 = (d3*Theta2(:,2:end)).*sigmoidGradient(z2);

Theta1_grad = 1/m * d2' * a1;
Theta2_grad = 1/m * d3' * a2;

%add regularization:
Theta1_grad(:,2:end) = Theta1_grad(:,2:end) + lambda/m*Theta1(:,2:end);
Theta2_grad(:,2:end) = Theta2_grad(:,2:end) + lambda/m*Theta2(:,2:end);

% -------------------------------------------------------------

% =========================================================================

% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end
