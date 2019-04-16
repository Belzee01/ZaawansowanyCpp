In order to run this application you will need:
(either)
- Visual Studio C++ (compatibile with v2019)
- CMake

How to run:<br/>
There are two ways to run the program. First is:
1. Visual Studio:
- there are added solution and project files, so there should be not problem importing/openning the project in Visual Studio compatibile with version 2019 Community Edition in which this project has been prepared.

2. Using CMake:
- you will need cmake version at least 3.5.1 
- in project folder run:<br/>
`cmake .`<br/>
then<br/>
`make`<br/>
then<br/>
`./test_1`<br/>

After you have used one of the presented methods to run the program you should see command prompt window asking you to pass three variables:
- number of tasks
- number of processes
- number of communication channels

After you've passed the last variable there should be created file called `output` in which there is definition of the graph, processes and communication (plus other related data).
!!!Important!!! Note that, if you compile it under Unix the data in the `output` file WILL BE IN ONE LINE.