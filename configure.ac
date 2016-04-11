#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT([Neonlicht], [0.0.1], [milde@hs-fulda.de])
AC_CONFIG_SRCDIR([src/Neonlicht.cpp])
AM_INIT_AUTOMAKE

# Checks for programs.
AC_PROG_CXX

# Checks for libraries.

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([stdlib.h unistd.h])

## Create config file /DOES NOT WORK ????
# AC_CONFIG_HEADERS([config.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([sqrt])
AC_OUTPUT(Makefile man/Makefile src/Makefile)
