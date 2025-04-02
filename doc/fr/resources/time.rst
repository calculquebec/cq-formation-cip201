Temps
=====

`English <../../en/resources/time.html>`_

Pourquoi se fixer une limite de temps?
--------------------------------------

- Pour des fins de maintenance, chaque grappe nationale impose une durée
  maximale aux tâches, typiquement de sept (7) jours, sauf exception.
- Cependant, plus les tâches sont longues, plus elles s'exposent à une
  défaillance matérielle.

  - `Les points de contrôle <https://docs.alliancecan.ca/wiki/Points_de_contr%C3%B4le/fr>`_
    permettent de s'en protéger et même de découper le travail en plusieurs
    tâches de calcul successives.

- En fait, la plupart des tâches se terminent en quelques heures.
- Par conséquent,
  `la politique d'ordonnancement <https://docs.alliancecan.ca/wiki/Job_scheduling_policies/fr#Pourcentages_des_n%C5%93uds_disponibles>`_
  rend davantage de nœuds disponibles pour les tâches courtes.

.. figure:: ../../images/partitions_fr.svg

- Selon le nombre de nœuds disponibles acceptant la durée de votre tâche,
  cette dernière attendra dans la file plus ou moins longtemps.

En somme, **vous avez tout intérêt à ne demander que le temps de calcul
nécessaire**, avec bien sûr une certaine marge de sécurité (par exemple,
ajouter 20% sur le temps prévu).

Déterminer le temps de calcul à partir de votre ordinateur
----------------------------------------------------------

Si vous vous basez sur votre expérience avec le logiciel sur votre ordinateur
personnel, il y a différents facteurs à considérer :

#. La vitesse de votre **processeur** : les coeurs CPU de la grappe de calcul
   ne sont pas nécessairement plus rapides que ceux de votre ordinateur.
#. La vitesse de la **mémoire** de votre ordinateur.
#. La vitesse du **stockage** pour la lecture et l'écriture des données.

À problème égal, il vaut mieux **demander initialement à Slurm le double du
temps mesuré localement et ajuster par la suite**.

Obtenir le temps de calcul sur la grappe
----------------------------------------

- Si on connaît le numéro de la tâche terminée, on peut utiliser la commande
  ``seff <jobid>`` ou encore
  ``sacct -j <jobid> -o JobID,JobName,Elapsed``.

  - ``Elapsed`` : temps écoulé entre le début et la fin de la tâche.
  - Voir la
    `documentation ici <https://docs.alliancecan.ca/wiki/Running_jobs/fr#T%C3%A2ches_termin%C3%A9es>`_.

- Si on ne connaît pas le numéro de tâche, on peut lister nos dernières tâches
  avec ``sacct -X``.

  - L’option ``-X,--allocations`` filtre la liste pour n’afficher que les
    allocations de ressources, pas les étapes (que nous verrons dans un chapitre
    subséquent).
  - Pour démarrer la recherche à partir d'une
    `date antérieure <https://slurm.schedmd.com/sacct.html#OPT_starttime>`_
    à aujoud'hui : ``-S <YYYY-MM-DD>`` ou ``--starttime=<YYYY-MM-DD>``.
  - Pour limiter la recherche jusqu'à une
    `certaine date <https://slurm.schedmd.com/sacct.html#OPT_endtime>`_
    : ``-E <YYYY-MM-DD>`` ou ``--endtime=<YYYY-MM-DD>``.

Exercice
''''''''

#. Affichez la liste des dernières tâches avec ``sacct -X``.
#. Essayez la commande ``seff <jobid>`` pour l'une d'entre elles afin de
   voir le temps écoulé mesuré.
#. Voyez le temps écoulé avec la commande
   ``sacct -j <jobid> -o JobID,JobName,Elapsed``.

Estimer le temps requis pour un plus grand calcul
-------------------------------------------------

L'algorithme principal de certains programmes sont d'ordre :

- Linéaire, :math:`O(n)`, ce qui veut dire qu'une quantité **2x** plus élevée
  de données à traiter se traduit en un temps de calcul **2x** plus long.
- Quadratique, :math:`O(n^2)`, donc une dimension :math:`n` **2x** plus grande
  cause un temps **4x** plus long.
- Cubique, :math:`O(n^3)`, donc une dimension :math:`n` **2x** plus grande
  cause un temps **8x** plus long.
- Etc.

Empiriquement, il est possible d'observer la tendance d'un programme traitant
différentes quantités de données. Pour mesurer le temps de chaque exécution,
on peut utiliser l'outil ``time -p`` au début de la ligne de commande. Par
exemple :

.. code-block::

    time -p ./programme argument1 ...

Une fois le programme terminé, ``time`` affiche trois valeurs de temps en
secondes :

- ``real`` : temps réel, **c'est le temps à considérer**.
- ``user`` : temps total de calcul effectif sur les coeurs CPU.
- ``sys`` : temps passé dans les opérations système (accès à un fichier, par
  exemple)

Pour cet atelier, on s'intéressera uniquement au temps ``real``.

Exercice
''''''''

Parmi les
`algorithmes de tri <https://fr.wikipedia.org/wiki/Algorithme_de_tri#Comparaison_des_algorithmes>`_
de :math:`n` valeurs, certains algorithmes plus intuitifs, comme trier des
cartes à jouer, sont d'ordre :math:`O(n^2)`, alors que les plus sophistiqués
sont d'ordre :math:`O(n \log(n))`, et donc beaucoup plus rapides lorsque la
quantité de données augmente.

#. Allez dans le répertoire de l’exercice avec
   ``cd ~/cq-formation-cip201-main/lab/sort``.
#. Compilez les programmes ``bubble`` et ``quick`` avec la commande ``make``.
#. Éditez le fichier ``test.sh`` de sorte à ajouter ``time -p`` au début des
   commmandes ``./bubble`` et ``./quick``.
#. Soumettez une tâche avec le script ``test.sh``.
#. Une fois le calcul terminé, inspectez les temps ``real`` mesurés en fonction
   de l'algorithme de tri et en fonction du nombre d'éléments entre parenthèses.
   Ces résultats se trouvent dans le fichier ``slurm-<jobid>.out``.
