Sessions interactives
=====================

`English <../../en/monitoring/interactive-sessions.html>`_

Nous avons présenté plusieurs outils pour analyser les tâches de calcul. Les
commandes de l’ordonnanceur ``seff`` et ``sacct`` affichent de l’information sur
les tâches complétées. Pour le suivi des tâches actives, nous avons vu comment
se connecter à un nœud de calcul avec ``ssh`` et y utiliser le gestionnaire de
tâches ``top``.

Les sessions interactives sont un autre outil, particulièrement approprié pour
des séries de courts tests. Par exemple, si vous analysez la scalabilité d’un
programme, vous souhaiterez sans doute répéter une courte tâche avec différents
nombres de cœurs CPU. Plutôt que de soumettre avec ``sbatch`` de multiples
tâches qui ne durent que quelques minutes puis colliger leurs résultats, vous
pouvez démarrer une tâche interactive et y exécuter rapidement tous vos tests.

Démonstration
-------------

**Objectif**

- Analyser la scalabilité d’un programme parallèle dans une tâche interactive.
- Utiliser ``srun`` interactivement pour ajouter des étapes à une tâche.
- Utiliser ``sacct`` dans une tâche active pour obtenir de l’information sur les
  étapes terminées.

1. Démarrer une tâche interactive
'''''''''''''''''''''''''''''''''

.. code-block:: console
    :emphasize-lines: 4

    [alice@narval1 ~]$ cd ~/cq-formation-cip201/lab/pi-multi-threaded
    [alice@narval1 ~]$ make
    make: Nothing to be done for 'default'.
    [alice@narval1 pi-multi-threaded]$ salloc --nodes=1 --exclusive --mem=0 --time=3:00:00
    salloc: Pending job allocation 40716821
    salloc: job 40716821 queued and waiting for resources
    salloc: job 40716821 has been allocated resources
    salloc: Granted job allocation 40716821
    salloc: Waiting for resource configuration
    salloc: Nodes nc30432 are ready for job
    [alice@nc30432 pi-multi-threaded]$

- L’option ``--exclusive`` demande tous les cœurs CPU du nœud de calcul. Cela
  garantit qu’aucune autre tâche ne peut être exécutée sur ce nœud et influencer
  les résultats des tests.
- L’option ``--mem=0`` demande toute la mémoire du nœud et ne devrait être
  utilisée que lorsque l’on demande un nœud complet.

2. Tester le programme en mode sériel
'''''''''''''''''''''''''''''''''''''

.. code-block:: console
    :emphasize-lines: 1,4,10

    [alice@nc30432 pi-multi-threaded]$ srun -J testA -n 1 -c 1 ./pi
    Estimating pi with 10000000000 random points.
    Pi estimate is 3.141590.
    [alice@nc30432 pi-multi-threaded]$ sacct -j 40716821 -o JobID%15,JobName,Elapsed,NCPUs
              JobID    JobName    Elapsed      NCPUS 
    --------------- ---------- ---------- ---------- 
           40716821 interacti+   00:04:01         64 
    40716821.inter+ interacti+   00:04:01         64 
    40716821.extern     extern   00:04:01         64 
         40716821.0      testA   00:03:05          1 

- La commande ``srun`` ajoute une étape à la tâche. Les options utilisées sont :

  - ``-J,--job-name``
  - ``-n,--ntasks``
  - ``-c,--cpus-per-task``

- ``srun`` contrôle les ressources allouées à la nouvelle étape. Ici, nous
  n’utilisons qu’un seul des 64 cœurs alloués à la tâche.
- Lorsqu’une étape est terminée, elle peut être analysée avec ``sacct`` même si
  la tâche est encore active. Les ressources consommées par chaque étape sont
  comptabilisées séparément.

.. note::

    Précédemment, nous avons vu que la commande ``srun`` est nécessaire pour
    lancer des programmes MPI. ``srun`` peut aussi être utilisée avec n’importe
    quel autre programme, sériel ou parallèle, multi-fils ou MPI.

3. Tester différents nombres de cœurs CPU
'''''''''''''''''''''''''''''''''''''''''

.. code-block:: console
    :emphasize-lines: 1,4,7,10,16-19

    [alice@nc30432 pi-multi-threaded]$ srun -J testB -n1 -c2 ./pi
    Estimating pi with 10000000000 random points.
    Pi estimate is 3.141621.
    [alice@nc30432 pi-multi-threaded]$ srun -J testC -n1 -c4 ./pi
    Estimating pi with 10000000000 random points.
    Pi estimate is 3.141631.
    [alice@nc30432 pi-multi-threaded]$ srun -J testD -n1 -c8 ./pi
    Estimating pi with 10000000000 random points.
    Pi estimate is 3.141630.
    [alice@nc30432 pi-multi-threaded]$ sacct -j 40716821 -o JobID%15,JobName,Elapsed,NCPUs
              JobID    JobName    Elapsed      NCPUS 
    --------------- ---------- ---------- ---------- 
           40716821 interacti+   00:07:21         64 
    40716821.inter+ interacti+   00:07:21         64 
    40716821.extern     extern   00:07:21         64 
         40716821.0      testA   00:03:05          1 
         40716821.1      testB   00:01:35          2 
         40716821.2      testC   00:00:46          4 
         40716821.3      testD   00:00:23          8
    [alice@nc30432 pi-multi-threaded]$ exit

4. Calculer l’accélération et l’efficacité
''''''''''''''''''''''''''''''''''''''''''

.. list-table:: Scalabilité de ``pi`` multi-fils
    :header-rows: 1

    * - :math:`\pmb{n}`
      - :math:`\pmb{t}` (s)
      - :math:`\pmb{P}` (1e7 points/s)
      - :math:`\pmb{S}`
      - :math:`\pmb{E}` (%)
    * - 1
      - 185
      - 5,3
      - ---
      - ---
    * - 2
      - 95
      - 10,5
      - 1,95
      - 97
    * - 4
      - 46
      - 21,7
      - 4,0
      - 100
    * - 8
      - 23
      - 43,5
      - 8,0
      - 100

- Nombre de cœurs CPU : :math:`n`
- Temps : :math:`t`
- Performance : :math:`P_n = \text{points} / t`
- Accélération : :math:`S_n = t_\text{sériel} / t_n`
- Efficacité : :math:`E_n = S_n / n`

Remarques
---------

- Chaque test devrait durer au moins 5 minutes afin d’être fiable.
- Chaque test devrait être répété 3 fois afin de s’assurer de la stabilité du
  résultat.
- La même approche peut être utilisée pour analyser la consommation de mémoire
  en fonction du nombre de cœurs CPU. On utiliserait alors ``sacct -j <jobid> -o
  JobID%15,JobName,MaxRSS,NCPUs``.
