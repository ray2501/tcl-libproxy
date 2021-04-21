tcl-libproxy
=====

This package is Tcl bindings for libproxy.

[Libproxy](https://libproxy.github.io/libproxy/)
is a library that provides automatic proxy configuration management.
It is used to query the system for potential proxies to use in order to
reach a given URL.


UNIX BUILD
=====

This package requires libproxy development files.
For example, you can use below command to install development files in
opensSUSE:

    sudo zypper in libproxy-devel

Building under most UNIX systems is easy, just run the configure script
and then run make. For more information about the build process, see
the tcl/unix/README file in the Tcl src dist. The following minimal
example will install the extension in the /opt/tcl directory.

    $ cd tcl-libproxy
    $ ./configure --prefix=/opt/tcl
    $ make
    $ make install

If you need setup directory containing tcl configuration (tclConfig.sh),
below is an example:

    $ cd tcl-libproxy
    $ ./configure --with-tcl=/opt/activetcl/lib
    $ make
    $ make install


Implement commands
=====

::libproxy::proxies


Example
=====

    package require libproxy
    set result [::libproxy::proxies https://www.google.com/]
    foreach r $result {
        puts $r
    }

