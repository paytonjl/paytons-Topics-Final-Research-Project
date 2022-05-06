# paytons-Topics-Final-Research-Project
In each folder you will want to run these five comands in the order given to have it run 1000 test on the program. 
Currently the array in these files is a mostly sorted array to change the array you will have to go into the c program and manualy change it. In the Quick sort c file has to be a array of 100 and the array will have to be changed to allow a diffrent size of array. 

COMANDS
clang -emit-llvm -S *.c
instrument --readable sqrt.ll
profile ./llfi/sqrt-profiling.exe
injectfault ./llfi/sqrt-faultinjection.exe
python3 measure.py
