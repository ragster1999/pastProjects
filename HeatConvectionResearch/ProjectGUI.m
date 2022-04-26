function varargout = ProjectGUI(varargin)
% PROJECTGUI MATLAB code for ProjectGUI.fig
%      PROJECTGUI, by itself, creates a new PROJECTGUI or raises the existing
%      singleton*.
%
%      H = PROJECTGUI returns the handle to a new PROJECTGUI or the handle to
%      the existing singleton*.
%
%      PROJECTGUI('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in PROJECTGUI.M with the given input arguments.
%
%      PROJECTGUI('Property','Value',...) creates a new PROJECTGUI or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ProjectGUI_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ProjectGUI_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help ProjectGUI

% Last Modified by GUIDE v2.5 07-May-2019 10:44:27

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ProjectGUI_OpeningFcn, ...
                   'gui_OutputFcn',  @ProjectGUI_OutputFcn, ...
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


% --- Executes just before ProjectGUI is made visible.
function ProjectGUI_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ProjectGUI (see VARARGIN)

% Choose default command line output for ProjectGUI
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);
clc
movegui('center')
set(handles.UncookedGrill,'Value',1);
set(handles.RareGrill,'Value',0);
set(handles.MediumRareGrill,'Value',0);
set(handles.MediumGrill,'Value',0);
set(handles.MediumWellGrill,'Value',0);
set(handles.WellDoneGrill,'Value',0);
set(handles.UncookedPan,'Value',1);
set(handles.RarePan,'Value',0);
set(handles.MediumRarePan,'Value',0);
set(handles.MediumPan,'Value',0);
set(handles.MediumWellPan,'Value',0);
set(handles.WellDoneGrill,'Value',0);

% UIWAIT makes ProjectGUI wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = ProjectGUI_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes on button press in UncookedGrill.
function UncookedGrill_Callback(hObject, eventdata, handles)
% hObject    handle to UncookedGrill (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedGrill,'Value',1);
set(handles.RareGrill,'Value',0);
set(handles.MediumRareGrill,'Value',0);
set(handles.MediumGrill,'Value',0);
set(handles.MediumWellGrill,'Value',0);
set(handles.WellDoneGrill,'Value',0);


% Hint: get(hObject,'Value') returns toggle state of UncookedGrill


% --- Executes on button press in RareGrill.
function RareGrill_Callback(hObject, eventdata, handles)
% hObject    handle to RareGrill (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedGrill,'Value',0);
set(handles.RareGrill,'Value',1);
set(handles.MediumRareGrill,'Value',0);
set(handles.MediumGrill,'Value',0);
set(handles.MediumWellGrill,'Value',0);
set(handles.WellDoneGrill,'Value',0);


% Hint: get(hObject,'Value') returns toggle state of RareGrill


% --- Executes on button press in MediumRareGrill.
function MediumRareGrill_Callback(hObject, eventdata, handles)
% hObject    handle to MediumRareGrill (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedGrill,'Value',0);
set(handles.RareGrill,'Value',0);
set(handles.MediumRareGrill,'Value',1);
set(handles.MediumGrill,'Value',0);
set(handles.MediumWellGrill,'Value',0);
set(handles.WellDoneGrill,'Value',0);


% Hint: get(hObject,'Value') returns toggle state of MediumRareGrill


% --- Executes on button press in MediumWellGrill.
function MediumWellGrill_Callback(hObject, eventdata, handles)
% hObject    handle to MediumWellGrill (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedGrill,'Value',0);
set(handles.RareGrill,'Value',0);
set(handles.MediumRareGrill,'Value',0);
set(handles.MediumGrill,'Value',0);
set(handles.MediumWellGrill,'Value',1);
set(handles.WellDoneGrill,'Value',0);


% Hint: get(hObject,'Value') returns toggle state of MediumWellGrill


% --- Executes on button press in WellDoneGrill.
function WellDoneGrill_Callback(hObject, eventdata, handles)
% hObject    handle to WellDoneGrill (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedGrill,'Value',0);
set(handles.RareGrill,'Value',0);
set(handles.MediumRareGrill,'Value',0);
set(handles.MediumGrill,'Value',0);
set(handles.MediumWellGrill,'Value',0);
set(handles.WellDoneGrill,'Value',1);


% Hint: get(hObject,'Value') returns toggle state of WellDoneGrill


% --- Executes on button press in MediumGrill.
function MediumGrill_Callback(hObject, eventdata, handles)
% hObject    handle to MediumGrill (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedGrill,'Value',0);
set(handles.RareGrill,'Value',0);
set(handles.MediumRareGrill,'Value',0);
set(handles.MediumGrill,'Value',1);
set(handles.MediumWellGrill,'Value',0);
set(handles.WellDoneGrill,'Value',0);


% Hint: get(hObject,'Value') returns toggle state of MediumGrill


% --- Executes on button press in UncookedPan.
function UncookedPan_Callback(hObject, eventdata, handles)
% hObject    handle to UncookedPan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedPan,'Value',1);
set(handles.RarePan,'Value',0);
set(handles.MediumRarePan,'Value',0);
set(handles.MediumPan,'Value',0);
set(handles.MediumWellPan,'Value',0);
set(handles.WellDoneGrill,'Value',0);

% Hint: get(hObject,'Value') returns toggle state of UncookedPan


