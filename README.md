# tetris

## Description
This game is my second project in C++. The goal of the game is to have the biggest number of points. Every time the score changes, the speed of the the game increases. 

You can find the installers for both Linux and Windows in the "release_packages" directory.

## Installation
First, you need to install SFML version 2.5 (or higher on Windows) as well as CMake. After completing this step, you will need to update the SFML PATH according to the location where you installed SFML. Modify this in the CMakeLists.txt file (line 6 for Linux and line 8 for Windows).

To compile and obtain the executable, create a build directory in the game, navigate to the directory, and use the following commands:
<pre>
    cmake ..
    cmake --build .
</pre>
You can find the executable in the build directory.

## Author
Alicia Plath
