dnl
dnl Software pw3270, desenvolvido com base nos códigos fontes do  C3270  e  X3270
dnl (Paul Mattes Paul.Mattes@usa.net), de emulação de terminal 3270 para acesso a
dnl aplicativos mainframe. Registro no INPI sob o nome G3270.
dnl
dnl Copyright (C) <2008> <Banco do Brasil S.A.>
dnl
dnl Este programa é software livre. Você pode redistribuí-lo e/ou modificá-lo sob
dnl os termos da GPL v.2 - Licença Pública Geral  GNU,  conforme  publicado  pela
dnl Free Software Foundation.
dnl
dnl Este programa é distribuído na expectativa de  ser  útil,  mas  SEM  QUALQUER
dnl GARANTIA; sem mesmo a garantia implícita de COMERCIALIZAÇÃO ou  de  ADEQUAÇÃO
dnl A QUALQUER PROPÓSITO EM PARTICULAR. Consulte a Licença Pública Geral GNU para
dnl obter mais detalhes.
dnl
dnl Você deve ter recebido uma cópia da Licença Pública Geral GNU junto com este
dnl programa;  se  não, escreva para a Free Software Foundation, Inc., 59 Temple
dnl Place, Suite 330, Boston, MA, 02111-1307, USA
dnl
dnl Contatos:
dnl
dnl perry.werneck@gmail.com	(Alexandre Perry de Souza Werneck)
dnl erico.mendonca@gmail.com	(Erico Mascarenhas de Mendonça)
dnl

dnl Process this file with autoconf to produce a configure script.

dnl The minimum version of autoconf required.
AC_PREREQ(2.61)

dnl Initialise automake with the package name, version and
dnl bug-reporting address.
AC_INIT([autofill], [1.0], [perry.werneck@gmail.com])

dnl Place auxilliary scripts here.
AC_CONFIG_AUX_DIR([scripts])

dnl Compute the canonical host-system type
AC_CANONICAL_HOST

dnl Put macro definitions here (though they aren't used).
AC_CONFIG_HEADER([src/include/config.h])

dnl Initialise automake stuff.
AM_INIT_AUTOMAKE

dnl Check for iconv
AM_ICONV

dnl Checks for programs.
AC_PROG_CC
AC_PROG_SED
AC_PROG_LN_S

AC_LANG([C])

dnl ---------------------------------------------------------------------------
dnl Initialize defaults
dnl ---------------------------------------------------------------------------

DBG_CFLAGS="-g -fstack-check -DDEBUG=1"
RLS_CFLAGS="-DNDEBUG=1"
PLUGINS=""
APP_RESOURCES=""
APP_LDFLAGS=""
DLL_LDFLAGS="-shared"
STATIC_LDFLAGS=""

dnl ---------------------------------------------------------------------------
dnl Check for OS specifics
dnl ---------------------------------------------------------------------------

DLLPREFIX="lib"

case "$host" in
	*-mingw32)
		app_cv_osname="windows"
		CFLAGS="$CFLAGS -pthread -D_WIN32_WINNT=0x0600"
		LIBS="$LIBS -lws2_32 -lwtsapi32 -lcomdlg32"
		LDFLAGS="$LDFLAGS -pthread"
		DLLEXT=".dll"

		app_win32_revision=$(date +%y.%m.%d.%H)
		AC_SUBST(WIN32_VERSION,$app_win32_revision)
		;;

 	*)
		app_cv_osname="linux"
		CFLAGS="$CFLAGS -pthread"
		LDFLAGS="$LDFLAGS -pthread"
		DLLEXT=".so"

esac

AC_SUBST(OSNAME,$app_cv_osname)
AC_SUBST(LIBS)
AC_SUBST(DLLEXT)

dnl ---------------------------------------------------------------------------
dnl Check for other programs
dnl ---------------------------------------------------------------------------

AC_PATH_TOOL([AR], [ar], [ar])
AC_PATH_TOOL([WINDRES], [windres], [no])

PKG_CHECK_EXISTS

dnl ---------------------------------------------------------------------------
dnl Version info
dnl ---------------------------------------------------------------------------

AC_SUBST(PACKAGE_DESCRIPTION,"PW3270 Sample autologin")

dnl ---------------------------------------------------------------------------
dnl Check for libintl
dnl ---------------------------------------------------------------------------

INTL_LIBS=""

AC_PATH_TOOL([XGETTEXT], [xgettext], [no])
AC_PATH_TOOL([MSGCAT], [msgcat], [no])
AC_PATH_TOOL([MSGINIT], [msginit], [no])
AC_PATH_TOOL([MSGMERGE], [msgmerge], [no])
AC_PATH_TOOL([MSGFMT], [msgfmt], [no])

AC_SUBST(INTL_LIBS)

dnl ---------------------------------------------------------------------------
dnl Check for LIB3270
dnl ---------------------------------------------------------------------------

PKG_CHECK_MODULES( [LIB3270], [lib3270], AC_DEFINE(HAVE_LIB3270,[],[Do we have lib3270]), AC_MSG_ERROR([LIB3270 not present.]))

AC_SUBST(LIB3270_LIBS)
AC_SUBST(LIB3270_CFLAGS)

dnl ---------------------------------------------------------------------------
dnl Check for LIBV3270
dnl ---------------------------------------------------------------------------

PKG_CHECK_MODULES( [V3270], [libv3270], AC_DEFINE(HAVE_V3270,[],[Do we have libv3270]), AC_MSG_ERROR([V3270 not present.]))

AC_SUBST(V3270_LIBS)
AC_SUBST(V3270_CFLAGS)

dnl ---------------------------------------------------------------------------
dnl Check for GTK
dnl ---------------------------------------------------------------------------

PKG_CHECK_MODULES( [GTK], [gtk+-3.0], AC_DEFINE(HAVE_GTK,[],[Do we have libgtk]), AC_MSG_ERROR([GTK not present.]))

AC_SUBST(GTK_LIBS)
AC_SUBST(GTK_CFLAGS)

dnl ---------------------------------------------------------------------------
dnl Check for GLIB
dnl ---------------------------------------------------------------------------

PKG_CHECK_MODULES( [GLIB], [glib-2.0 gobject-2.0 gmodule-2.0 gio-2.0], AC_DEFINE(HAVE_GLIB,[],[Do we have libglib]), AC_MSG_ERROR([GLIB not present.] ))
AC_SUBST(GLIB_LIBS)
AC_SUBST(GLIB_CFLAGS)

dnl ---------------------------------------------------------------------------
dnl Check for pic
dnl ---------------------------------------------------------------------------
AC_ARG_ENABLE([pic],
	[AS_HELP_STRING([--disable-pic], [disable support for PIC libraries (required to compile on 64bits)])],
[
	app_cv_pic="$enableval"
],[

	case "$host_cpu" in
	x86_64)
		app_cv_pic="yes"
		;;

	aarch64)
		app_cv_pic="yes"
		;;

	*)
		app_cv_pic="no"
	esac

])

if test "$app_cv_pic" == "yes"; then
	CFLAGS="$CFLAGS -fPIC"
	CXXFLAGS="$CXXFLAGS -fPIC"
fi

dnl ---------------------------------------------------------------------------
dnl Configure which files to generate.
dnl ---------------------------------------------------------------------------

AC_CONFIG_FILES(Makefile)

dnl ---------------------------------------------------------------------------
dnl Output the generated config.status script.
dnl ---------------------------------------------------------------------------
AC_SUBST(BASEDIR,$ac_pwd)

AC_OUTPUT

