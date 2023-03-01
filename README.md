Maps
The game is able to play any map you want as long as it follow some specific rules:

The map has to be a .ber file.
It can only contain some of the following characters:
Character	Object
1	Wall.
0	Empty space.
C	Collectable.
E	Exit.
P	Player starting position.
The map must be a rectangle surrounded by walls ‘1’.
It must have at least one exit ‘E’ and one collectable ‘C’. And only one player ‘P’.
Controls
Use WASD to move.

You can exit the game with esc or by pressing the closing window botton.

Execute the game
To play you can use some of the makefile rules, or execute the file so_long if it's been generated, passing the map you want to play as parameter (./so_long map.ber). The make file has the following rules:

Rule	Function
make	Generates so_long and an object file for each .c.
make clean	Deletes all object files.
make fclean	Deletes the object files and the so_long.
make re	makes fclean and make again.
 make play	Allows you to play all maps one at a time. To play the next map just press esc
