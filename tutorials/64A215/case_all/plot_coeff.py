#!/usr/bin/python

import os
import sys
import math

#coeffs_file = "postProcessing/forceCoeffs/0/forceCoeffs.dat"
#coeffs_file = "Results_T_AOA_const/aero_T260/forceCoeffs/0/forceCoeffs.dat"
coeffs_file = "Results_T262_AOA/aero_T262_aoa15/forceCoeffs/0/forceCoeffs.dat"

if not os.path.isfile(coeffs_file):
	print "Coefficients file not found at "+coeffs_file
	print "Need to check and correct the file path in the directory"
	print "Exiting."
	sys.exit()

def line2dict(line):
	tokens_unprocessed = line.split()
	tokens = [x.replace(")","").replace("(","") for x in tokens_unprocessed]
	floats = [float(x) for x in tokens]
	data_dict = {}
	data_dict['time'] = floats[0]
	coeff_dict = {}
	coeff_dict['Cm'] = floats[1]
	coeff_dict['Cd'] = floats[2]
	coeff_dict['Cl'] = floats[3]
	data_dict['cm'] = coeff_dict['Cm']
	data_dict['cd'] = coeff_dict['Cd']
	data_dict['cl'] = coeff_dict['Cl']
	return data_dict

time = []
cm = []
cd = []
cl = []
with open(coeffs_file,"r") as datafile:
	for line in datafile:
		if line[0] == "#":
			continue
		data_dict = line2dict(line)
		time += [data_dict['time']]
		cm += [data_dict['cm']]
		cd += [data_dict['cd']]
		cl += [data_dict['cl']]

datafile.close()

outputfile = open('coefficient.txt','w')
for i in range(0,len(time)):
	outputfile.write(str(time[i])+' '+str(cm[i])+' '+str(cd[i])+' '+str(cl[i])+'\n')
outputfile.close()

os.system("./gnuplot_coeffs.sh")

#-----------------------------------------------------#
