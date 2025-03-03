#!/bin/bash

#SBATCH --job-name=gmx-test
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=X
#SBATCH --mem-per-cpu=1G
#SBATCH --time=00:05:00

module load StdEnv/2023 gcc/12.3 openmpi/4.1.5
module load gromacs/2024.4

gmx mdrun \
	-s topol.tpr \
	-x results/traj.xtc \
	-cpo results/state.cpt \
	-c results/confout.gro \
	-e results/ener.edr \
	-g results/md.log
