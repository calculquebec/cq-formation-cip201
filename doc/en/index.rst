Running jobs: resources and monitoring
======================================

`Français <../fr/index.html>`_

This intermediate-level workshop (CIP201) is the continuation of *First steps on
compute clusters* (CIP101). We explore in details certain key aspects of
high-performance computing.

The workshop begins with a review of the **task scheduler**. :doc:`What is it
for <slurm/intro>`? What are the main :doc:`commands <slurm/commands>` to
submit, show, cancel and analyse compute jobs? How do we write the :doc:`job
scripts <slurm/scripts>` that drive these computations? In addition to
refreshing your knowledge from the previous workshop, this section will serve as
a reference during the exercises.

The next section introduces the two **types of compute jobs**. :doc:`Serial jobs
<task-types/serial>` are the simplest. :doc:`Parallel jobs
<task-types/parallel>` deserve a more in-depth presentation, including the
difference between multi-threaded and MPI programs. Data parallelism is briefly
discussed and is the topic of a subsequent workshop, *Data parallelism on the
clusters* (CIP202).

**Estimating the resources required** for a compute job can be challenging! This
section covers compute :doc:`time <resources/time>`, :doc:`memory
<resources/memory>`, and number of :doc:`CPU cores <resources/cpu>`. How do we
determine the minimal amounts required and the optimal quantities? What is the
impact of requested resources on your jobs’ priority? What should you do if the
available resources seem insufficient? GPU resources will be discussed in a
separate workshop (to be announced).

**Monitoring** ensures that a job is making proper use of the resources it was
allocated. To monitor a job, one must :doc:`connect to the compute nodes
<monitoring/compute-nodes>` to examine the running programs. To debug a job that
is not running correctly or to optimise a resource request, :doc:`interactive
sessions <monitoring/interactive-sessions>` are particularly useful. Finally,
some clusters offer a :doc:`user portal <monitoring/user-portal>` that
facilitates job monitoring.

.. note::

    This workshop was designed for guided sessions with a Calcul Québec
    instructor on our cloud computing platform. The files necessary for the
    exercices are in your home directory on the platform.

    If you follow this workshop on your own, you can download the `the
    necessary files <https://github.com/calculquebec/cq-formation-cip201>`_ and
    do the exercises on any Calcul Québec or Digital Research Alliance of Canada
    cluster. Your jobs’ wait time, however, will be longer than on the cloud
    computing platform.

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
