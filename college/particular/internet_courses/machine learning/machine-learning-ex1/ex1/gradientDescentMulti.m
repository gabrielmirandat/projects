function [theta, J_history] = gradientDescentMulti(X, y, theta, alpha, num_iters)
%GRADIENTDESCENTMULTI Performs gradient descent to learn theta
%   theta = GRADIENTDESCENTMULTI(x, y, theta, alpha, num_iters) updates theta by
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);
fator = alpha/m;
theta_f = zeros(size(theta));

%thetaLen = length(theta);
%tempVal = theta; % Just a temporary variable to store theta values.

for iter = 1:num_iters 
    % ====================== YOUR CODE HERE ======================
    % Instructions: Perform a single gradient step on the parameter vector
    %               theta. 
    %
    % Hint: While debugging, it can be useful to print out the values
    %       of the cost function (computeCost) and gradient here.
    %

    h_theta = (theta.')* (X.'); %sempre 1 x m
    parcial1 = (h_theta.') - y; %também 1 x m
    soma = (parcial1.') * X;
    theta_f = theta - fator*(soma.');
    theta = theta_f;
    
    
    %    temp = (X*theta - y);
    
    %    for i=1:thetaLen
    %        tempVal(i,1) = sum(temp.*X(:,i));
    %    end
    
    %    theta = theta - (alpha/m)*tempVal;
    
    % ============================================================

    % Save the cost J in every iteration    
    J_history(iter) = computeCost(X, y, theta);

end

end