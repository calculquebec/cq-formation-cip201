User portals
============

`Français <../../fr/monitoring/user-portal.html>`_

Some clusters offer a portal to monitor your current jobs and even your
recently completed jobs. Here they are:

- **Béluga** : https://portail.beluga.calculquebec.ca
- **Narval** : https://portail.narval.calculquebec.ca
- **Niagara** : https://my.scinet.utoronto.ca

In all cases, you must log in with your `CCDB <https://ccdb.alliancecan.ca>`__
portal credentials.

Narval job statistics
---------------------

In the Narval portal (or the Béluga portal), a table listing your most recent
jobs can be found on the `Job stats
<https://portail.narval.calculquebec.ca/secure/jobstats/>`__ page, in the
*Your jobs* section.

.. figure:: ../../images/portal-tasks-table-narval_en.png

Clicking on one of the job identifiers takes you to a page displaying all
`available information about the job
<https://docs.alliancecan.ca/wiki/Portail#Page_d'une_t%C3%A2che_CPU>`__
(at the time of writing, that wiki page is only available in French):

- The loaded modules, if any.
- If applicable, one or more diagnostic messages giving suggestions for
  improving the job script.
- A button to view the job script.
- A button to view the job submission command.
- The job history.
- A summary table of the requested resources.
- A complete analysis of resources used (if measured) over time:

  - CPU usage. In the figure below, 8 of the 12 cores requested for the job are
    100 % utilized.

    .. figure:: ../../images/portal-cpu-core-usage_en.png

  - Memory usage.
  - Number of processes and threads. In the figure below, we see four (4)
    processes each using two (2) ``gmx`` threads, so 8 running threads.

    .. figure:: ../../images/portal-processes-and-threads.png

  - The network file system usage.
  - The compute node’s shared resources:

    - Ethernet and Infiniband bandwidth.
    - Local storage usage (number of operations, bandwidth, total usage).
    - Electrical power used.

For more images and information, see the `documentation section here
<https://docs.alliancecan.ca/wiki/Portail#Statistiques_des_t%C3%A2ches>`__
(at the time of writing, that wiki page is only available in French).

Niagara job statistics
----------------------

In the Niagara portal, a table listing your latest jobs can be found on the
`Jobs -> Niagara <https://my.scinet.utoronto.ca/jobs/niagara>`__ page.

.. figure:: ../../images/portal-tasks-table-niagara_en.png

Clicking on one of the job identifiers takes you to a page displaying all
available information about the job:

- The job history.
- A complete analysis of resources used (if measured) over time:

  - Average CPU utilization per node. In the figure below, each colored dot
    corresponds to one of the 14 nodes reserved for the job.

    .. figure:: ../../images/portal-niagara-node-usage_en.png

  - Available memory.
  - Data read throughput.
  - Data write throughput. In the figure below, we can see write operations at
    regular intervals. These are possibly `checkpoints
    <https://docs.alliancecan.ca/wiki/Points_de_contr%C3%B4le/en>`__.

    .. figure:: ../../images/portal-niagara-write-bw_en.png

  - File operations.
  - etc.

- The job script.
- The environment variables of the running job.
