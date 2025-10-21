Se connecter aux nœuds de calcul
================================

`English <../../en/monitoring/compute-nodes.html>`_

Bien que très utiles, les outils ``seff`` et ``sacct`` ne peuvent pas décrire
tout le comportement d'un programme, à savoir son utilisation CPU sur chaque
cœur réservé, s'il y a trop de fils d'exécution ou bien s'il y a soudainement
une surutilisation de la mémoire qui n'est pas mesurée par Slurm.

Comme on l'a déjà vu, c'est possible d'utiliser ``top`` et ``htop`` via des
tâches interactives, mais **vous pouvez aussi vous connectez aux nœuds où vous
avez une tâche en cours**. Voici les étapes à suivre pour ce faire :

#. S'assurer d'être connecté sur un nœud de connexion de la grappe de calcul.
#. Obtenir l’identifiant de la tâche d’intérêt avec ``sq`` ou ``squeue -t
   running -u $USER``.
#. Se connecter à la tâche avec ``srun --jobid=<id> --pty $SHELL``.

Dans le cas d’une tâche multi-nœuds, vous pouvez vous connecter à un nœud
spécifique avec ``srun --jobid=<id> --nodelist=<node> --pty $SHELL``. Les nœuds
alloués à une tâche sont affichés dans la sortie de ``sq``. Si le champ
``NODELIST`` est trop étroit pour voir la liste complète, utilisez ``squeue -j
<id> -o %.40N``, où 40 est la largeur du champ en nombre de caractères.

Vous pouvez aussi vous connecter par SSH à un nœud alloué à une de vos tâches.
Par exemple : ``ssh compute-node1``.

Cette méthode d'accès est pratique pour :

- les tâches déjà démarrées;
- les tâches parallèles multi-nœuds où il importe de vérifier le comportement
  sur chaque nœud impliqué.

.. warning::

    Sur un nœud de calcul, s'il ne vous reste plus aucune tâche en cours, votre
    connexion entre le nœud de connexion et le nœud de calcul sera interrompue.
    Votre invite de commande sera automatiquement de retour sur le nœud de
    connexion.

Exercice en groupe
------------------

**Objectif**

- Savoir trouver la liste des nœuds d'une tâche en cours d'exécution.

**Instructions**

#. Soumettez une courte tâche : ``sbatch --wrap='sleep 120'``.
#. Voyez l’identifiant et la liste de nœuds dans la sortie de : ``squeue -t
   running -u $USER``.
#. Essayez aussi : ``squeue -j <id> -o %.40N``.
