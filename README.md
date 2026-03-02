*This project has been created as part of the 42 curriculum by yucchen, sileow.*

# cub3D 🧱

## Description
cub3D renders a 3D-like view using raycasting from a 2D map.

**cub3D** is a graphic design project inspired by the world-famous Wolfenstein 3D game, which is considered the first true First Person Shooter (FPS) ever created.

The goal of this project is to create a "realistic" 3D graphical representation of the inside of a maze from a first-person perspective using the **Raycasting** principles.

Built with C and the **miniLibX** graphical library, this project serves as a deep dive into practical applications of mathematics, window management, and event handling.

### Main Flow:
1. **Parsing:** Parse and validate the `.cub` file (textures, colors, map closure, single player).
	- .cub format:
      - NO SO WE EA textures
      - F C colors
      - Closed map with one player (N/S/E/W)
2. **Initialization:** Set up the player's position, direction vectors, and the camera plane.
3. **MLX Setup:** Initialize the MiniLibX window, image buffers, and key/render hooks.
4. **Raycasting:** Utilize the **Digital Differential Analysis (DDA)** to shoot rays, detect wall hits, and project distances to prevent fish-eye distortion.

TODO: Add N/S/W/E char to know the direction
5. **Rendering:** Load `.xpm` images and map texture to walls (North/South/East/West)

6. **Interaction:** Handle player movement (`W`, `A`, `S`, `D`), camera rotation(Left/Right)

TODO:
7. **Bonus:** Wall collisions detection (Check the `norm_map[(int)y][(int)x]` before updating the position), a minimap system, doors which can open and close, animated sprites, rotate the point of view with the mouse

## Instructions

### Compilation
To compile the mandatory part of the project, simply run:
```bash
make
```

### Execution
Run the executable with a valid map file passed as an argument:
```bash
./cub3D maps/valid/normal_rectangle.cub
```

### Controls
| Key   | Action              |
|-------|---------------------|
| `W`   | Move Forward        |
| `S`   | Move Backward       |
| `A`   | Move Left           |
| `D`   | Move Right          |
| `<-`  | Rotate Camera Left  |
| `->`  | Rotate Camera Right |
| `ESC` | Exit Game           |

## Parser Design
The parser is implemented step by step.
Each step validates its input before moving to the next step.
If any step fails, the program safely frees allocated memory, prints a descriptive error, and exits.

### Step 1 - File Validation
- Check argument count (`argc == 2`)
- Verify the `.cub` file extension
- Ensure the file can be opened

### Step 2 - Read File into Lines
- Read the entire file using `get_next_line`
- Strip trailing newline (`\n`)
- Store into `char **lines`

### Step 3 - Parse Configuration Lines, locate map start & parse map lines
- Skip blank lines
- Parse the 6 required identifiers in any order
	- Textures (`NO`, `SO`, `WE`, `EA`) and check the file paths
	- Colors (`F`, `C`) and ensure exactly 3 values in the range `[0,255]`
- First line containing map tiles (`1`, `0`, `N`, `S`, `E`, `W`) marks `map_start`
- No blank lines allowed inside the map
- No configuration lines after the map starts
- Only valid map characters are allowed

### Step 4 - Check Configuration Identifiers Count
- Each identifier must appear exactly once
	- Textures (`NO`, `SO`, `WE`, `EA`)
	- Colors (`F`, `C`)	

### Step 5 - Collect Map Lines
- Extract map lines from `map_start` to `EOF`

### Step 6 - Compute Map Dimensions
- Compute max width among all map lines
- Store the map width & height

### Step 7 - Normalize Map
- Allocate a rectangular map of size `map_height x map_width`
- Pad shorter lines with spaces (`' '`)
- Preserve original layout

### Step 8 - Player Extraction
- Locate exactly one player (`N`, `S`, `E` , `W`)
- Store player position at tile center (`+0.5`) and direction
- Replace player tile with `'0'`

### Step 9 - Map Validation (Wall Check)
- Ensure the map is closed by walls
	- Border checks
		- If the top row contains any `0`, `N`, `S`, `E`, `W` -> fail (Step 3)
		- If the bottom row contains any `0`, `N`, `S`, `E`, `W` -> fail (Step 5)
		- If the first column contains any `0`, `N`, `S`, `E`, `W` -> fail (Step 6)
		- If the last column contains any `0`, `N`, `S`, `E`, `W` -> fail (Step 6)
	- Neighbor checks
		- For every `'0'`, check its 4 neighbors != ' '
			- (x, y)
			- North: Up (x, y - 1)
			- South: Down (x, y + 1)
			- West: Left (x - 1, y)
			- East: Right (x + 1, y)

TODO:
## Resources
References
- Lode's Computer Graphics Tutorial: Raycasting (https://lodev.org/cgtutor/raycasting.html)
- Crazy Simple Raycasting E2 - 🎮 How to make awesome 3d games in Scratch (https://www.youtube.com/watch?v=Vihr-PVjWF4)
- Make Your Own Raycaster Part 1 (https://www.youtube.com/watch?v=gYRrGTC7GtA)

### How AI was used
AI tools were used as a learning aid.
- To learn 

## Notes (Norm, Valgrind)
- This project follows the 42 Norm rules
- Memory and file descriptor leaks checked with **Valgrind**
```bash
valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes ./cub3D maps/valid/normal_rectangle.cub
```
