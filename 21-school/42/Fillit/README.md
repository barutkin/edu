# Fillit

Fillit is not about recoding Tetris, even if it’s still a variant of this game. The program will take a file as parameter, which contains a list of Tetriminos, and arrange them in order to create the smallest square possible.
Obviously, the main goal is to find the smallest square in the minimal amount of time, despite an exponentially growing number of possibilities each time a piece is added.

[Subject](./fillit.en.pdf)

<img src="./fillit.svg" width="100%">

We used backtracking with tons of ifs. It's relatively fast.

<img src="./moulinette.png" width="100%" align="center">

[Useful source](https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909)
