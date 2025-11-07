Interactive sessions
====================

`Français <../../fr/monitoring/interactive-sessions.html>`_

We have already presented several tools to analyse compute jobs. Scheduler
commands ``seff`` and ``sacct`` show information about completed jobs. To
monitor running jobs, we have seen how to connect to a compute node with
``ssh``, and there use the ``top`` task manager.

Interactive sessions are yet another tool, which is especially well-suited for
series of short tests. For instance, when analysing a program’s scalability, you
often need to repeat a short job with different numbers of CPU cores. Rather
than submitting multiple minute-length jobs with ``sbatch`` and then collecting
their results, you can start an interactive job and quickly run all your tests
there.

Demonstration
-------------

**Objectives**

- Analyse a parallel program’s scalability in an interactive job.
- Use ``srun`` interactively to add steps to a job.
- Use ``sacct`` in an interactive job to get information about completed steps.

1. Start an interactive job
'''''''''''''''''''''''''''

.. code-block:: console
    :emphasize-lines: 4

    [alice@narval1 ~]$ cd ~/cq-formation-cip201/lab/pi-multi-threaded
    [alice@narval1 ~]$ make
    make: Nothing to be done for 'default'.
    [alice@narval1 pi-multi-threaded]$ salloc --nodes=1 --exclusive --mem=0 --time=3:00:00
    salloc: Pending job allocation 40716821
    salloc: job 40716821 queued and waiting for resources
    salloc: job 40716821 has been allocated resources
    salloc: Granted job allocation 40716821
    salloc: Waiting for resource configuration
    salloc: Nodes nc30432 are ready for job
    [alice@nc30432 pi-multi-threaded]$

- The ``--exclusive`` option requests all CPU cores on the compute node. This
  ensures that no other job can be run on the node and influence the tests’
  results.
- The ``--mem=0`` option requests all the node’s memory and should only be used
  when requesting a full node.

2. Test the program in serial mode
''''''''''''''''''''''''''''''''''

.. code-block:: console
    :emphasize-lines: 1,4,10

    [alice@nc30432 pi-multi-threaded]$ srun -J testA -n 1 -c 1 ./pi
    Estimating pi with 10000000000 random points.
    Pi estimate is 3.141590.
    [alice@nc30432 pi-multi-threaded]$ sacct -j 40716821 -o JobID%15,JobName,Elapsed,NCPUs
              JobID    JobName    Elapsed      NCPUS 
    --------------- ---------- ---------- ---------- 
           40716821 interacti+   00:04:01         64 
    40716821.inter+ interacti+   00:04:01         64 
    40716821.extern     extern   00:04:01         64 
         40716821.0      testA   00:03:05          1 

- The ``srun`` command adds a step to the job. The options used here are:

  - ``-J,--job-name``
  - ``-n,--ntasks``
  - ``-c,--cpus-per-task``

- ``srun`` controls the resources allocated to the new step. Here, we use only
  one of the 64 cores allocated to the job.
- When a step has completed, it can be analysed with ``sacct`` even if the job
  is still running. The resources consumed by each step are accounted for
  separately.

.. note::

    Previously, we saw that the ``srun`` command is necessary to run MPI
    programs. ``srun`` can also be used with any other program, serial or
    parallel, multi-threaded or MPI.

3. Test different numbers of CPU cores
''''''''''''''''''''''''''''''''''''''

.. code-block:: console
    :emphasize-lines: 1,4,7,10,16-19

    [alice@nc30432 pi-multi-threaded]$ srun -J testB -n1 -c2 ./pi
    Estimating pi with 10000000000 random points.
    Pi estimate is 3.141621.
    [alice@nc30432 pi-multi-threaded]$ srun -J testC -n1 -c4 ./pi
    Estimating pi with 10000000000 random points.
    Pi estimate is 3.141631.
    [alice@nc30432 pi-multi-threaded]$ srun -J testD -n1 -c8 ./pi
    Estimating pi with 10000000000 random points.
    Pi estimate is 3.141630.
    [alice@nc30432 pi-multi-threaded]$ sacct -j 40716821 -o JobID%15,JobName,Elapsed,NCPUs
              JobID    JobName    Elapsed      NCPUS 
    --------------- ---------- ---------- ---------- 
           40716821 interacti+   00:07:21         64 
    40716821.inter+ interacti+   00:07:21         64 
    40716821.extern     extern   00:07:21         64 
         40716821.0      testA   00:03:05          1 
         40716821.1      testB   00:01:35          2 
         40716821.2      testC   00:00:46          4 
         40716821.3      testD   00:00:23          8
    [alice@nc30432 pi-multi-threaded]$ exit

4. Calculate speedup and efficiency
'''''''''''''''''''''''''''''''''''

.. list-table:: Multi-threaded ``pi`` scalability
    :header-rows: 1

    * - :math:`\pmb{n}`
      - :math:`\pmb{t}` (s)
      - :math:`\pmb{P}` (1e7 points/s)
      - :math:`\pmb{S}`
      - :math:`\pmb{E}` (%)
    * - 1
      - 185
      - 5,3
      - ---
      - ---
    * - 2
      - 95
      - 10,5
      - 1,95
      - 97
    * - 4
      - 46
      - 21,7
      - 4,0
      - 100
    * - 8
      - 23
      - 43,5
      - 8,0
      - 100

- Number of CPU cores: :math:`n`
- Time : :math:`t`
- Performance : :math:`P_n = \text{points} / t`
- Speedup : :math:`S_n = t_\text{serial} / t_n`
- Efficiency : :math:`E_n = S_n / n`

Remarks
-------

- Each test should last at least 5 minutes to be reliable.
- Each test should be
  repeated 3 times to ensure the result is stable.
- The same approach can be used to analyse memory usage as a function of the
  number of CPU cores. For a multi-threaded program, use ``sacct -j <jobid> -o
  JobID%15,JobName,AveRSS,NCPUs``. For an MPI program, use ``sacct -j <jobid> -o
  JobID%15,JobName,AveRSS,NTasks`` and compute peak memory usage with ``NTasks``
  × ``AveRSS``.
