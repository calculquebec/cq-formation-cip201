#!/bin/bash
#SBATCH --job-name=tri-sort
#SBATCH --mem=2G
#SBATCH --time=00:05:00

for iter in 32000 64000 128000
do
  ./bubble $iter
done

echo '---'

for iter in 128000 1280000 12800000 128000000
do
  ./quick $iter
done
