Running jobs: resources and monitoring
======================================

`Français <../fr/index.html>`_

This intermediate-level workshop (CIP201) is the continuation of *First steps on
compute clusters* (CIP101). We explore in details certain key aspects of
high-performance computing.

..
    Cet atelier de niveau intermédiaire (CIP201) est la suite de *Premiers pas
    sur les grappes de calcul* (CIP101). Nous y explorons plus en profondeur
    certains aspects clés du calcul informatique de pointe.

The workshop begins with a review of the **task scheduler**. :doc:`What is it
for <slurm/intro>`? What are the main :doc:`commands <slurm/commands>` to
submit, show, cancel and analyse compute jobs? How do we write the :doc:`job
scripts <slurm/scripts>` that drive these computations? In addition to
refreshing your knowledge from the previous workshop, this section will serve as
a reference during the exercises.

..
    L’atelier débute par un rappel sur **l’ordonnanceur de tâches**. :doc:`À
    quoi sert-il ? <slurm/intro>` Quelles sont les principales :doc:`commandes
    <slurm/commands>` pour soumettre, afficher, annuler et analyser les tâches
    de calcul ? Comment rédige-t-on les :doc:`scripts de tâches <slurm/scripts>`
    qui exécutent ces calculs ? En plus de rafraîchir vos connaissances acquises
    au cours de l’atelier précédent, cette section vous servira de référence
    pendant les exercices.

The next section introduces the two **types of compute jobs**. :doc:`Serial jobs
<task-types/serial>` are the simplest. :doc:`Parallel jobs
<task-types/parallel>` deserve a more in-depth presentation, including the
difference between multi-threaded and MPI programs. Data parallelism is briefly
discussed and is the topic of a subsequent workshop, *Data parallelism on the
clusters* (CIP202).

..
    La section suivante présente les deux **types de tâches de calcul**. Les
    :doc:`tâches sérielles <task-types/serial>` sont les plus simples. Les
    :doc:`tâches parallèles <task-types/parallel>`, pour leur part, méritent une
    discussion plus approfondie, incluant la différence entre les programmes
    parallèles multi-fils et MPI. Le parallélisme de données est mentionné
    brièvement et fait l’objet d’un atelier subséquent, *Parallélisme de données
    sur les grappes* (CIP202).

**Estimating the resources required** for a compute job can be challenging! This
section covers compute :doc:`time <resources/time>`, :doc:`memory
<resources/memory>`, and number of :doc:`CPU cores <resources/cpu>`. How do we
determine the minimal amounts required and the optimal quantities? What is the
impact of requested resources on your jobs’ priority? What should you do if the
available resources seem insufficient? GPU resources will be discussed in a
separate workshop (to be announced).

..
    **Estimer les ressources requises** pour une tâche de calcul peut être un
    défi ! Cette section discute du :doc:`temps <resources/time>` de calcul, de
    la :doc:`mémoire <resources/memory>` et du nombre de :doc:`cœurs CPU
    <resources/cpu>`. Comment déterminer les quantités minimales nécessaires et
    les quantités optimales? Quel est l’impact des ressources demandées sur la
    priorité de vos tâches ? Que faire si les ressources disponibles ne semblent
    pas suffisantes ? Les ressources GPU sont couvertes dans un atelier séparé
    (à venir).

**Monitoring** ensures that a job is making proper use of the resources it was
allocated. To monitor a job, one must :doc:`connect to the compute nodes
<monitoring/compute-nodes>` to examine the running programs. To debug a job that
is not running correctly or to optimise a resource request, :doc:`interactive
sessions <monitoring/interactive-sessions>` are particularly useful. Finally,
some clusters offer a :doc:`user portal <monitoring/user-portal>` that
facilitates job monitoring.

..
    Le **suivi des tâches** permet de s’assurer qu’une tâche utilise
    correctement les ressources qui lui ont été allouées. Pour se faire, il est
    nécessaire de :doc:`se connecter aux nœuds de calcul
    <monitoring/compute-nodes>` pour examiner les programmes qui s’y exécutent.
    Pour déboguer une tâche qui ne s’exécute pas correctement ou pour optimiser
    les ressources demandées, les :doc:`sessions interactives
    <monitoring/interactive-sessions>` sont particulièrement indiquées.
    Finalement, certaines grappes offrent un :doc:`portail des utilisateurs
    <monitoring/user-portal>` qui facilite le suivi des tâches.

.. note::

    This workshop was designed for guided sessions with a Calcul Québec
    instructor on our cloud computing platform. The files necessary for the
    exercices are in your home directory on the platform.

    ..
        Cet atelier a été conçu pour être guidé par un formateur ou une
        formatrice de Calcul Québec sur notre plateforme infonuagique. Les
        fichiers nécessaires pour les exercices sont dans votre répertoire
        personnel sur la plateforme.

    If you follow this workshop on your own, you can download the `the
    necessary files <https://github.com/calculquebec/cq-formation-cip201>`_ and
    do the exercises on any Calcul Québec or Digital Research Alliance of Canada
    cluster. Your jobs’ wait time, however, will be longer than on the cloud
    computing platform.

    ..
        Si vous suivez cet atelier par vous-même, vous pouvez télécharger `les
        fichiers nécessaires
        <https://github.com/calculquebec/cq-formation-cip201>`_ et réaliser les
        exercices sur n’importe quelle grappe de Calcul Québec ou de l’Alliance
        de recherche numérique du Canada. Le temps d’attente pour l’exécution
        des tâches sera toutefois plus long que sur la plateforme infonuagique.

.. toctree::
    :caption: The job scheduler
    :maxdepth: 2
    :titlesonly:
    :hidden:

    slurm/intro
    slurm/commands
    slurm/scripts

.. toctree::
    :caption: Compute job types
    :maxdepth: 2
    :titlesonly:
    :hidden:

    task-types/serial
    task-types/parallel

.. toctree::
    :caption: Estimating required resources
    :maxdepth: 2
    :titlesonly:
    :hidden:

    resources/time
    resources/memory
    resources/cpu

.. toctree::
    :caption: Monitoring jobs
    :maxdepth: 2
    :titlesonly:
    :hidden:

    monitoring/compute-nodes
    monitoring/interactive-sessions
    monitoring/user-portal

.. toctree::
    :caption: External links
    :hidden:

    Alliance Technical Documentation <https://docs.alliancecan.ca/wiki/Technical_documentation/en>
    Calcul Québec Training <https://www.calculquebec.ca/en/academic-research-services/training/>
