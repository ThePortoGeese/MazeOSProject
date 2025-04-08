MazeOS is a project I made to present in an academic environment. I made this mostly to study data structures and building an application with a functional UI, things which I can say I succeeded in.
The Cells have pointers to others cells which allows the whole Maze to be connected and stored in a X vectors of cells (X being dimensions). This also allows it to do Mazes in other dimensions besides 2d, theoretically.
I only added QObject integration to the 2dmazes class which is under the QMazes class. I only did it this way because I didnt need to use mazes that weren't 2d.

Only 3 algorithms were implemented because I'm lazy: The classic recursive function, the wall follower algorithm and the dead end filling algorithm.


To open the project on your QCreator, open the .pro document with it, that should render the whole thing there.
