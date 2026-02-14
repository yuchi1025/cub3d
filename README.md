*This project has been created as part of the 42 curriculum by yucchen, sileow.*

# cub3D 🧱

Cub3D renders a 3D-like view using raycasting from a 2D map.

Main flow:
- Parse .cub file (textures, colors, map) -> validate walls & player
- Initialize player (position, direction, plane)
- Initialize MLX
- Main loop:
  - handle input
  - cast rays
  - draw walls

.cub format:
- NO SO WE EA textures
- F C colors
- closed map with one player (N/S/E/W)

## Parser Design
The parser is implemented step by step.
Each step validates its input before moving to the next step.
If any step fails, the program exits.

### Step 1 - File validation
- Check argument count
- Check `.cub` file extension
- Check file can be opened

### Step 2 - Read file into lines
- Read entire file using `get_next_line`
- Strip trailing newline (`\n`)
- Store into `char **lines`

### Step 3 - Parse configuration lines, locate map start & parse map lines
- Skip blank lines
- Parse configuration lines
	- Parse the 6 required identifiers in any order
		- Textures (`NO`, `SO`, `WE`, `EA`) and check the path
		- Colors (`F`, `C`) and exactly 3 values in range `[0,255]`

- First line containing map tiles (`1`, `0`, `N`, `S`, `E`, `W`) marks `map_start`
- No blank lines allowed inside the map
- No configuration lines allowed after the map begins
- Only valid map characters are allowed

### Step 4 - Check configuration identifiers count
- Each identifier must appear exactly once
	- Textures (`NO`, `SO`, `WE`, `EA`)
	- Colors (`F`, `C`)	

### Step 5 - Collect map lines
- Extract map lines from `map_start` to EOF

### Step 6 - Compute map dimensions
- Compute max width among all map lines
- Store map width & height

### Step 7 - Normalize map
- Allocate a rectangular map of size `map_height x map_width`
- Pad shorter lines with spaces (`' '`)
- Preserve original layout

### Step 8 - Player extraction
- Locate exactly one player (`N`, `S`, `E` , `W`)
- Store player position at tile center (`+0.5`) and direction
- Replace player tile with `'0'`

### Step 9 - Map validation
- Ensure the map is closed by walls
	- Border checks
		- If the top row contains any `0`, `N`, `S`, `E`, `W` -> fail (Step 3)
		- If the bottom row contains any `0`, `N`, `S`, `E`, `W` -> fail (Step 5)
		- If the first column contains any `0`, `N`, `S`, `E`, `W` -> fail (Step 6)
		- If the last column contains any `0`, `N`, `S`, `E`, `W` -> fail (Step 6)
	- For every '0', check 4 neighbors != ' '
		- (x, y)
		- up (x, y - 1)
		- down (x, y + 1)
		- left (x - 1, y)
		- right (x + 1, y)
