# Cat and Mouse Game


![System diagram](./images/cat-mouse-image.png)


A classic cat-and-mouse chase game built with C++ and SFML. Guide the mouse through multiple levels, collect cheese, avoid cats, and use special items to survive and win!

---

## Features
- Multiple levels with increasing difficulty
- Animated graphics and sound effects (SFML-based)
- Power-ups: extra lives, freeze cats, add time, etc.
- Menu system with help screen
- Customizable level files

---

## Screenshots

---

## Installation & Running

### Prerequisites
- C++17 or later
- [SFML 2.6.x](https://www.sfml-dev.org/) (graphics, audio, window)
- CMake 3.26+

### Build Instructions
1. **Install SFML** and ensure its path is set in `CMakeLists.txt` (default: `C:/SFML/SFML-2.6.0`).
2. Clone this repository and open a terminal in the project root.
3. Run:
   ```sh
   cmake -S . -B build
   cmake --build build
   ```
4. Copy all files from `resources/` (images, sounds, music, fonts, txt) to the build output directory if not done automatically.
5. Run the executable from the build directory.

---

## Project Structure
- `src/` — Main source files
  - `main.cpp`: Entry point
  - `Controller.cpp/h`: Game loop, menu, and level management
  - `Board.cpp/h`: Handles the game board and main logic
  - `Menu.cpp/h`: Menu and help screen
  - `FileReader.cpp/h`: Loads level files
  - `Resources.cpp/h`: Singleton for images, sounds, fonts
  - `GameObject.cpp/h`, `Static.cpp/h`, `MovingObject.cpp/h`: Base classes for all objects
  - `Mouse.cpp/h`, `Cat.cpp/h`, etc.: Game entities
- `resources/`
  - `images/`, `sounds/`, `music/`, `font/`, `txt/`: All required assets
- `include/` — Header files
- `CMakeLists.txt` — Build configuration

---

## Level Design
Levels are defined in text files in `resources/txt/`. The main file `Levels.txt` lists the order of level files. Each level file uses characters to represent objects:

**Sample Level File:**
```
10 10 0
#        #
#        #  
##D###  ^#     
#  * #   #  
#    #   #
######   #    
# F  %  ^# 
#L       # 
# $* * I #
##########
```
- First line: `<rows> <cols> <time_limit>`
- Symbols:
  - `#` Wall
  - `%` Mouse (player)
  - `^` Cat (enemy)
  - `*` Cheese
  - `D` Door
  - `F` Key
  - `$` Cat Gift
  - `T` Time Gift
  - `I` Freeze Gift
  - `L` Life Gift

Add new levels by creating new files and listing them in `Levels.txt`.

## Credits

 Yosef Kovan

## Acknowledgments
- [SFML](https://www.sfml-dev.org/) for multimedia support
- All open-source asset authors 
