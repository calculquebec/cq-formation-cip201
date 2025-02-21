Temps
=====

`English <../en/resources/time.html>`_

Pourquoi se fixer une limite de temps?
--------------------------------------

- Pour des fins de maintenance, chaque grappe nationale impose une durée
  maximale des tâches, typiquement de sept (7) jours, sauf exception.
- Cependant, plus les tâches sont longues, plus elles s'exposent à une
  défaillance matérielle.

  - `Les points de contrôle <https://docs.alliancecan.ca/wiki/Points_de_contr%C3%B4le/fr>`_
    permettent de s'en protéger et même de découper le travail en plusieurs
    tâches de calcul successives.

- En fait, la plupart des tâches se terminent en quelques heures.
- Par conséquent,
  `la politique d'ordonnancement <https://docs.alliancecan.ca/wiki/Job_scheduling_policies/fr#Pourcentages_des_n%C5%93uds_disponibles>`_
  implique davantage de noeuds disponibles pour les tâches courtes.

.. image:: ../../images/partitions_fr.svg

- Selon le nombre de noeuds disponibles acceptant la durée de votre tâche,
  cette dernière attendra en file plus ou moins longtemps.

En somme, **vous avez tout intérêt à demander que le temps de calcul
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
  ``sacct -j <jobid> --format=JobID,JobName,Elapsed``.

  - ``Elapsed`` : temps écoulé entre le début et la fin de la tâche.
  - Voir la
    `documentation ici <https://docs.alliancecan.ca/wiki/Running_jobs/fr#T%C3%A2ches_termin%C3%A9es>`_.

- Si on ne connaît pas le numéro de tâche, on peut lister nos dernières tâches
  avec ``sacct -X``.

  - Pour démarrer la recherche à partir d'une
    `date antérieure <https://slurm.schedmd.com/sacct.html#OPT_starttime>`_
    à aujoud'hui : ``-S AAAA-MM-JJ``
  - Pour limiter la recherche jusqu'à une
    `certaine date <https://slurm.schedmd.com/sacct.html#OPT_endtime>`_
    : ``-E AAAA-MM-JJ``

Exercice
''''''''

#. Afficher la liste des dernières tâches avec ``sacct -X``.
#. Essayer la commande ``seff <jobid>`` pour l'une d'entre elles afin de
   voir le temps écoulé mesuré.
#. Voir le temps écoulé avec la commande
   ``sacct -j <jobid> --format=JobID,JobName,Elapsed``.
