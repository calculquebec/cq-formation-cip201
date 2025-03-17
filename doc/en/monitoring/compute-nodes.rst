Connecting to compute nodes
===========================

`Français <../../fr/monitoring/compute-nodes.html>`_

Although very useful, ``seff`` and ``sacct`` cannot fully describe a program’s
behaviour, such as its CPU usage on each allocated CPU core, whether there are
too many threads of execution, or if there is a memory overuse that has not been
measured by Slurm.

..
    Bien que très utiles, les outils ``seff`` et ``sacct`` ne peuvent pas décrire
    tout le comportement d'un programme, à savoir son utilisation CPU sur chaque
    cœur réservé, s'il y a trop de fils d'exécution ou bien s'il y a soudainement
    une surutilisation de la mémoire qui n'est pas mesurée par Slurm.

As we have already seen, ``top`` and ``htop`` can be used in interactive jobs,
but **the national clusters also allow you to connect by SSH to the nodes where
you have running jobs**. To do so, follow these steps:

..
    Comme on l'a déjà vu, c'est possible d'utiliser ``top`` et ``htop`` via des
    tâches interactives, mais **les grappes nationales permettent aussi que vous
    vous connectiez par SSH aux nœuds où vous avez une tâche en cours**. Voici
    les étapes à suivre pour ce faire :

#. Ensure you are connected to a cluster login node.
#. Identify the node(s) allocated to your running job.

   - Get the node’s name with ``sq`` or ``squeue -t running -u $USER``.
   - If the ``NODELIST`` field is too narrow to get a full list of the nodes,
     you can also find the full list with ``scontrol show job <jobid> | grep
     'NodeList'``.

#. Connect to one node at a time. For instance: ``ssh compute-node1``.

This is a practical method for:

- Jobs that have already started;
- Multi-node parallel jobs where checking the program’s behaviour on all
  allocated nodes is important.

.. warning::

    If you are connected to a compute node where you no longer have any running
    jobs, the SSH connection between the login and compute nodes will be
    terminated. Your command prompt will automatically go back to the login
    node.

Group exercise
--------------

**Objective**

- Understand how to get a list of the compute nodes allocated to a running job.

**Instructions**

#. Submit a short job: ``sbatch --wrap='sleep 120'``.
#. Check the node list with ``squeue -t running -u $USER``.
#. Check again the full node list with ``scontrol show job <jobid> | grep
   'NodeList'``.
