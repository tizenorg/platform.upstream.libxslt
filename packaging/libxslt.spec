%define run_tests 0
%if %{run_tests}
    # check is defined off at .rpmmacros file.
    %define check %%check
%endif

Name:           libxslt
Version:        1.1.29
Release:        0
Summary:        XSL Transformation Library
License:        MIT
Group:          System/Libraries
Url:            http://xmlsoft.org/XSLT/
Source:         %{name}-%{version}.tar.bz2
Source1001:     libxslt.manifest
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
Group:          System/Libraries
Requires:       %{name}-tools = %version
Requires:       libxslt = %{version}
Requires:       glibc-devel
Requires:       libgcrypt-devel
Requires:       libgpg-error-devel
#libxml is automatically required with pkgconfig

%description devel
This package contains all necessary include files and libraries needed
to develop applications that require these.

%package tools
Summary:        Extended Stylesheet Language (XSL) Transformation utilities
Group:          Development/Tools
Provides:       xsltproc = %version-%release

%description tools
This package contains xsltproc, a command line interface to the XSLT engine.

%prep
%setup -q
cp %{SOURCE1001} .

%build
%configure --disable-static --with-pic --without-python
%__make %{?_smp_mflags}

%check
%if %{run_tests}
    %__make check || exit 0
%endif

%install
%make_install
%remove_docs

%post -n libxslt -p /sbin/ldconfig

%postun -n libxslt -p /sbin/ldconfig

%files -n libxslt
%manifest %{name}.manifest
%defattr(-, root, root)
%license COPYING Copyright
%{_libdir}/lib*.so.*

%files devel
%manifest %{name}.manifest
%defattr(-, root, root)
%{_libdir}/lib*.so
%{_libdir}/*.sh
%{_libdir}/pkgconfig/*.pc
%{_includedir}/*
%{_datadir}/aclocal/*
%{_bindir}/xslt-config

%files tools
%manifest %{name}.manifest
%defattr(-,root,root)
%{_bindir}/xsltproc
