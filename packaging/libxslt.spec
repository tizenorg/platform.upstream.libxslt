Name:           libxslt
%define soname  %{name}
Version:        1.1.26
Release:        0
Summary:        XSL Transformation Library
License:        MIT and GPL-2.0+
Group:          System/Libraries
#
Url:            http://xmlsoft.org/XSLT/
Source:         %{name}-%{version}.tar.bz2
Source2:        baselibs.conf
Source3:        xslt-config.1.gz
BuildRequires:  libgcrypt-devel
BuildRequires:  libgpg-error-devel
BuildRequires:  libtool
BuildRequires:  libxml2-devel
BuildRequires:  pkg-config

%description
This C library allows you to transform XML files into other XML files
(or HTML, text, and more) using the standard XSLT stylesheet
transformation mechanism.

It is based on libxml (version 2) for XML parsing, tree manipulation,
and XPath support. It is written in plain C, making as few assumptions
as possible and sticks closely to ANSI C/POSIX for easy embedding.
Although not primarily designed with performance in mind, libxslt seems
to be a relatively fast processor. It also includes full support for
the EXSLT set of extension functions as well as some common extensions
present in other XSLT engines.


%package devel
Summary:        Include Files and Libraries mandatory for Development
License:        LGPL-2.1+
Group:          Development/Libraries/C and C++
Requires:       %{name}-tools = %version
Requires:       %{soname} = %{version}
Requires:       glibc-devel
Requires:       libgcrypt-devel
Requires:       libgpg-error-devel
#libxml is automatically required with pkgconfig

%description devel
This package contains all necessary include files and libraries needed
to develop applications that require these.

%package tools
Summary:        Extended Stylesheet Language (XSL) Transformation utilities
License:        MIT and GPL-2.0+
Group:          Development/Tools
Provides:       xsltproc = %version-%release

%description tools
This package contains xsltproc, a command line interface to the XSLT engine.

%prep
%setup -q

%build
autoreconf --force --install
%configure --disable-static --with-pic --without-python
make %{?_smp_mflags}

%check
%if ! 0%{?qemu_user_space_build}
make check
%endif

%install
%make_install

# Unwanted doc stuff
rm -fr %{buildroot}%{_datadir}/doc

# the manual page is required
install -ma=r '-t%{buildroot}%{_mandir}/man1' '%{SOURCE3}'


%post -n %{soname} -p /sbin/ldconfig

%postun -n %{soname} -p /sbin/ldconfig

%files -n %{soname}
%defattr(-, root, root)
%{_libdir}/lib*.so.*

%files devel
%defattr(-, root, root)
%{_libdir}/lib*.so
%{_libdir}/*.sh
%{_libdir}/pkgconfig/*.pc
%{_includedir}/*
%{_datadir}/aclocal/*
%{_bindir}/xslt-config
%doc %{_mandir}/man1/xslt-config.*
%doc %{_mandir}/man3/*

%files tools
%defattr(-,root,root)
%{_bindir}/xsltproc
%doc %{_mandir}/man1/xsltproc.*

%changelog
