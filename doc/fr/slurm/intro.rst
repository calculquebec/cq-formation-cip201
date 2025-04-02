Généralités
===========

`English <../../en/slurm/intro.html>`_

Rappel de l'ordonnancement des tâches
-------------------------------------

* Le lancement de tâches de calcul n'est pas immédiat comme sur un ordinateur
  local.

  * Les tâches sont mises en file d'attente et sont constamment triées par
    ordre de priorité en attendant que les ressources demandées soient
    disponibles.
  * Tout cela est dû à la grande demande pour les ressources de calcul.

* Selon la priorité de chaque tâche et selon les ressources qui se libèrent,
  l'ordonnanceur Slurm joue à un genre de
  `Tetris <https://fr.wikipedia.org/wiki/Tetris>`__ où la largeur des blocs
  correspond à une quantité de ressource demandée et où la hauteur d'un bloc
  est le temps demandé pour la tâche.

  * Ce qui est particulier, c'est que la durée réelle du calcul est
    généralement plus courte que le temps demandé et que certains blocs de
    calcul parallèle peuvent être scindés en plusieurs morceaux.

.. figure:: ../../images/scheduling-tetris_fr.svg

En tant qu'utilisatrice ou utilisateur des grappes de calcul, votre travail
consiste à soumettre des tâches au moyen de commandes, d'options et de
scripts de tâches.
Ces tâches seront éventuellement exécutées automatiquement.
