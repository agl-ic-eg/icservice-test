AUTOMAKE_OPTIONS = foreign
ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}

bin_PROGRAMS = icservice

icservice_SOURCES = \
		ipc_common.c \
		ic_service.c 

icservice_LDADD = \
		@LIBCLUSTERIPC_LIBS@ \
		@LIBCLUSTERAPI_LIBS@ \
		-lrt -lpthread 

icservice_CFLAGS = \
		-I$(top_srcdir)/include \
		-g \
		@LIBCLUSTERIPC_LIBS@ \
		@LIBCLUSTERAPI_LIBS@

icservice_CXXFLAGS = \
		-I$(top_srcdir)/include \
		-std=c++11 -g \
		@LIBCLUSTERIPC_LIBS@ \
		@LIBCLUSTERAPI_LIBS@

icservice_LDFLAGS = \
		@LIBCLUSTERIPC_LIBS@ \
		@LIBCLUSTERAPI_LIBS@ \
		-lrt -lpthread 


icservice_CFLAGS   += @LIBCLUSTERIPC_CFLAGS@ @LIBCLUSTERAPI_CFLAGS@
icservice_CXXFLAGS += @LIBCLUSTERIPC_CFLAGS@ @LIBCLUSTERAPI_CFLAGS@

if ENABLE_DEBUG
icservice_CFLAGS   += -DENABLE_DEBUG
icservice_CXXFLAGS += -DENABLE_DEBUG
endif

if ENABLE_DEBUGLOG
icservice_CFLAGS   += -DENABLE_DEBUGLOG
icservice_CXXFLAGS += -DENABLE_DEBUGLOG
endif

