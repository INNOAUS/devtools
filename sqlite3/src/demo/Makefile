top_srcdir  = ../../..

SERVER      = demo

TARGETS     = $(SERVER)

OBJS        = demo.o
		  								  

SRCS        = $(OBJS:.o=.cpp) 
SLICE_SRCS  = 

include $(top_srcdir)/config/Make.rules
include ../Makefile.proj

CPPFLAGS    := -I. -I/usr/include -I/usr/include/postgresql -I$(top_srcdir)/$(proj_name)/src -I$(ACE_ROOT)/include -I$(CRYPTOPP_ROOT)/include -Wno-deprecated -Wno-sign-compare $(CPPFLAGS) 
CPPFLAGS	:= $(CPPFLAGS)
#ifeq ($(OPTIMIZE), yes)
#    CPPFLAGS := -O3 $(CPPFLAGS)
#endif

LDFLAGS		:= -L$(top_srcdir)/$(proj_name)/lib -L/usr/lib -L$(ACE_ROOT)/lib -L$(CRYPTOPP_ROOT)/lib $(LDFLAGS) 
LINKWITH    := -lIce -lIceUtil -lIceSSL -lFreeze -lIceStorm -lIcePatch2 -lIceGrid -lGlacier2 -lIceBox -linnoaus+sqlite3 -lcryptopp -lpq -lpthread -ldl -lACE

$(SERVER): $(OBJS)
	rm -f $@
	$(CXX) $(LDFLAGS) -o $@ $(OBJS) $(DB_RPATH_LINK) $(LIBS) $(LINKWITH)
	cp $@ $(top_srcdir)/$(proj_name)/bin

clean::

