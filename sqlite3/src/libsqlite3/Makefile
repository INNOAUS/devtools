# **********************************************************************
#
# Copyright (c) 2003-2011 ZeroC, Inc. All rights reserved.
#
# This copy of Ice is licensed to you under the terms described in the
# ICE_LICENSE file included in this distribution.
#
# **********************************************************************

top_srcdir	= ../../..


LIBFILENAME = $(call mklibfilename,sqlite3,$(VERSION))
SONAME      = $(call mksoname,sqlite3,$(soversion))
LIBNAME		= $(call mklibname,sqlite3)

TARGETS		= $(call mklibtargets,$(LIBFILENAME),$(SONAME),$(LIBNAME))

OBJS		= shell.o 	  \
		      sqlite3.o

SRCS		= $(OBJS:.o=.c)

STATICLIBS = yes

include $(top_srcdir)/config/Make.rules
include ../Makefile.proj

CPPFLAGS	:= -I. -I.. -I/usr/include -I/opt/local/include -I/usr/include/postgresql $(CPPFLAGS)
CPPFLAGS	:= $(CPPFLAGS)
LDFLAGS		:= -L/usr/lib -L/opt/local/lib

#ifeq ($(OPTIMIZE), yes)
#    CPPFLAGS := -O3 $(CPPFLAGS)
#endif

$(LIBNAME): $(OBJS)
	rm -f $@
	ar cr $@ $(OBJS)
	cp $@ $(top_srcdir)/$(proj_name)/lib/

clean::
