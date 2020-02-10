#
#Copyright 2020 Xproject authors

VERSION=1.0.0.0
RELEASEDIR=../release
INSTDIR=xprojectapp

OSV=$(shell lsb_release -rs)

BIT=$(shell getconf LONG_BIT)
OUTPUTFILE=Xproject_Core_$(VERSION)_CENTOS$(OSV)_x86_$(BIT)bit_Bin.tar.gz

#source code
CC_SRC=$(wildcard grpcproto/startX/*.cc grpcproto/parameters/*.cc grpcproto/glass/*.cc calcucomponents/*.cc calcucomponents/columns/*.cc calcucomponents/connectors/*.cc calcucomponents/crossbeams/*.cc calcucomponents/embedded/*.cc calcucomponents/gums/*.cc calcucomponents/loads/*.cc calcucomponents/panels/*.cc loghelper/*.cc calcucomponents/factorys/*.cc)

#object
CC_OBJ=$(patsubst %.cc, ./build/%.o, $(CC_SRC))

#include_dir
INC_DIR= -I./ -I ../export/glog/ -I ../export/jsonCpp/ -I ../export/tinyxml/ -I ../export/xmlConfig/ -I ./grpcproto/startX/ -I ./grpcproto/glass/ -I ./grpcproto/parameters/ -I ./loghelper/ -I ./calcucomponents/ -I ./calcucomponents/columns/ -I ./calcucomponents/connectors/ -I ./calcucomponents/crossbeams/ -I ./calcucomponents/embedded/ -I ./calcucomponents/gums/ -I ./calcucomponents/loads/ -I ./calcucomponents/panels/ -I ./calcucomponents/factorys/

#lib_dir
LIB_DIR=-L ../libs -L ../libs/glog/suse$(BIT) -L ../libs/glog/ -L ../libs/tinyxml/ -L ../libs/xmlConfig/ -L ../libs/jsonCpp/suse$(BIT)

#libs
LIBS=-lxmlConfig$(BIT) -ljsonCpp -lglog -llog4cxx -ltinyxml$(BIT) -lapr -laprutil 


CPPFLAGS += $(INC_DIR) -D_VERSION=$(VERSION) -Wno-deprecated
CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++11

ifeq ($(SYSTEM),Darwin)
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -pthread\
           -lgrpc++_reflection\
           -ldl
else
LDFLAGS += -L/usr/local/lib `pkg-config --libs protobuf grpc++`\
           -pthread\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl
endif

LDFLAGS += $(LIB_DIR) $(LIBS)

CXX=g++

EXTRA_CPPFLAGS=-g -DCONSOLE_DEBUG
CCOPTION=-DLINUX -DTIXML_USE_STL $(EXTRA_CPPFLAGS)

PROTOC=protoc
GRPC_CPP_PLUGIN= grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN_PATH)` 

COMPONENTS=components

PROTOS_PATH=../protos

vpath %.proto $(PROTOS_PATH)

EXE=../bin/Xproject
all:$(EXE)

$(EXE): $(CC_OBJ) ./main.cc
	ar -r ../libs/lib$(COMPONENTS).a $(CC_OBJ)
	$(CXX) ./*.cc -l$(COMPONENTS) $(CPPFLAGS) $(LDFLAGS) $(CCOPTION) -o $@;

./build/%.o:%.cc
	$(CXX) $(CPPFLAGS) $(CCOPTION) -o $@ -c $<

./build/%.d:%.cc
	@set -e;rm -f $@; \
	$(CC) -MM $(INC_DIR) $(CCOPTION) $< > $@.$$$$; \
	sed 's,.*\.o[ :]*,$(patsubst %.d, %.o, $@) $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$;

#.PRECIOUS: ../grpcproto/%.grpc.pb.cc
#../grpcproto/%.grpc.pb.cc: %.proto
#	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=. --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $<
#
#.PRECIOUS: %.pb.cc
#%.pb.cc: %.proto
#	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=. $<

clean:
	rm -rf $(EXE) $(CC_OBJ) 
	rm -f ../libs/lib$(COMPONENTS).a


