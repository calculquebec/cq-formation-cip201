Commands
========

`Français <../../fr/slurm/commands.html>`_

Submitting jobs
---------------

There are several options for `submitting a computational job
<https://docs.alliancecan.ca/wiki/Running_jobs>`__, but the first method below
is preferred to avoid waiting on the command line and to avoid wasting
computation time.

#. Via a job script:

   .. code-block:: bash

      sbatch [<options>] script.sh

#. Via an interactive job on the compute node:

   .. code-block:: bash

      salloc <options>
      ./application arg1 arg2 ...
      exit

.. warning::

    In interactive mode, jobs are limited to a maximum of three (3) to eight
    (8) hours, depending on the cluster.

Main options
''''''''''''

- ``--account=<account>``:
  `compute account <https://slurm.schedmd.com/sbatch.html#OPT_account>`__.

  - On the national clusters, the accounts have the form ``def-*``,
    ``rrg-*``, ``rpp-*`` or ``ctb-*``.
  - For the workshop, the account will be ``def-sponsor00``.

- ``--job-name=<name>``:
  `name of your choice <https://slurm.schedmd.com/sbatch.html#OPT_job-name>`__
  for the job. This is very useful to differentiate your different types of
  jobs.

- ``--time=D-HH:MM`` or ``--time=HH:MM:SS``:
  `limit on the total run time
  <https://slurm.schedmd.com/sbatch.html#OPT_time>`__ of the job.

  - You can specify days (``D``), hours (``HH``), minutes (``MM``) and seconds
    (``SS``).
  - By default: ``1:0:0``, or one hour.

- ``--mem=<size>``, memory required `per node
  <https://slurm.schedmd.com/sbatch.html#OPT_mem>`__.

  - Units:

    - ``M`` (mebibyte = 1024K, this is the default unit)
    - ``G`` (gibibyte = 1024M)

  - By default: ``256M``

Monitoring jobs
---------------

- ``squeue``: `to display jobs <https://slurm.schedmd.com/squeue.html>`__
  currently managed by Slurm.

  - ``-t pending``: only display pending jobs.
  - ``-t running``: only display active jobs.
  - ``-u $USER``: only display your jobs.

- ``sq``: alias of ``squeue -u $USER``.
- ``scontrol show job <jobid>``: display the properties of a job managed by
  Slurm.
- ``seff <jobid>``: summary of resources used.
- ``sacct``: `the details of jobs <https://slurm.schedmd.com/sacct.html>`__
  completed since midnight.

  - ``-j,--jobs=<jobid...>``: display the information for one or more specific
    jobs.
  - ``-o,--format=<field...>``: only display specific fields of information.
  - ``-X,--allocations``: only display statistics relevant to the job
    allocation itself, not job steps.
  - ``-S,--starttime=<YYYY-MM-DD>``: search jobs from a precise date.
  - ``-E,--endtime=<YYYY-MM-DD>``: search jobs until a precise date.
