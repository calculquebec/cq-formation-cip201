#!/bin/bash
#SBATCH --job-name=simple
#SBATCH --mem=1500M
#SBATCH --time=00:05:00

env | grep SLURM
sleep 60
