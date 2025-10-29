Commandes
=========

`English <../../en/slurm/commands.html>`_

Soumission de tâches
--------------------

Il existe plusieurs possibilités pour `soumettre une tâche de calcul
<https://docs.alliancecan.ca/wiki/Running_jobs/fr>`__, mais la première méthode
ci-dessous est à privilégier afin d'éviter d'attendre sur la ligne de commandes
et pour éviter le gaspillage de temps de calcul.

#. Via un script de tâche :

   .. code-block:: bash

      sbatch [<options>] script.sh

#. Via une tâche interactive sur le nœud de calcul :

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
  `compte de calcul <https://slurm.schedmd.com/sbatch.html#OPT_account>`__.

  - Sur les grappes nationales, les comptes ont la forme ``def-*``,
    ``rrg-*``, ``rpp-*`` ou ``ctb-*``.
  - Pour l'atelier, le compte sera ``def-sponsor00``.

- ``--job-name=<nom>`` :
  `nom au choix <https://slurm.schedmd.com/sbatch.html#OPT_job-name>`__
  de la tâche de calcul. C'est très utile pour différencier vos différents
  types de tâches.

- ``--time=J-HH:MM`` ou ``--time=HH:MM:SS`` :
  `limite de temps <https://slurm.schedmd.com/sbatch.html#OPT_time>`__
  pour l'exécution de la tâche de calcul.

  - On peut spécifier des jours (``J``), des heures (``HH``), des
    minutes (``MM``) et des secondes (``SS``).
  - Par défaut : ``1:0:0``, soit une heure.

- ``--mem=<quantité>``, quantité de mémoire
  `par nœud de calcul <https://slurm.schedmd.com/sbatch.html#OPT_mem>`__.

  - Unités :

    - ``M`` (mébioctet = 1024K, unité par défaut)
    - ``G`` (gibioctet = 1024M)

  - Par défaut : ``256M``

Suivi de tâches
---------------

- ``squeue`` : `afficher les tâches <https://slurm.schedmd.com/squeue.html>`__
  actuellement gérées par Slurm.

  - ``-t pending`` : afficher les tâches en attente.
  - ``-t running`` : afficher les tâches en cours.
  - ``-u $USER`` : afficher uniquement vos tâches.

- ``sq`` : alias de ``squeue -u $USER``.
- ``scontrol show job <jobid>`` : afficher les propriétés d'une tâche gérée
  par Slurm.
- ``seff <jobid>`` : résumé des ressources utilisées.
- ``sacct`` : `détail des tâches <https://slurm.schedmd.com/sacct.html>`__
  complétées depuis minuit.

  - ``-j,--jobs=<jobid...>`` : affiche l’information pour une ou plusieurs tâches
    spécifiques.
  - ``-o,--format=<field...>`` : choisit les informations à afficher.
  - ``-X,--allocations`` : affiche seulement les allocations
    de ressources, pas les étapes de la tâche.
  - ``-S,--starttime=<YYYY-MM-DD>`` : démarre la recherche à une date précise.
  - ``-E,--endtime=<YYYY-MM-DD>`` : termine la recherche à une date précise.
