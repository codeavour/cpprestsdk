cmake_minimum_required(VERSION 3.30.5)
project(cpprestsdk-root NONE)

include(ExternalProject)

ExternalProject_Add(boost
        GIT_REPOSITORY https://github.com/boostorg/boost.git
        GIT_TAG boost-1.87.0
        CMAKE_ARGS
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install
        LOG_DOWNLOAD ON
        LOG_CONFIGURE ON
        LOG_BUILD ON
        LOG_INSTALL ON
)

ExternalProject_Add(cpprestsdk
        GIT_REPOSITORY https://github.com/codeavour/cpprestsdk.git
        GIT_TAG HEAD
        DEPENDS boost
        CMAKE_ARGS
            -DBUILD_TESTS=OFF   # turned off as it generates build errors
            -DWERROR=OFF        # turned off as there are warnings
#            -DCMAKE_CXX_STANDARD=11
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/install
            -DCMAKE_CXX_FLAGS=BOOST_ASIO_NO_DEPRECATED=0
            -DBoost_USE_STATIC_LIBS=ON
#            -DBOOST_ASIO_NO_DEPRECATED=OFF  # Linux version of cpprestsdk indireclty relies on boost's deprecated IO service
        LOG_DOWNLOAD ON
        LOG_CONFIGURE ON
        LOG_BUILD ON
        LOG_INSTALL ON
)