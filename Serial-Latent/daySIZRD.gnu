#
#This file can be used with gnuplot. Simply type at the command line:
#gnuplot daySIZRD.gnu
#
plot "data/daySIZRD.dat" u 1:2 w lines title "S", "data/daySIZRD.dat" u 1:3 w lines title "I", "data/daySIZRD.dat" u 1:4 w lines title "Z", "data/daySIZRD.dat" u 1:5 w lines title "R", "data/daySIZRD.dat" u 1:6 w lines title "D"
pause -1 "hit return to continue"
