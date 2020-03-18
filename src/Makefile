#
#Copyright 2020 Xproject authors

VERSION=1.0.0.0
RELEASEDIR=../release
INSTDIR=xprojectapp

OSV=$(shell lsb_release -rs)

BIT=$(shell getconf LONG_BIT)
OUTPUTFILE=Xproject_Core_$(VERSION)_CENTOS$(OSV)_x86_$(BIT)bit_Bin.tar.gz

#source code
CC_SRC=$(wildcard grpcproto/startX/*.cc grpcproto/parameters/*.cc grpcproto/glass/*.cc calcucomponents/*.cc calcucomponents/columns/*.cc calcucomponents/connectors/*.cc calcucomponents/crossbeams/*.cc calcucomponents/embedded/*.cc calcucomponents/gums/*.cc calcucomponents/loads/*.cc calcucomponents/panels/*.cc loghelper/*.cc calcucomponents/factorys/*.cc util/*.cc)

CC_TEST_SRC=$(wildcard tests/*.cc grpcproto/parameters/*.cc grpcproto/glass/*.cc loghelper/*.cc calcucomponents/factorys/*.cc util/*.cc)

#object
CC_OBJ=$(patsubst %.cc, ./build/%.o, $(CC_SRC))

CC_TEST_OBJ=$(patsubst %.cc, ./build/%.o,$(CC_TEST_SRC))

#include_dir
INC_DIR= -I./ -I ../export/ -I ../export/glog/ -I ../export/grpcpp/ -I ../export/grpc++/ -I ../export/grpc/ -I ../export/google/ -I ../export/google/protobuf/ -I ../export/jsonCpp/ -I ../export/tinyxml/ -I ../export/xmlConfig/ -I ./grpcproto/startX/ -I ./grpcproto/glass/ -I ./grpcproto/parameters/ -I ./loghelper/ -I ./calcucomponents/ -I ./calcucomponents/columns/ -I ./calcucomponents/connectors/ -I ./calcucomponents/crossbeams/ -I ./calcucomponents/embedded/ -I ./calcucomponents/gums/ -I ./calcucomponents/loads/ -I ./calcucomponents/panels/ -I ./calcucomponents/factorys/ -I ./util/ \
	 -I ./tests/

#lib_dir
LIB_DIR=-L ../libs -L ../libs/glog/suse$(BIT) -L ../libs/glog/ -L ../libs/tinyxml/ -L ../libs/xmlConfig/ -L ../libs/jsonCpp/suse$(BIT) -L ../libs/grpc/

#libs
LIBS=-lxmlConfig$(BIT) -ljsonCpp -lglog  -ltinyxml$(BIT) -lgrpc -lgrpc++ -lgrpc++_alts -lgrpc_cronet -lgrpc++_error_details -lgrpcpp_channelz -lgrpc++_reflection -lgrpc++_unsecure -lgrpc_unsecure\
    -lprotobuf -lprotobuf-lite -lprotoc  


CPPFLAGS += $(INC_DIR) -D_VERSION=$(VERSION) -Wno-deprecated
#CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -std=c++11

ifeq ($(SYSTEM),Darwin)
LDFLAGS += -pthread\
           -lgrpc++_reflection\
           -ldl
else
LDFLAGS += -pthread\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl
endif

LDFLAGS += $(LIB_DIR) $(LIBS)

CXX=clang++

EXTRA_CPPFLAGS=-g -DCONSOLE_DEBUG
CCOPTION=-DLINUX -DTIXML_USE_STL $(EXTRA_CPPFLAGS)

PROTOC=protoc
GRPC_CPP_PLUGIN= grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN_PATH)` 

COMPONENTS=components
COMPONENTS_TEST=components_test

PROTOS_PATH=../protos

vpath %.proto $(PROTOS_PATH)

EXE=../bin/Xproject
TEST_EXE=../bin/Xproject_test
all:$(EXE) $(TEST_EXE)

$(EXE): $(CC_OBJ) ./main.cc 
	ar -r ../libs/lib$(COMPONENTS).a $(CC_OBJ)
	$(CXX) ./main.cc -l$(COMPONENTS) $(CPPFLAGS) $(LDFLAGS) $(CCOPTION) -o $@;

$(TEST_EXE): $(CC_TEST_OBJ) ./main_test.cc 
	ar -r ../libs/lib$(COMPONENTS_TEST).a $(CC_TEST_OBJ)
	$(CXX) ./main_test.cc -l$(COMPONENTS_TEST) $(CPPFLAGS) $(LDFLAGS) $(CCOPTION) -o $@;

./build/%.o:%.cc
	$(CXX) $(CPPFLAGS) $(CCOPTION) -o $@ -c $<

./build/%.d:%.cc
	@set -e;rm -f $@; \
	$(CXX) -MM $(INC_DIR) $(CCOPTION) $< > $@.$$$$; \
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
	rm -rf $(EXE) $(CC_OBJ) $(TEST_EXE) $(CC_TEST_OBJ) 
	rm -f ../libs/lib$(COMPONENTS).a
	rm -f ../libs/lib$(COMPONENTS_TEST).a


