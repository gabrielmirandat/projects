%MNIST HELPER - http://ufldl.stanford.edu/wiki/index.php/Using_the_MNIST_Dataset

%% Initialization
clear ; close all; clc
fprintf('Initialization ...\n')

%% Parameters setup
fprintf('Parameters setup ...\n')
input_layer_size  = 784;  % 28x28 Input Images of Digits
num_labels = 10;          % 10 labels, from 1 to 10   
                          % (note that we have mapped "0" to label 10)

%  You should also try different values of iterations, lambda and hidden
%  layer size
prompt = 'Give a value for the learning rate? (e.g. 0.1) ';
lambda = input(prompt) 
if lambda<0.1; error('Learning rate must be greater than 0..'); end

prompt = 'Give the number of training iterations. (e.g. 100) ';
num_iterations = input(prompt)
if num_iterations<1; error('Training iterations must be greater than 0..'); end

prompt = 'Give the number of neurons in the hidden layer. (e.g. 25) ';
hidden_layer_size = input(prompt)
if hidden_layer_size<10; error('Number of neurons must be greater or equal than 10..'); end

prompt = 'Activation function. ((1)logistic (2)tanh) ';
activation = input(prompt)
if activation~=1 && activation~=2; error('Activation function must be logistic or tanh..'); end

                          
%%  Loading and visualizing the training data

fprintf('Loading and visualizing the training data ...\n')

% Load Training Data
X = loadMNISTImages('../data/si/train-images.idx3-ubyte');
X = X'; %transpose
y = loadMNISTLabels('../data/si/train-labels.idx1-ubyte');
y( y==0 )=10; 

m = size(X, 1);

% Randomly select 100 data points to display
sel = randperm(size(X, 1));
sel = sel(1:100);

displayData(X(sel, :));

fprintf('Program paused. Press enter to continue.\n');
pause;
close all;

%% Initializing parameters

fprintf('\nInitializing neural network parameters (random weights) ...\n')

initial_Theta1 = randInitializeWeights(input_layer_size, hidden_layer_size);
initial_Theta2 = randInitializeWeights(hidden_layer_size, num_labels);

% Unroll parameters
initial_nn_params = [initial_Theta1(:) ; initial_Theta2(:)];

%% Training NN

%  After you have completed the assignment, change the MaxIter to a larger
%  value to see how more training helps.
options = optimset('MaxIter', num_iterations);

fprintf('\nTraining neural network ... \n')

% Create "short hand" for the cost function to be minimized
costFunction = @(p) nnCostFunction(p, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, X, y, ...
                                   lambda, activation);

% Now, costFunction is a function that takes in only one argument (the
% neural network parameters)
[nn_params, cost] = fmincg(costFunction, initial_nn_params, options);


%% Visualizing cost and weight

fprintf('\nVisualizing cost and weights... \n')

% Ploting cost by iterations
plot(1:num_iterations, cost);
title('Cost by iterations')
xlabel('Iteration')
ylabel('Cost')
figure;

% Obtain Theta1 and Theta2 back from nn_params
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

displayData(Theta1(:, 2:end));

fprintf('\nProgram paused. Press enter to continue.\n');
pause;
close all;

%% Loading the test data

fprintf('Loading and visualizing the test data ...\n')

% Load Training Data
X_test = loadMNISTImages('../data/si/t10k-images.idx3-ubyte');
X_test = X_test'; %transpose
y_test = loadMNISTLabels('../data/si/t10k-labels.idx1-ubyte');
y_test( y_test==0 )=10; 

m_test = size(X_test, 1);

% Randomly select 100 data points to display
sel_test = randperm(size(X_test, 1));
sel_test = sel_test(1:100);

displayData(X_test(sel_test, :));

fprintf('Program paused. Press enter to continue.\n');
pause;
close all;

%% Predict

%im_entrada = double(rgb2gray(imread('tres.jpg')));
%entrada = reshape(im_entrada,1,[]);
%pred = predict(Theta1, Theta2, entrada);
%disp(pred);

fprintf('Predict ...\n')

pred_train = predict(Theta1, Theta2, X, activation);
fprintf('\nTraining Set Accuracy: %f\n', mean(double(pred_train == y)) * 100);

pred_test = predict(Theta1, Theta2, X_test, activation);
fprintf('Test Set Accuracy: %f\n', mean(double(pred_test == y_test)) * 100);

% Pause
fprintf('Program paused. Press enter to continue.\n\n');
pause;
close all;

%% To give you an idea of the network's output, you can also run
%  through the examples one at the a time to see what it is predicting.

fprintf('\nRandom ten samples from test dataset ...\n')

%  Randomly permute examples
rp = randperm(m_test);

for i = 1:10
    % Display 
    fprintf('Displaying Example Image\n');
    displayData(X_test(rp(i), :));

    pred_rand = predict(Theta1, Theta2, X_test(rp(i),:), activation);
    fprintf('Neural Network Prediction: %d (digit %d)\n', pred_rand, mod(pred_rand, 10));
    
    % Pause
    fprintf('Program paused. Press enter to continue.\n\n');
    pause;
end
close all;

%% End

fprintf('\nEnd of program ...\n');




