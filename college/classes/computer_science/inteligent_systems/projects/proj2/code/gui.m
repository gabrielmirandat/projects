function varargout = gui(varargin)
% GUI MATLAB code for gui.fig
%      GUI, by itself, creates a new GUI or raises the existing
%      singleton*.
%
%      H = GUI returns the handle to a new GUI or the handle to
%      the existing singleton*.
%
%      GUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK inn GUI.M with the given input arguments.
%
%      GUI('Property','Value',...) creates a new GUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before gui_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to gui_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help gui

% Last Modified by GUIDE v2.5 08-Jun-2016 19:52:08

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @gui_OpeningFcn, ...
                   'gui_OutputFcn',  @gui_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before gui is made visible.
function gui_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to gui (see VARARGIN)

% Choose default command line output for gui
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes gui wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = gui_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;

%% creations (not important)

% --- Executes during object creation, after setting all properties.
function LR_CreateFcn(hObject, eventdata, handles)
% hObject    handle to LR (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes during object creation, after setting all properties.
function HLNN_CreateFcn(hObject, eventdata, handles)
% hObject    handle to HLNN (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes during object creation, after setting all properties.
function ITP_CreateFcn(hObject, eventdata, handles)
% hObject    handle to ITP (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes during object creation, after setting all properties.
function WSOMM_CreateFcn(hObject, eventdata, handles)
% hObject    handle to WSOMM (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes during object creation, after setting all properties.
function LR0_CreateFcn(hObject, eventdata, handles)
% hObject    handle to LR0 (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes during object creation, after setting all properties.
function LRD_CreateFcn(hObject, eventdata, handles)
% hObject    handle to LRD (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes during object creation, after setting all properties.
function INN_CreateFcn(hObject, eventdata, handles)
% hObject    handle to INN (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes during object creation, after setting all properties.
function NND_CreateFcn(hObject, eventdata, handles)
% hObject    handle to NND (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

% --- Executes during object creation, after setting all properties.
function ITS_CreateFcn(hObject, eventdata, handles)
% hObject    handle to ITS (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


%% variables
% LR - PERCEPTRON: LEARNING RATE
% HLNN - PERCEPTRON: HIDDEN LAYER NEURONS NUMBER
% ITP - PERCEPTRON: NUMBER OF ITERATIONS
% WSOMM - SOM: WIDTH SOM MAP
% LR0 - SOM: INITIAL LEARNING RATE
% LRD - SOM: LEARNING RATE DECAY
% INN - SOM: INITIAL NEURON NEIGHBOR
% NND - SOM: NEURON NEIGHBOR DECAY
% ITS - SOM: NUMBER OF ITERATIONS

%% callbacks

function LR_Callback(hObject, eventdata, handles)
% hObject    handle to LR (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of LR as text
%        str2double(get(hObject,'String')) returns contents of LR as a double

LR = str2double(get(hObject,'String')); %returns contents of LR as a double
assignin('base', 'LR', LR);

function HLNN_Callback(hObject, eventdata, handles)
% hObject    handle to HLNN (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of HLNN as text
%        str2double(get(hObject,'String')) returns contents of HLNN as a double

HLNN = str2num(get(hObject,'String')); %returns contents of HLNN as integer
assignin('base', 'HLNN', HLNN);

function ITP_Callback(hObject, eventdata, handles)
% hObject    handle to ITP (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of ITP as text
%        str2double(get(hObject,'String')) returns contents of ITP as a double

ITP = str2num(get(hObject,'String')); %returns contents of ITP as a integer
assignin('base', 'ITP', ITP);

function WSOMM_Callback(hObject, eventdata, handles)
% hObject    handle to WSOMM (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of WSOMM as text
%        str2double(get(hObject,'String')) returns contents of WSOMM as a double

WSOMM = str2num(get(hObject,'String')); %returns contents of WSOMM as a integer
assignin('base', 'WSOMM', WSOMM);

function LR0_Callback(hObject, eventdata, handles)
% hObject    handle to LR0 (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of LR0 as text
%        str2double(get(hObject,'String')) returns contents of LR0 as a double

LR0 = str2double(get(hObject,'String')); %returns contents of LR0 as a double
assignin('base', 'LR0', LR0);

function LRD_Callback(hObject, eventdata, handles)
% hObject    handle to LRD (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of LRD as text
%        str2double(get(hObject,'String')) returns contents of LRD as a double

LRD = str2double(get(hObject,'String')); %returns contents of LRD as a double
assignin('base', 'LRD', LRD);

function INN_Callback(hObject, eventdata, handles)
% hObject    handle to INN (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of INN as text
%        str2double(get(hObject,'String')) returns contents of INN as a double

INN = str2num(get(hObject,'String')); %returns contents of INN as a integer
assignin('base', 'INN', INN);

function NND_Callback(hObject, eventdata, handles)
% hObject    handle to NND (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of NND as text
%        str2double(get(hObject,'String')) returns contents of NND as a double

NND = str2double(get(hObject,'String')); %returns contents of INN as a double
assignin('base', 'NND', NND);

function ITS_Callback(hObject, eventdata, handles)
% hObject    handle to ITS (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of ITS as text
%        str2double(get(hObject,'String')) returns contents of ITS as a double

ITS = str2num(get(hObject,'String')); %returns contents of ITS as a integer
assignin('base', 'ITS', ITS);

%% begin 

% --- Executes on button press in GetData.
function GetData_Callback(hObject, eventdata, handles)
% hObject    handle to GetData (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

fprintf('Loading data..\n');

% Load Training Data
inputX = loadMNISTImages('data/si/train-images.idx3-ubyte');
inputX = inputX'; %transpose
inputY = loadMNISTLabels('data/si/train-labels.idx1-ubyte');
inputY( inputY==0 )=10; 
assignin('base', 'inputX', inputX);
assignin('base', 'inputY', inputY);

% Load Training Data
inputXtest = loadMNISTImages('data/si/t10k-images.idx3-ubyte');
inputXtest = inputXtest'; %transpose
inputYtest = loadMNISTLabels('data/si/t10k-labels.idx1-ubyte');
inputYtest( inputYtest==0 )=10; 
assignin('base', 'inputXtest', inputXtest);
assignin('base', 'inputYtest', inputYtest);
fprintf('Data loaded..\n');

fprintf('Initializing variables..\n');
assignin('base','LR',0.1);
assignin('base','HLNN',25);
assignin('base','ITP',700);
assignin('base','WSOMM',15);
assignin('base','LR0',0.5);
assignin('base','LRD',0.01);
assignin('base','INN',20);
assignin('base','NND',0.02);
assignin('base','ITS',500);
fprintf('Initialized variables..\n');

% --- Executes on button press inn pushbuttonRun.
function pushbuttonRun_Callback(hObject, eventdata, handles)
% hObject    handle to pushbuttonRun (see GCBO)
% eventdata  reserved - to be defined inn a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

fprintf('Running..\n')

% get all data
inputX = evalin('base','inputX');
inputY = evalin('base','inputY');
inputXtest = evalin('base','inputXtest');
inputYtest = evalin('base','inputYtest');
LR = evalin('base','LR');
HLNN = evalin('base','HLNN');
ITP = evalin('base','ITP');
WSOMM = evalin('base','WSOMM');
LR0 = evalin('base','LR0');
LRD = evalin('base','LRD');
INN = evalin('base','INN');
NND = evalin('base','NND');
ITS = evalin('base','ITS');

inputXm = inputX(1:1000,:);
inputYm = inputY(1:1000,:);
assignin('base','inputXm',inputXm);
assignin('base','inputYm',inputYm);

[xX yX] = size(inputXm);

% train som
fprintf('SOM..\n')
somMap = som(yX, WSOMM, ITS, inputXm, LR0, LRD, INN, NND, 2, inputYm);
assignin('base', 'somMap', somMap);
fprintf('Finished SOM!.\n')

%%
% get perceptron input
sz = size(somMap);
somMapReshaped = reshape(somMap,sz(3),sz(1)*sz(2));
percepTrain = inputXm*somMapReshaped;
assignin('base','percepTrain',percepTrain);
percepTest = inputXtest*somMapReshaped;
assignin('base','percepTest',percepTest);

% train perceptron
fprintf('Perceptron..\n')
[theta1 theta2] = multilayerPerceptron(sz(1)*sz(2), LR, ITP, HLNN, percepTrain, inputYm);
assignin('base', 'theta1', theta1);
assignin('base', 'theta2', theta2);
fprintf('Finished Perceptron!.\n')

% predict
fprintf('Predict ...\n')

pred_train = predictmp(theta1, theta2, percepTrain, 1);
fprintf('\nTraining Set Accuracy: %f\n', mean(double(pred_train == inputYm)) * 100);

pred_test = predictmp(theta1, theta2, percepTest, 1);
fprintf('Test Set Accuracy: %f\n', mean(double(pred_test == inputYtest)) * 100);
%%