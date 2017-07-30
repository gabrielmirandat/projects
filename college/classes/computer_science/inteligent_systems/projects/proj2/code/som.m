function somM = som(nfeatures, ndim, nepochs, inputdata, eta0, etadecay, sgm0, sgmdecay, showMode, inputdataY)
%somM Simple demonstration of a Self-Organizing Map that was proposed by Kohonen.
%   somMmap = somMSimple(nfeatures, ndim, nepochs, inputdata, eta0, neta, sgm0, nsgm, showMode) 
%   trains a self-organizing map with the following parameters
%       nfeatures        - dimension size of the training feature vectors
%       ndim             - width of a square somM map
%       nepochs          - number of epochs used for training
%       inputdata        - input data
%       inputdataY       - to show kohonen map
%       eta0             - initial learning rate
%       etadecay         - exponential decay rate of the learning rate
%       sgm0             - initial variance of a Gaussian function that
%                          is used to determine the neighbours of the best 
%                          matching unit (BMU)
%       sgmdecay              - exponential decay rate of the Gaussian variance 
%       showMode         - 0: do not show output, 
%                          1: show the initially randomly generated somM map 
%                             and the trained somM map,
%                          2: show the trained somM map after each 10 epochs
%
%   For example: A demonstration of an somM map that is trained by RGB values
%           
%       somM = somMSimple(3,60,10,100,0.1,0.05,20,0.05,2);
%       % It uses:
%       %   3    : dimensions for training vectors, such as RGB values
%       %   60x60: neurons
%       %   10   : epochs
%       %   100  : training vectors
%       %   0.1  : initial learning rate
%       %   0.05 : exponential decay rate of the learning rate
%       %   20   : initial Gaussian variance
%       %   0.05 : exponential decay rate of the Gaussian variance
%       %   2    : Display the somM map after every update

nrows = ndim;
ncols = ndim;

somM = rand(nrows,ncols,nfeatures);
showMap = zeros(nrows, ncols, 3);

if showMode >= 1
    fig = figure;
    displaysomMmap(fig, 1, 'Randomly initialized somM', somM);
end

% Generate random training data
% inputdata = rand(inputdata,nfeatures);

% Generate coordinate system
[x y] = meshgrid(1:ncols,1:nrows);

[ninput ~] = size(inputdata);

for t = 1:nepochs    
    % Compute the learning rate for the current epoch
    eta = eta0 * exp(-t*etadecay);        
    % Compute the variance of the Gaussian (Neighbourhood) function for the current epoch
    sgm = sgm0 * exp(-t*sgmdecay);
    % Consider the width of the Gaussian function as 3 sigma
    width = ceil(sgm*3);        
    % width = sgm;
 
    for ntraining = 1:ninput
        % fprintf('Imagem: %d\n', ntraining);
        % Get current training vector
        trainingVector = inputdata(ntraining,:);
        % Compute the Euclidean distance between the training vector and
        % each neuron in the somM map and return the index of closer neuron
        [bmurow bmucol] = get2Dindexbmu(trainingVector, somM, nrows, ncols, nfeatures);
        % update show map
        showMap(bmurow,bmucol,1:3) = inputdataY(ntraining)/10;
        % Generate a Gaussian function centered on the location of the bmu
        g = exp(-(((x - bmucol).^2) + ((y - bmurow).^2)) / (2*sgm*sgm));
        % Determine the boundary of the local neighbourhood
        fromrow = max(1,bmurow - width);
        torow   = min(bmurow + width,nrows);
        fromcol = max(1,bmucol - width);
        tocol   = min(bmucol + width,ncols);
        % Get the neighbouring neurons and determine the size of the neighbourhood
        neighbourNeurons = somM(fromrow:torow,fromcol:tocol,:);
        sz = size(neighbourNeurons);
        % Transform the training vector and the Gaussian function into 
        % multi-dimensional to facilitate the computation of the neuron weights update
        T = reshape(repmat(trainingVector,sz(1)*sz(2),1),sz(1),sz(2),nfeatures);                   
        G = repmat(g(fromrow:torow,fromcol:tocol),[1 1 nfeatures]);
        % Update the weights of the neurons that are in the neighbourhood of the bmu
        neighbourNeurons = neighbourNeurons + eta .* G .* (T - neighbourNeurons);
        % neighbourNeurons = neighbourNeurons + eta .* (T - neighbourNeurons);
        % Put the new weights of the BMU neighbouring neurons back to the
        % entire somM map
        somM(fromrow:torow,fromcol:tocol,:) = neighbourNeurons;
    end
    
    %if(mod(t,10)==0)
        fprintf('Epoch: %d\n', t);
    %end
    
    if showMode == 2
        %displaysomMmap(fig, 2, ['Epoch: ',num2str(t),'/',num2str(nepochs),', Training Vector: ',num2str(ntraining),'/',num2str(inputdata)], somM, nfeatures);
        displaysomMmap(fig, 2, ['Epoch: ',num2str(t)], showMap);
        pause(0.001);
    end         
end

function displaysomMmap(fig, nsubplot, description, image)
% Display given somM map
figure(fig);
subplot(1,2,nsubplot);
imagesc(image(:,:,1:3));
axis off;axis square;
title(description);

function [bmurow bmucol] = get2Dindexbmu(trainingVector, somMmap, nrows, ncols, nfeatures)
% dist = getEuclideanDistance(trainingVector, somMmap, nrows, ncols, nfeatures);
neuronList = reshape(somMmap,nrows*ncols,nfeatures); 
dist = mandist(neuronList, trainingVector');
% Find the best matching unit (bmu)
[~, bmuindex] = min(dist);
% transform the bmu index into 2D
[bmurow bmucol] = ind2sub([nrows ncols],bmuindex);   

 function ed = getEuclideanDistance(trainingVector, somMmap, nrows, ncols, nfeatures)
 % Transform the nD representation of neurons into 2D
 neuronList = reshape(somMmap,nrows*ncols,nfeatures);               
 % Initialize Euclidean Distance
 ed = 0;
 for n = 1:size(neuronList,2)
     ed = ed + (trainingVector(n)-neuronList(:,n)).^2;
 end
ed = sqrt(ed);



