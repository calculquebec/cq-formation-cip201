Scripts de tâches
=================

`English <../../en/slurm/scripts.html>`_

Un script de tâche est communément un script Bash destiné à l'ordonnanceur
Slurm. On y retrouve :

#. Le `shebang <https://fr.wikipedia.org/wiki/Shebang>`__ en toute première
   ligne. Par exemple : ``#!/bin/bash``.
#. Les options ``#SBATCH`` en entête pour les besoins de la tâche. Ces
   options seront lues par la commande de soumission de tâche
   `sbatch <https://slurm.schedmd.com/sbatch.html>`__.
#. `Chargement des modules <https://docs.alliancecan.ca/wiki/Utiliser_des_modules>`__
   requis.
#. Les commandes Bash qui seront exécutées automatiquement sur des processeurs
   réservés pour la tâche.

Voir les exemples de la documentation de l'Alliance :

- `Script simple <https://docs.alliancecan.ca/wiki/Running_jobs/fr#Soumettre_des_t%C3%A2ches_avec_sbatch>`__
- `Tâche Python <https://docs.alliancecan.ca/wiki/Python/fr#Cr%C3%A9er_un_environnement_virtuel_dans_vos_t%C3%A2ches>`__
- `Tâche R <https://docs.alliancecan.ca/wiki/R/fr#Interpr%C3%A9teur>`__

Exercice en groupe
------------------

#. Connectez-vous à la grappe virtuelle avec ``ssh login1``.
#. Allez dans le répertoire de l’exercice avec
   ``cd ~/cq-formation-cip201-main/lab/script``.
#. Dans le fichier ``simple.sh``, éditez l'entête d'options
   ``#SBATCH`` selon les instructions qui s'y trouvent :

   #. Demandez une quantité de mémoire.
   #. Fixez un temps limite d'exécution.

   Note : l'ordonnanceur déterminera automatiquement le compte de calcul
   ``def-sponsor00``.

#. Soumettez ce script de tâche au moyen de la commande ``sbatch``.
#. Visualisez l'état de la tâches avec la commande ``sq``.
#. Une fois la tâche terminée, voyez le contenu du fichier de sortie
   (``slurm-<jobid>.out``) avec ``less`` (appuyez sur la touche
   :kbd:`q` pour sortir).
