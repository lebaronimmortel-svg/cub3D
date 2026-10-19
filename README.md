*This project has been created as part of the 42 curriculum by lukrodri, alexfuen.*

## Description
cub3D is a project inspired by the world-famous Wolfenstein 3D game — the first true First-Person Shooter in history. Using ray-casting principles, it renders a dynamic 3D view of the inside of a maze from a first-person perspective.

The project is split into a mandatory part and a bonus part:

**Mandatory part** incorporates the following main features:
* Parses a `.cub` scene description file containing texture paths, floor/ceiling RGB colors, and the map grid.
* Validates the map thoroughly: checks for a closed/surrounded layout, a single player spawn, only valid characters (`0`, `1`, `N`, `S`, `E`, `W`), and correct header syntax.
* Renders wall textures that vary depending on the cardinal direction of the face (North, South, East, West) using the DDA (Digital Differential Analysis) ray-casting algorithm.
* Applies a flat solid color to the floor and a different one to the ceiling.
* Handles player movement with `W`, `A`, `S`, `D` and camera rotation with the left/right arrow keys.
* Closes the window cleanly on `ESC` or by clicking the window's red cross.

**Bonus part** extends the mandatory version with:
* Wall collision detection preventing the player from walking through walls or doors.
* A minimap displayed in the top-left corner showing the map layout and the player's position in real time.
* Openable and closable doors: door cells are auto-detected at startup and can be toggled with a left mouse click while facing them.
* A weapon animation system: an idle hand sprite, a 10-frame walk animation, and a 6-frame shooting animation triggered by the left mouse button.
* Mouse look: the camera rotates smoothly by tracking horizontal mouse movement, with the cursor hidden and re-centered every frame.

Memory is properly managed throughout; all heap-allocated resources (map grid, texture paths, MLX images, contexts, and windows) are freed on exit.

## Instructions
To compile and run the project, the standard `Makefile` rules apply:
* Run `make` or `make all` to compile the mandatory executable.
* Run `make bonus` to compile the bonus executable `cub3D_bonus`.
* Once compiled, launch the program by passing a `.cub` scene file as argument:
  ```
  ./cub3D path/to/scene.cub
  ./cub3D_bonus path/to/scene.cub
  ```
* Other available `Makefile` rules include `clean`, `fclean`, and `re`.

> **Note:** This project uses **MacroLibX** as its graphical library (a modern re-implementation of MiniLibX).

### Scene file format
The `.cub` file must specify, in any order before the map, the following identifiers:
```
NO ./path/to/north_texture.png
SO ./path/to/south_texture.png
WE ./path/to/west_texture.png
EA ./path/to/east_texture.png
F 220,100,0
C 225,30,0
```
The map must appear last and may only contain the characters `0` (empty), `1` (wall), and `N`/`S`/`E`/`W` (player start + orientation). The map must be fully enclosed by walls.

### Controls

| Key / Action | Effect |
|---|---|
| `W` / `S` | Move forward / backward |
| `A` / `D` | Strafe left / right |
| `←` / `→` | Rotate camera left / right |
| Mouse move (bonus) | Rotate camera horizontally |
| Left click (bonus) | Open / close a door in front of the player |
| `ESC` | Quit the program |
| Exit cross | Quit the program |

## Resources

Resources for this project were:

- https://lodev.org/cgtutor/raycasting.html — the main reference for understanding and implementing the DDA ray-casting algorithm
- https://man7.org/linux/man-pages/ — Linux man pages for system calls
- https://github.com/seekrs/MacroLibX — MacroLibX documentation and source

