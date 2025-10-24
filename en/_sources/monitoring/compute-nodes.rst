Connecting to compute nodes
===========================

`Français <../../fr/monitoring/compute-nodes.html>`_

Although very useful, ``seff`` and ``sacct`` cannot fully describe a program’s
behaviour, such as its CPU usage on each allocated CPU core, whether there are
too many threads of execution, or if there is a memory overuse that has not been
measured by Slurm.

As we have already seen, ``top`` and ``htop`` can be used in interactive jobs,
but **you can also connect to the nodes where you have running jobs**. To do so,
follow these steps:

#. Ensure you are connected to a cluster login node.
#. Get the id of the job you are interested in with ``sq`` or ``squeue -t
   running -u $USER``.
#. Connect to the job with ``srun --jobid=<id> --pty $SHELL``.

For multi-node jobs, you can connect to a specific node with ``srun --jobid=<id>
--nodelist=<node> --pty $SHELL``. The nodes allocated to a job are shown in the
output of ``sq``. If the ``NODELIST`` field is too narrow to see the full list,
use ``squeue -j <id> -o %.40N``, where 40 is the number of characters to use for
the field width.

You can also use SSH to connect to a node allocated to one of your jobs. For
instance: ``ssh compute-node1``.

This is a practical method for:

- Jobs that have already started;
- Multi-node parallel jobs where checking the program’s behaviour on all
  allocated nodes is important.

.. warning::

    If you are connected to a compute node where you no longer have any running
    jobs, your connection between the login node and the compute node will be
    terminated. Your command prompt will automatically go back to the login
    node.

Group exercise
--------------

**Objective**

- Understand how to get a list of the compute nodes allocated to a running job.

**Instructions**

#. Submit a short job: ``sbatch --wrap='sleep 120'``.
#. Check the id and node list with ``squeue -t running -u $USER``.
#. Also try:  ``squeue -j <id> -o %.40N``.
