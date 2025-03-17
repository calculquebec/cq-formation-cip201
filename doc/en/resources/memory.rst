Memory
======

`Français <../../fr/resources/memory.html>`_

The analysis of memory requirements is similar to that done for time
requirements, but with different metrics.

Recall the two Slurm options to request memory:

- ``--mem=<amount>``, memory
  `per compute node <https://slurm.schedmd.com/sbatch.html#OPT_mem>`_.
- ``--mem-per-cpu=<amount>``, memory
  `per CPU core <https://slurm.schedmd.com/sbatch.html#OPT_mem-per-cpu>`_.

  - Default: ``256M``

Why set a memory limit?
-----------------------

- On the `national clusters
  <https://docs.alliancecan.ca/wiki/National_systems#List_of_compute_clusters>`_,
  the vast majority of compute nodes have a little less than **4G of usable
  memory per CPU core**.

  - A handful of nodes have between 16G and 32G per core. Since there are few of
    them, asking for that much memory can lead to a longer wait time.

- A limit protects the compute node in case your program tries to use too much
  memory.
- In any case, you probably need to change the default value of 256M per CPU
  core.

In conclusion, **it is necessary to specify an amount of memory**, with of
course a safety margin (such as 20 % more than you expect to need).

Assessing memory using your computer
------------------------------------

Using the Task Manager (Windows), the Activity Monitor (Mac OS),
or the ``top`` command, you can check your program’s memory usage. For a similar
calculation on the cluster, a similar amount of memory should be needed.

.. figure:: ../../images/win-task-manager_en.png

.. note::

    With ``top`` and ``htop``, the ``RES`` column is the one you should
    consider. It is the *resident set size* of the process, that is the amount
    of memory it currently occupies.

Checking the memory used on the cluster
---------------------------------------

With the id of a completed job, use ``seff <jobid>`` or ``sacct -j <jobid> -o
JobID,JobName,MaxRSS``.

- ``Memory Utilized``: the maximum amount of memory used during the job.
- ``MaxRSS``: the same thing, where RSS stands for *resident set size*.
- See our `documentation
  <https://docs.alliancecan.ca/wiki/Running_jobs#Completed_jobs>`_.

Exercise
''''''''

#. List your recent jobs with ``sacct -X -o JobID,JobName``.
#. Try ``seff <jobid>`` for the job that compared sorting algorithms. How much
   memory was used?
#. Check again how much memory was used by that job with
   ``sacct -j <jobid> -o JobID,JobName,MaxRSS``.

Estimating the memory required for a larger calculation
-------------------------------------------------------

Several factors influence memory usage:

- Number of files to process **simultaneously**
- Input data file size

  - Data compressed in storage will take up more memory after decompression.

- Program parameters, including those that control the algorithm
- Data subsequently generated in memory

By varying these parameters, it is possible to empirically verify the memory
usage trend of a program in preparation for a larger calculation. Some things to
consider:

- Memory measurements must be done one calculation at a time.
- For the measure to be reliable, maximum memory usage should be sustained for
  around 30 seconds.
- Otherwise, `real-time job monitoring <../monitoring/compute-nodes.html>`_ must
  be performed.

Exercise
''''''''

**Objective:** cause an out-of-memory situation in a job.

#. Go to the exercise directory with ``cd ~/cq-formation-cip201-main/lab/sort``.
#. If need be, (re)compile the ``bubble`` and ``quick`` programs with the
   ``make`` command.
#. Edit ``test.sh`` to request ``--mem=400M`` (only 400 mebibytes).
#. Submit ``test.sh`` as a job.
#. Once the job has completed:

   #. Check the error message in the output file ``slurm-<jobid>.out``.
   #. Check the ``OUT_OF_MEMORY`` job state with ``sacct -j <jobid>``.
