*This project has been created as part of the 42 curriculum by lukrodri, alexfuen.*

# cub3D

# Description

*cub3D* is a 3D FPS game developed for the 42 `cub3D` project.
It uses a ray-casting algorithm to calculate distances and display a 3D environment.

### Key concepts

- Strict parsing
- Memory management
- Ray-casting
- Optimization
- Game design

### External functions

Functions are grouped by the library they come from.

**libc**

* `printf`, `malloc`, `free`, `write`, `open`, `read`, `close`.
* `exit`.
* `gettimeofday` — frame timing / delta time.

**math (`libm`)**

* `sin`, `cos` — player and camera rotation (`move_utils.c`, `move_utils_bonus.c`).
* `fabs` — absolute distances in the DDA algorithm (`init_utils.c`, `raycasting_utils_bonus.c`).
* `floor` — texture X coordinate computation (`raycasting.c`, `raycasting_bonus.c`).
* `sqrt` — vector normalization (bonus, `init_utils_bonus.c`).

**MacroLibX (`libmlx.so`)**

* Context / window: `mlx_init`, `mlx_new_window`, `mlx_destroy_window`, `mlx_destroy_context`.
* Images: `mlx_new_image`, `mlx_new_image_from_file`, `mlx_destroy_image`, `mlx_get_image_pixel`, `mlx_set_image_pixel`, `mlx_put_image_to_window`.
* Events and loop: `mlx_on_event`, `mlx_add_loop_hook`, `mlx_loop`, `mlx_loop_end`.
* Mouse (bonus): `mlx_mouse_get_pos`, `mlx_mouse_move`, `mlx_mouse_hide`.


### Libraries

* `libc`
* `math`
* `MacroLibX`

## Rules

This game is played using a file in .cub format as a map.
The `.cub` file must specify, in any order before the map, the following identifiers:
 - the image used for each wall texture
 - the color of the floor and the ceiling in RGB format
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
| Left click (bonus) | Shoot |
| `ESC` | Quit the program |
| Exit cross | Quit the program |


## Team Information

| Member | 42 login | Role | Main responsibilities |
| --- | --- | --- | --- |
| Alexandre | `alexfuen` | Developer | parsing, display, design
| Lukas | `lukrodri` | Developer | ray-casting, minimap

---

# Instructions

## Requirements

The project requires:

- Make
- Clang Compiler
- X Window System

---

## Configuration

Clone the repository:

```bash
git clone <repository-url>
cd cub3D
```

---

## Start the Application

Build with:
```bash
make
```
You can also build the bonus version:
```bash
make bonus
```

Then launch with:
```bash
./cub3D path/to/map/file
```
Or launch the bonus version with:
```bash
./cub3D_bonus path/to/map/file
```

---

# Resources

Main documentation and references used during development:

- https://lodev.org/cgtutor/raycasting.html — the main reference for understanding and implementing the DDA ray-casting algorithm
- https://man7.org/linux/man-pages/ — Linux man pages
- https://github.com/seekrs/MacroLibX — MacroLibX documentation and source

## AI Usage

AI tools were used as a supplementary resource during the project, mainly for technical research, troubleshooting, reviewing edge cases, checking project requirements and assisting with documentation.
The team remained responsible for the technical decisions, implementation and final validation of the project.