<h1 align="center">A 2D game SO_LONG 😄</h1>
<div align="center"><img src="./img/" /></div>

SO_LONG is the first graphical project in the main cursus of 42 school.
It is giving students the core base knowledge in terms of using a graphic
library: especialy the MiniLibX developped by 42 school, a simplified
version.

The [MinilibX](https://github.com/42Paris/minilibx-linux)
is a simple X-Window (X11R6) programming API in C, designed for students, suitable for X-beginners.

In this project, student must do a 2D game, where a player can collect items and quit the game via 
an exit or ESC button.
TO WIN the goal is: collect all items.
As bonus to this project, students can add animations/ennemies/a counter to showcase the number of
steps.

# GET STARTED

This project was coded for MacOs device, i haven't implemented the linux part.

To play my version of SO-LONG:

1 - clone the repo:

```
git clone https://github.com/BenjaminWach/42_so_long.git
```

2 - To compile the project (there is a special rule for norminette: make norminette)

```
make
```

3 - once the project compiled: type ./so_long map/.......ber (... being the name of the map
     with the extension ".ber"), you can create your own or use mine (map.ber, m.ber).

```
./so_long map/map.ber
```

## HOW TO PLAY

Press the W , S , A, D keys to move or the directionals keys.
You can restart the game by pressing R, or escape it with ESC (or the cross at the top left of the window).

| Keyboard | Action |
|---|---|
| <kbd>W</kbd>, <kbd>↑</kbd>| Move to the top |
| <kbd>S</kbd>, <kbd>↓</kbd>| Move to the bottom |
| <kbd>A</kbd>, <kbd>←</kbd>| Move to the left |
| <kbd>D</kbd>, <kbd>→</kbd>| Move to the right |
| <kbd>ESC</kbd>, `⎋`| Close or Quit |
| <kbd>R</kbd>, <kbd>r</kbd> | Restart |

## TECHNICAL SPEC or PARTICULARITIES

### MAP

| Characters | Description|                                              
|--|--|
| `0` | grassland |
| `1` | trees |
| `P` | player |
| `E` | exit |
| `C` | items |
| `M` | Monster |
---

```txt
111111111111111111
1P0100000000001001
100000000000010001
101100M000000C1001
101000000C00000001
10C00C001111100001
100001000C010C0001
10001101000M0001E1
111111111111111111
```

This project use image file format : .xpm, design are from artist and myself. (credits at the end)

I implemented a system to refresh the frames (FPS): cap at 30 (since my animations are smoother at 30, but you can change it
-> src -> game_loop.c-> (the condition of the loop). OR
-> utils -> fps -> check for the number in the function that initialize the last timer (should be 960).

There is a restart and dead mode, each states are display in the terminal: Victory, Death or Quit.
The map is a 64x64 pixels grid with object of 32x32 pixels.
The forest is randomly created (between two sprites for the trees) so a same map would be different, between each execution of the code.
More features can be implemented.

## FINAL WORDS

This project can be extremely time consuming because it is fun!
And having others to judge it or try it, make the process of coding this kind of project
Quite enjoyable!

If there any errors or sugestions, please contact me at @.

## CREDITS

itch.io:

  [penusbmic](https://penusbmic.itch.io/)

  [Cainos](https://cainos.itch.io/)
