# Copyright (C) 2013 Calpont Corp.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; version 2 of
# the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.

# $Id: Makefile.am 3639 2013-03-18 12:36:37Z rdempsey $
## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = $(idb_common_includes) $(idb_cppflags)
AM_CFLAGS = $(idb_cflags)
AM_CXXFLAGS = $(idb_cxxflags)
AM_LDFLAGS = -version-info 1:0:0 $(idb_ldflags)
lib_LTLIBRARIES = libmessageqcpp.la
libmessageqcpp_la_SOURCES = messagequeue.cpp bytestream.cpp socketparms.cpp inetstreamsocket.cpp iosocket.cpp compressed_iss.cpp
include_HEADERS = messagequeue.h bytestream.h socketparms.h inetstreamsocket.h iosocket.h \
serversocket.h socket.h serializeable.h socketclosed.h

test:

coverage:

leakcheck:

docs:

bootstrap: install-data-am

