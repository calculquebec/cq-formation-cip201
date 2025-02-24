Tâches de calcul : ressources et suivi
======================================

`English <../en/index.html>`_

Cet atelier de niveau intermédiaire (CIP201) est la suite de *Premiers pas sur
les grappes de calcul* (CIP101). Nous y explorons plus en profondeur certains
aspects clés du calcul informatique de pointe.

L’atelier débute par un rappel sur **l’ordonnanceur de tâches**. :doc:`À quoi
sert-il ? <slurm/intro>` Quelles sont les principales :doc:`commandes
<slurm/commands>` pour soumettre, afficher, annuler et analyser les tâches de
calcul ? Comment rédige-t-on les :doc:`scripts de tâches <slurm/scripts>` qui
exécutent ces calculs ? En plus de rafraîchir vos connaissances acquises au
cours de l’atelier précédent, cette section vous servira de référence pendant
les exercices.

La section suivante présente les deux **types de tâches de calcul**. Les
:doc:`tâches sérielles <task-types/serial>` sont les plus simples. Les
:doc:`tâches parallèles <task-types/parallel>`, pour leur part, méritent une
discussion plus approfondie, incluant la différence entre les programmes
parallèles multi-fils et MPI. Le parallélisme de données est mentionné
brièvement et fait l’objet d’un atelier subséquent, *Parallélisme de données sur
les grappes* (CIP202).

**Estimer les ressources requises** pour une tâche de calcul peut être un défi !
Cette section discute du :doc:`temps <resources/time>` de calcul, de la
:doc:`mémoire <resources/memory>` et du nombre de :doc:`cœurs CPU
<resources/cpu>`. Comment déterminer les quantités minimales nécessaires et les
quantités optimales? Quel est l’impact des ressources demandées sur la priorité
de vos tâches ? Que faire si les ressources disponibles ne semblent pas
suffisantes ? Les ressources GPU sont couvertes dans un atelier séparé (à
venir).

Le **suivi des tâches** permet de s’assurer qu’une tâche utilise correctement
les ressources qui lui ont été allouées. Pour se faire, il est nécessaire de
:doc:`se connecter aux nœuds de calcul <monitoring/compute-nodes>` pour examiner
les programmes qui s’y exécutent. Pour déboguer une tâche qui ne s’exécute pas
correctement ou pour optimiser les ressources demandées, les :doc:`sessions
interactives <monitoring/interactive-sessions>` sont particulièrement
indiquées. Finalement, certaines grappes offrent un :doc:`portail des
utilisateurs <monitoring/user-portal>` qui facilite le suivi des tâches.

.. note::

    Cet atelier a été conçu pour être guidé par un formateur ou une formatrice
    de Calcul Québec sur notre plateforme infonuagique. Les fichiers nécessaires
    pour les exercices sont dans votre répertoire personnel sur la plateforme.

    Si vous suivez cet atelier par vous-même, vous pouvez télécharger `les
    fichiers nécessaires <https://github.com/calculquebec/cq-formation-cip201>`_
    et réaliser les exercices sur n’importe quelle grappe de Calcul Québec ou de
    l’Alliance de recherche numérique du Canada. Le temps d’attente pour
    l’exécution des tâches sera toutefois plus long que sur la plateforme
    infonuagique.

.. toctree::
    :caption: L’ordonnanceur de tâches
    :maxdepth: 2
    :titlesonly:
    :hidden:

    slurm/intro
    slurm/commands
    slurm/scripts

.. toctree::
    :caption: Types de tâches de calcul
    :maxdepth: 2
    :titlesonly:
    :hidden:

    task-types/serial
    task-types/parallel

.. toctree::
    :caption: Estimer les ressources requises
    :maxdepth: 2
    :titlesonly:
    :hidden:

    resources/time
    resources/memory
    resources/cpu

.. toctree::
    :caption: Suivi des tâches
    :maxdepth: 2
    :titlesonly:
    :hidden:

    monitoring/compute-nodes
    monitoring/interactive-sessions
    monitoring/user-portal

.. toctree::
    :caption: Liens externes
    :hidden:

    Documentation technique de l’Alliance <https://docs.alliancecan.ca/wiki/Technical_documentation/fr>
    Formations de Calcul Québec <https://www.calculquebec.ca/services-aux-chercheurs/formation/>
