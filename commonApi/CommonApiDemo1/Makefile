OS            ?= ${PLATFORM_NAME}
BUILD_DIR     ?= build
INSTALL_DIR   ?= ${SOA_DIR}/install
BUILD_TYPE    ?= Release

.PHONY: clean create build

 

default: clean create build

create: 
ifeq ("$(wildcard $(BUILD_DIR))", "")
	@echo "${BUILD_DIR} Directory Does not exist creating."
	mkdir ${BUILD_DIR}
else
	@echo "${BUILD_DIR} Directory Already Exists."
endif
 

build:
	@echo ${PLATFORM_NAME}
	sleep 1
ifeq ($(OS),QNX)
	cd ${BUILD_DIR}; \
	"Building CommonApiDemo1"; \
	cmake -DCMAKE_TOOLCHAIN_FILE=${SOA_DIR}/soa-infra/framework/qcc8_qnx710_aarch64le.cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} .. ; \
	make install -j8;
endif
ifeq ($(OS),Linux)
	cd ${BUILD_DIR}; \
	"Building CommonApiDemo1"; \
	cmake -DCMAKE_BUILD_TYPE=${BUILD_TYPE} -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} .. ; \
	make install -j8;
endif

 

clean:
ifeq ("$(wildcard $(BUILD_DIR))", "")
	@echo "${BUILD_DIR} Directory Does not exist."
else
	@echo "${BUILD_DIR} Directory Exists deleting."
	rm -rf ${BUILD_DIR}
endif

install: default


hinstall:
