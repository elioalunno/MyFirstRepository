Exam program C++ elio alunno camelia
#########################################################################################################
Structure of directories

- MYFIRSTREPOSITORY contains C++ classes
- BIN contains the executable of the program
- MACROS	contains the root macro
- OBJ contains the object file
- SRC contains the source files of the classe
- UTIL contains the main program
Makefile
Readme.md
particle.dat
########################################################################################################
1)Run the main program
open a terminal and 
- cd /MyFisrtRepository
- make clean
- make
- EXECUTE THE PROGRAM: ./bin/FirstParticleExercise
it counts the negative and positive particle in particle.dat file, then creates a particleOutput.root file in the folder macros/

2)Run the root macro
- cd macros/
- root -l histFile.C











