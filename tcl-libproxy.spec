%{!?directory:%define directory /usr}

%define buildroot %{_tmppath}/%{name}
%define packagename libproxy

Name:          tcl-libproxy
Summary:       Tcl bindings for libproxy
Version:       0.1
Release:       0
License:       MIT
Group:         Development/Libraries/Tcl
Source:        %{name}-%{version}.tar.gz
URL:           https://github.com/ray2501/tcl-libproxy
BuildRequires: autoconf
BuildRequires: make
BuildRequires: tcl-devel >= 8.6
BuildRequires: libproxy-devel
Requires:      tcl >= 8.6
BuildRoot:     %{buildroot}

%description
This package is Tcl bindings for libproxy.

Libproxy is a library that provides automatic proxy configuration
management. It is used to query the system for potential proxies to
use in order to reach a given URL.

%prep
%setup -q -n %{name}-%{version}

%build
./configure \
	--prefix=%{directory} \
	--exec-prefix=%{directory} \
	--libdir=%{directory}/%{_lib}
make 

%install
make DESTDIR=%{buildroot} pkglibdir=%{tcl_archdir}/%{packagename}%{version} install

%clean
rm -rf %buildroot

%files
%defattr(-,root,root)
%{tcl_archdir}

