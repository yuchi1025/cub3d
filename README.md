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
