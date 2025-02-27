#!/bin/bash

module load StdEnv/2023 gcc/12.3 openmpi/4.1.5
module load gromacs/2024.4

gmx grompp -maxwarn 1 \
	-p input/topol.top \
	-c ${EBROOTGROMACS}/share/gromacs/top/spc216.gro \
	-f input/grompp.mdp \
	-o topol.tpr \
	-po mdout.mdp

mkdir results
