Workshop material using Sphinx
==============================

`Français <../fr/index.html>`_

Welcome to this example of workshop material made with
`Sphinx <https://www.sphinx-doc.org/en/master/index.html>`_.

Here are some examples of special boxes:

.. important::

    The :code:`*.rst` files do not contain Markdown code, but
    `reStructuredText <https://www.sphinx-doc.org/en/master/usage/restructuredtext/>`_.
    There are some advantages, like including the contents of another
    :code:`*.rst` file, which avoids duplicating some written information.

.. note::

    - We

        - can
        - make

    - nested

        - lists.

    #. Quite
    #. useful!

See the documentation about the
`reStructuredText basics <https://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html>`_.

Finally, the :code:`index.rst` files contain the necessary
informations to build the table of contents in the left pane.

.. toctree::
    :maxdepth: 2
    :titlesonly:
    :hidden:

    01-subjectA
    02-subjectB
    extra/index

.. toctree::
    :caption: Help
    :maxdepth: 2
    :titlesonly:
    :hidden:

    references

.. toctree::
    :caption: External links
    :hidden:

    Alliance Technical Documentation <https://docs.alliancecan.ca/wiki/Technical_documentation/en>
    Calcul Québec Training <https://www.calculquebec.ca/en/academic-research-services/training/>
    CCDB Portal <https://ccdb.alliancecan.ca/>
