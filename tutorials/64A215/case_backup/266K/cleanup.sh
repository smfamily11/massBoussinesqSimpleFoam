#!/bin/bash
cd ${0%/*} || exit 1    # run from this directory

# Source tutorial clean functions
. $WM_PROJECT_DIR/bin/tools/CleanFunctions

#Cleanup script
rm -r postProcessing
rm -r 0
cleanTimeDirectories

