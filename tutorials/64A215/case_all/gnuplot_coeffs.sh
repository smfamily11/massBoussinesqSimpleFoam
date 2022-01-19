#!/bin/bash

gnuplot -persist > /dev/null 2>&1 << EOF
	set title "Coefficients vs. Time"
	set xlabel "Time / Iteration"
	set ylabel "Coefficients (Drag/Lift/Mass)"

	plot	"coefficient.txt" using 1:2 title 'Cd' with linespoints,\
			"coefficient.txt" using 1:3 title 'Cl' with linespoints,\
			"coefficient.txt" using 1:4 title 'Cm' with linespoints

EOF

#-----------------------------------------------------------------#
