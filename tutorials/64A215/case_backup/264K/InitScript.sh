#!/bin/bash
#blockMesh
checkMesh
mkdir -p 0
cp -r 0.org/* 0/
cp -r system/polyMesh constant/.
massBuoyantBoussinesqSimpleFoam
