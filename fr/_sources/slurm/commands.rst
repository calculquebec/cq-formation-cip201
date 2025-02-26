Commandes
=========

`English <../en/commands.html>`_

Soumission de tâches
--------------------

Il existe plusieurs possibilités pour soumettre une tâche de calcul, mais la
première méthode ci-dessous est à privilégier afin d'éviter d'attendre sur la
ligne de commandes et pour éviter le gaspillage de temps de calcul.

1. Via un script de tâche :

.. code-block:: bash

    sbatch [<options>] script.sh

2. Via une tâche interactive sur le noeud de calcul :

.. code-block:: bash

    salloc <options>
    ./application arg1 arg2 ...
    exit

.. warning::

    En mode interactif, les tâches sont limitées à un maximum de trois (3) à
    huit (8) heures, selon la grappe.

Principales options
'''''''''''''''''''

- ``--account=<compte>`` :
  `compte de calcul <https://slurm.schedmd.com/sbatch.html#OPT_account>`_.

  - Sur les grappes nationales, les comptes ont la forme ``def-*``,
    ``rrg-*``, ``rpp-*`` ou ``ctb-*``.
  - Pour l'atelier, le compte sera ``def-sponsor00``.

- ``--job-name=<nom>`` :
  `nom au choix <https://slurm.schedmd.com/sbatch.html#OPT_job-name>`_
  de la tâche de calcul. C'est très utile pour différencier vos différents
  types de tâches.

- ``--time=J-HH:MM`` ou ``--time=HH:MM:SS`` :
  `limite de temps <https://slurm.schedmd.com/sbatch.html#OPT_time>`_
  pour l'exécution de la tâche de calcul.

  - On peut spécifier des jours (``J``), des heures (``HH``), des
    minutes (``MM``) et des secondes (``SS``).
  - Par défaut : ``1:0:0``, soit une heure.

- ``--mem=<quantité>``, quantité de mémoire
  `par noeud de calcul <https://slurm.schedmd.com/sbatch.html#OPT_mem>`_.

  - Unités :

    - ``M`` (mébioctet = 1024K, unité par défaut)
    - ``G`` (gibioctet = 1024M)

  - Par défaut : ``256M``

Suivi de tâches
---------------

- ``squeue`` : `afficher les tâches <https://slurm.schedmd.com/squeue.html>`_
  actuellement gérées par slurm.

  - ``-t pending`` : afficher les tâches en attente.
  - ``-t running`` : afficher les tâches en cours.
  - ``-u $USER`` : afficher uniquement vos tâches.

- ``sq`` : alias de ``squeue -u $USER``.
- ``scontrol show job <jobid>`` : afficher le détail d'une tâche gérée
  par Slurm.
- ``seff <jobid>`` : résumé des ressources utilisées.
- ``sacct`` : `détail des tâches <https://slurm.schedmd.com/sacct.html>`_
  complétées depuis minuit.