% --- Executes on button press in RarePan.
function RarePan_Callback(hObject, eventdata, handles)
% hObject    handle to RarePan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedPan,'Value',0);
set(handles.RarePan,'Value',1);
set(handles.MediumRarePan,'Value',0);
set(handles.MediumPan,'Value',0);
set(handles.MediumWellPan,'Value',0);
set(handles.WellDoneGrill,'Value',0);

% Hint: get(hObject,'Value') returns toggle state of RarePan


% --- Executes on button press in MediumRarePan.
function MediumRarePan_Callback(hObject, eventdata, handles)
% hObject    handle to MediumRarePan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedPan,'Value',0);
set(handles.RarePan,'Value',0);
set(handles.MediumRarePan,'Value',1);
set(handles.MediumPan,'Value',0);
set(handles.MediumWellPan,'Value',0);
set(handles.WellDoneGrill,'Value',0);

% Hint: get(hObject,'Value') returns toggle state of MediumRarePan


% --- Executes on button press in MediumWellPan.
function MediumWellPan_Callback(hObject, eventdata, handles)
% hObject    handle to MediumWellPan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedPan,'Value',0);
set(handles.RarePan,'Value',0);
set(handles.MediumRarePan,'Value',0);
set(handles.MediumPan,'Value',0);
set(handles.MediumWellPan,'Value',1);
set(handles.WellDoneGrill,'Value',0);

% Hint: get(hObject,'Value') returns toggle state of MediumWellPan


% --- Executes on button press in WellDonePan.
function WellDonePan_Callback(hObject, eventdata, handles)
% hObject    handle to WellDonePan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedPan,'Value',0);
set(handles.RarePan,'Value',0);
set(handles.MediumRarePan,'Value',0);
set(handles.MediumPan,'Value',0);
set(handles.MediumWellPan,'Value',0);
set(handles.WellDoneGrill,'Value',1);

% Hint: get(hObject,'Value') returns toggle state of WellDonePan


% --- Executes on button press in MediumPan.
function MediumPan_Callback(hObject, eventdata, handles)
% hObject    handle to MediumPan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
set(handles.UncookedPan,'Value',0);
set(handles.RarePan,'Value',0);
set(handles.MediumRarePan,'Value',0);
set(handles.MediumPan,'Value',1);
set(handles.MediumWellPan,'Value',0);
set(handles.WellDoneGrill,'Value',0);

% Hint: get(hObject,'Value') returns toggle state of MediumPan


% --- Executes on button press in StartGrillButton.
function StartGrillButton_Callback(hObject, eventdata, handles)
% hObject    handle to StartGrillButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
cla
index1=get(handles.UncookedGrill,'Value');
index2=get(handles.RareGrill,'Value');
index3=get(handles.MediumRareGrill,'Value');
index4=get(handles.MediumGrill,'Value');
index5=get(handles.MediumWellGrill,'Value');
index6=get(handles.WellDoneGrill,'Value');
axes(handles.AxesGrill)
if(index1==1)
    n=1;
elseif(index2==1)
    n=2;
elseif(index3==1)
    n=3;
elseif(index4==1)
    n=4;
elseif(index5==1)
    n=5;
elseif(index6==1)
    n=6;
end

% --- Executes on button press in PanStartButton.
function PanStartButton_Callback(hObject, eventdata, handles)
% hObject    handle to PanStartButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
cla
index7=get(handles.UncookedPan,'Value');
index8=get(handles.RarePan,'Value');
index9=get(handles.MediumRarePan,'Value');
index10=get(handles.MediumPan,'Value');
index11=get(handles.MediumWellPan,'Value');
index12=get(handles.WellDonePan,'Value');
axes(handles.AxesPan)
if(index7==1)
    n=1;
elseif(index8==1)
    n=2;
elseif(index9==1)
    n=3;
elseif(index10==1)
    n=4;
elseif(index11==1)
    n=5;
elseif(index12==1)
    n=6;
end


function TimerPan_Callback(hObject, eventdata, handles)
% hObject    handle to TimerPan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of TimerPan as text
%        str2double(get(hObject,'String')) returns contents of TimerPan as a double


% --- Executes during object creation, after setting all properties.
function TimerPan_CreateFcn(hObject, eventdata, handles)
% hObject    handle to TimerPan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function TimerGrill_Callback(hObject, eventdata, handles)
% hObject    handle to TimerGrill (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of TimerGrill as text
%        str2double(get(hObject,'String')) returns contents of TimerGrill as a double


% --- Executes during object creation, after setting all properties.
function TimerGrill_CreateFcn(hObject, eventdata, handles)
% hObject    handle to TimerGrill (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in PauseGrill.
function PauseGrill_Callback(hObject, eventdata, handles)
% hObject    handle to PauseGrill (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of PauseGrill


% --- Executes on button press in PausePan.
function PausePan_Callback(hObject, eventdata, handles)
% hObject    handle to PausePan (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of PausePan


% --- Executes on button press in PorkButton.
function PorkButton_Callback(hObject, eventdata, handles)
% hObject    handle to PorkButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of PorkButton


% --- Executes on button press in SteakButton.
function SteakButton_Callback(hObject, eventdata, handles)
% hObject    handle to SteakButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of SteakButton


% --- Executes on button press in ChickenButton.
function ChickenButton_Callback(hObject, eventdata, handles)
% hObject    handle to ChickenButton (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of ChickenButton
