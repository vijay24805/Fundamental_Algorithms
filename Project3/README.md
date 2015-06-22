The aim of this project is to model an instance of the k-server problem for three servers
with input given from the screen. Initially the servers are located at the top left cor-
ner (yellow), top right (red) and middle of the bottom line (blue). The user specifies a
sequence of request points by left mouseclicks in the window, terminated by a right
mouseclick. You show after each mouseclick a strategy of your choice (in thin yel-
low/red/blue lines) then after the final right mouseclick you compute and display the
optimal strategy (in thick yellow/red/blue lines). Your program then prints (to stdout)
the total length of both strategies, and the competitiveness ratio that you achieved.
You can find the optimal strategy by a dynamic-programming type argument: If the
input sequence was n request points long (p1, . . . , pn), you create an n×n×n×n array;
the entry cost[t][i][j][k] is the cost of the cheapest sequence of moves that starts at
the given starting positions and serves the requests up to time step t, and ends up with
the yellow server at pi, the red server at pj , and the blue server at pk. One of ijk must
be t, since the last request at pt was served, all other table entries have cost 1. Any
possible table entry must have been reached by moving one of the three servers from a
position at step t − 1.