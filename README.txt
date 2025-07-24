Names:
1) Yosef-Kovan_ID: 328607304
2) Shmuel-Friedman_ID: 312252588

====================  about the project  =====================
The project is a cat mouse chase game. the goal of the game is for the mouse the finish all levels successfully.

==================== Classes and objects ====================
the main class that runs the whole game in the Controller class. this class is in charge of the game loops, 
dealing with the menu. 
the Resource class is a singletone class that holds images sounds and music for the game duration.
Board object which is in charge of presenting the board and 
holding the main game logic, and dealing with the keys movement .
FileReader class that is in charge of reading the information from the file and holding this
information if neede throughout the level.
Menu class this is in charge of presenting the menu and all menu logic such as dealing with which 
buttons are clicked and opening the help screen if the button was clicked.
GameObject - this is the top of the tree for all the game moving and static objects. 
the tree will split into two branches: Static and MovingObjects each one will split its branches to the 
objects it  inheritance to.
the objects that inheirant from the static objects are: Wall, Key, Door, FreezeGift, TimeGift, CatGift, LifeGift. 
we used the hiding method for the static objects.
the objects that inheirant from the MovingObjects are Mouse and Cat.
We used a consts.h file that is incharge of holding the consts and the enums of the program.
====================  ====================
the cat chasing mouse algorithm recives the location of the mouse and chases the mouse according to its current location.
