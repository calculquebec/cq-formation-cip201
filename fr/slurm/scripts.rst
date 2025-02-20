Scripts de tâches
=================

`English <../en/02-mem.html>`_

Un script de tâche est communément un script Bash destiné à l'ordonnanceur
Slurm. On y retrouve :

1. Le `shebang <https://fr.wikipedia.org/wiki/Shebang>`_ en toute première
   ligne. Par exemple : :code:`#!/bin/bash`.
2. Les options :code:`#SBATCH` en entête pour les besoins de la tâche. Ces
   options seront lues par la commande de soumission de tâche
   `sbatch <https://slurm.schedmd.com/sbatch.html>`_.
3. `Chargement des modules <https://docs.alliancecan.ca/wiki/Utiliser_des_modules>`_
   requis.
4. Les commandes Bash qui seront exécutées automatiquement sur des processeurs
   réservés pour la tâche.

Voir les exemples de la documentation de l'Alliance :

* `Script simple <https://docs.alliancecan.ca/wiki/Running_jobs/fr#Soumettre_des_t%C3%A2ches_avec_sbatch>`_
* `Tâche Python <https://docs.alliancecan.ca/wiki/Python/fr#Cr%C3%A9er_un_environnement_virtuel_dans_vos_t%C3%A2ches>`_
* `Tâche R <https://docs.alliancecan.ca/wiki/R/fr#Interpr%C3%A9teur>`_

Exercice en groupe
------------------

1. Dans le fichier :code:`scripts/simple.sh`, éditer l'entête d'options
   :code:`#SBATCH` selon les instructions qui s'y trouvent :

   a. Demander une quantité de mémoire.
   b. Fixer un temps limite d'exécution.

   Note : l'ordonnanceur déterminera automatiquement le compte de calcul
   :code:`def-sponsor00`.

2. Soumettre ce script de tâche au moyen de la commande :code:`sbatch`.
3. Visualiser l'état de la tâches avec la commande :code:`sq`.
4. Une fois la tâche terminée, voir le contenu du fichier de sortie
   (:code:`slurm-<jobid>.out`) avec :code:`less` (appuyer sur la touche **q**
   pour sortir).
