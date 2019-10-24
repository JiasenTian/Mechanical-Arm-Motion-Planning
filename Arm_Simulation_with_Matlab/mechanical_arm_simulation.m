%Final version of robotic arm
clear;
clc;
L1 = Link('d', 0, 'a', 0, 'alpha', 0, 'modified');
L2 = Link('d', 0, 'a', 1.25, 'alpha', pi/2, 'modified');
L3 = Link('d', 0, 'a', 10.5, 'alpha',0, 'modified');
L4 = Link('d', 13, 'a', 0, 'alpha',pi/2, 'modified');
L5 = Link('d', 0, 'a', 0, 'alpha', pi/2, 'modified');
L6 = Link('d', 10, 'a', 0, 'alpha',pi/2, 'modified');
b=isrevolute(L1);  %Link 
robot=SerialLink([L1,L2,L3,L4,L5,L6]);   %SerialLink 
robot.name='6 freedom degree robotic arm';
robot.comment='test 1';
robot.display();  %Link 
theta=[0 pi/2 pi/2 -pi pi 0];
robot.plot(theta);   %SerialLink 
robot.teach();
