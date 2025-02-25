Se connecter aux nœuds de calcul
================================

`English <../en/monitoring/compute-nodes.html>`_

Bien que très utiles, les outils ``seff`` et ``sacct`` ne peuvent pas décrire
tout le comportement d'un programme, à savoir son utilisation CPU sur chaque
cœur réservé, s'il y a trop de fils d'exécution ou bien s'il y a soudainement
une surutilisation de la mémoire qui n'est pas mesurée par Slurm.

Comme on l'a déjà vu, c'est possible d'utiliser ``top`` et ``htop`` via des
tâches interactives, mais **les grappes nationales permettent aussi que vous
vous connectiez par SSH aux nœuds où vous avez une tâche en cours**. Voici
les étapes à suivre pour ce faire :

#. S'assurer d'être connecté sur un nœud de connexion de la grappe de calcul.
#. Identifier le ou les nœuds où se trouve la tâche en cours.

   - Obtenir le nom du nœud avec ``sq`` ou ``squeue -t running -u $USER``.
   - Si le champ ``NODELIST`` est trop étroit pour obtenir la liste complète
     des nœuds, la liste complète se trouve dans la sortie de la commande
     ``scontrol show job <jobid> | grep 'NodeList'``.

#. Se connecter à un nœud à la fois. Par exemple : ``ssh compute-node1``.

Cette méthode d'accès est pratique pour :

- les tâches déjà démarrées;
- les tâches parallèles multi-nœuds où il importe de vérifier le comportement
  sur chaque nœud impliqué.

.. warning::

    Sur un nœud de calcul, s'il ne vous reste plus aucune tâche en cours, la
    connexion SSH entre le nœud de connexion et le nœud de calcul sera
    interrompue. Votre invite de commande sera automatiquement de retour sur le
    nœud de connexion.

Exercice en groupe
------------------

**Objectif**

- Savoir trouver la liste des nœuds d'une tâche en cours d'exécution.

**Instructions**

#. Soumettez une courte tâche : ``sbatch --wrap='sleep 120'``.
#. Voyez la liste de nœuds dans la sortie de : ``squeue -t running -u $USER``.
#. Obtenez la liste de nœuds avec la commande :
   ``scontrol show job <jobid> | grep 'NodeList'``.
