Commandes
=========

`English <../en/02-mem.html>`_

Soumission de tâches
--------------------

Il existe plusieurs possibilités pour soumettre une tâche de calcul, mais la
première méthode ci-dessous est à privilégier afin d'éviter d'attendre sur la
ligne de commandes et pour éviter le gaspillage de temps de calcul.

1. Via un script de tâche :

.. code:: bash

    sbatch [<options>] script.sh

2. Via une commande bloquante :

.. code:: bash

    srun <options> ./application arg1 arg2 ...

3. Via une tâche interactive sur le noeud de calcul :

.. code:: bash

    salloc <options>
    ./application arg1 arg2 ...
    exit

.. note::

    En mode interactif, les tâches sont limitées à un maximum de trois (3) à
    huit (8) heures, selon la grappe.

Principales options
^^^^^^^^^^^^^^^^^^^

* :code:`--account=<compte>` :
  `compte de calcul <https://slurm.schedmd.com/sbatch.html#OPT_account>`_.

  * Sur les grappes nationales, les comptes ont la forme :code:`def-*`,
    :code:`rrg-*`, :code:`rpp-*` ou :code:`ctb-*`.
  * Pour l'atelier, le compte sera :code:`def-sponsor00`.

* :code:`--time=J-HH:MM` ou :code:`--time=HH:MM:SS` :
  `limite de temps <https://slurm.schedmd.com/sbatch.html#OPT_time>`_
  pour l'exécution de la tâche de calcul.

  * On peut spécifier des jours (:code:`J`), des heures (:code:`HH`), des
    minutes (:code:`MM`) et des secondes (:code:`SS`).
  * Par défaut : :code:`1:0:0`, soit une heure.

* :code:`--mem=<quantité>`, quantité de mémoire
  `par noeud de calcul <https://slurm.schedmd.com/sbatch.html#OPT_mem>`_.

  * Unités :

    * :code:`M` (mébioctet = 1024K, unité par défaut)
    * :code:`G` (gibioctet = 1024M)

  * Par défaut : :code:`256M`

Suivi de tâches
---------------

* :code:`squeue` : `afficher les tâches <https://slurm.schedmd.com/squeue.html>`_
  actuellement gérées par slurm.

  * :code:`-t pending` : afficher les tâches en attente.
  * :code:`-t running` : afficher les tâches en cours.
  * :code:`-u $USER` : afficher uniquement vos tâches.

* :code:`sq` : alias de :code:`squeue -u $USER`.
* :code:`scontrol show job -dd <jobid>` : afficher le détail d'une tâche gérée
  par Slurm.
* :code:`seff <jobid>` : résumé des ressources utilisées.
* :code:`sacct` : `détail des tâches <https://slurm.schedmd.com/sacct.html>`_
  complétées depuis minuit.
