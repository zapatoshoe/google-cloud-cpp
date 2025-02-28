# ~~~
# Copyright 2020 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# ~~~

include(GoogleapisConfig)
set(DOXYGEN_PROJECT_NAME "Google Cloud IAM C++ Client")
set(DOXYGEN_PROJECT_BRIEF "A C++ Client Library for Google Cloud IAM")
set(DOXYGEN_PROJECT_NUMBER "${PROJECT_VERSION}")
set(DOXYGEN_EXAMPLE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/samples
                         ${CMAKE_CURRENT_SOURCE_DIR}/quickstart)
set(DOXYGEN_EXCLUDE_SYMBOLS "internal" "iam_internal" "iam_testing" "examples")

# Creates the proto headers needed by doxygen.
set(GOOGLE_CLOUD_CPP_DOXYGEN_DEPS google-cloud-cpp::iam_protos)

include(GoogleCloudCppCommon)

add_library(
    google_cloud_cpp_iam # cmake-format: sort
    iam_client.cc
    iam_client.h
    iam_connection.cc
    iam_connection.h
    iam_connection_idempotency_policy.cc
    iam_connection_idempotency_policy.h
    iam_credentials_client.cc
    iam_credentials_client.h
    iam_credentials_connection.cc
    iam_credentials_connection.h
    iam_credentials_connection_idempotency_policy.cc
    iam_credentials_connection_idempotency_policy.h
    iam_credentials_options.h
    iam_options.h
    iam_policy_client.cc
    iam_policy_client.h
    iam_policy_connection.cc
    iam_policy_connection.h
    iam_policy_connection_idempotency_policy.cc
    iam_policy_connection_idempotency_policy.h
    iam_policy_options.h
    internal/iam_auth_decorator.cc
    internal/iam_auth_decorator.h
    internal/iam_connection_impl.cc
    internal/iam_connection_impl.h
    internal/iam_credentials_auth_decorator.cc
    internal/iam_credentials_auth_decorator.h
    internal/iam_credentials_connection_impl.cc
    internal/iam_credentials_connection_impl.h
    internal/iam_credentials_logging_decorator.cc
    internal/iam_credentials_logging_decorator.h
    internal/iam_credentials_metadata_decorator.cc
    internal/iam_credentials_metadata_decorator.h
    internal/iam_credentials_option_defaults.cc
    internal/iam_credentials_option_defaults.h
    internal/iam_credentials_retry_traits.h
    internal/iam_credentials_stub.cc
    internal/iam_credentials_stub.h
    internal/iam_credentials_stub_factory.cc
    internal/iam_credentials_stub_factory.h
    internal/iam_logging_decorator.cc
    internal/iam_logging_decorator.h
    internal/iam_metadata_decorator.cc
    internal/iam_metadata_decorator.h
    internal/iam_option_defaults.cc
    internal/iam_option_defaults.h
    internal/iam_policy_auth_decorator.cc
    internal/iam_policy_auth_decorator.h
    internal/iam_policy_connection_impl.cc
    internal/iam_policy_connection_impl.h
    internal/iam_policy_logging_decorator.cc
    internal/iam_policy_logging_decorator.h
    internal/iam_policy_metadata_decorator.cc
    internal/iam_policy_metadata_decorator.h
    internal/iam_policy_option_defaults.cc
    internal/iam_policy_option_defaults.h
    internal/iam_policy_retry_traits.h
    internal/iam_policy_stub.cc
    internal/iam_policy_stub.h
    internal/iam_policy_stub_factory.cc
    internal/iam_policy_stub_factory.h
    internal/iam_retry_traits.h
    internal/iam_stub.cc
    internal/iam_stub.h
    internal/iam_stub_factory.cc
    internal/iam_stub_factory.h
    retry_traits.h)
target_include_directories(
    google_cloud_cpp_iam
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
           $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
           $<INSTALL_INTERFACE:include>)
target_link_libraries(
    google_cloud_cpp_iam
    PUBLIC google-cloud-cpp::grpc_utils google-cloud-cpp::common
           google-cloud-cpp::iam_protos google-cloud-cpp::iam_v1_policy_protos)
google_cloud_cpp_add_common_options(google_cloud_cpp_iam)
set_target_properties(
    google_cloud_cpp_iam
    PROPERTIES EXPORT_NAME google-cloud-cpp::iam
               VERSION "${PROJECT_VERSION}"
               SOVERSION "${PROJECT_VERSION_MAJOR}")
target_compile_options(google_cloud_cpp_iam
                       PUBLIC ${GOOGLE_CLOUD_CPP_EXCEPTIONS_FLAG})
add_library(google-cloud-cpp::iam ALIAS google_cloud_cpp_iam)

# To avoid maintaining the list of files for the library, export them to a .bzl
# file.
include(CreateBazelConfig)
create_bazel_config(google_cloud_cpp_iam YEAR "2020")

# Create a header-only library for the mocks. We use a CMake `INTERFACE` library
# for these, a regular library would not work on macOS (where the library needs
# at least one .o file). Unfortunately INTERFACE libraries are a bit weird in
# that they need absolute paths for their sources.
add_library(google_cloud_cpp_iam_mocks INTERFACE)
target_sources(
    google_cloud_cpp_iam_mocks
    INTERFACE
        # cmake-format: sort
        ${CMAKE_CURRENT_SOURCE_DIR}/mocks/mock_iam_connection.h
        ${CMAKE_CURRENT_SOURCE_DIR}/mocks/mock_iam_credentials_connection.h
        ${CMAKE_CURRENT_SOURCE_DIR}/mocks/mock_iam_policy_connection.h)
target_link_libraries(
    google_cloud_cpp_iam_mocks
    INTERFACE google-cloud-cpp::iam_mocks google-cloud-cpp::iam
              GTest::gmock_main GTest::gmock GTest::gtest)
set_target_properties(google_cloud_cpp_iam_mocks
                      PROPERTIES EXPORT_NAME google-cloud-cpp::iam_mocks)
create_bazel_config(google_cloud_cpp_iam_mocks YEAR "2020")
target_include_directories(
    google_cloud_cpp_iam_mocks
    INTERFACE $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
              $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
              $<INSTALL_INTERFACE:include>)
target_compile_options(google_cloud_cpp_iam_mocks
                       INTERFACE ${GOOGLE_CLOUD_CPP_EXCEPTIONS_FLAG})

add_subdirectory(integration_tests)
# Examples are enabled if possible, but package maintainers may want to disable
# compilation to speed up their builds.
if (GOOGLE_CLOUD_CPP_ENABLE_EXAMPLES)
    add_executable(iam_quickstart "quickstart/quickstart.cc")
    target_link_libraries(iam_quickstart PRIVATE google-cloud-cpp::iam)
    google_cloud_cpp_add_common_options(iam_quickstart)
    add_test(
        NAME iam_quickstart
        COMMAND cmake -P "${PROJECT_SOURCE_DIR}/cmake/quickstart-runner.cmake"
                $<TARGET_FILE:iam_quickstart> GOOGLE_CLOUD_PROJECT)
    set_tests_properties(iam_quickstart
                         PROPERTIES LABELS "integration-test;quickstart")
endif ()

# Get the destination directories based on the GNU recommendations.
include(GNUInstallDirs)

# Export the CMake targets to make it easy to create configuration files.
install(
    EXPORT google_cloud_cpp_iam-targets
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/google_cloud_cpp_iam"
    COMPONENT google_cloud_cpp_development)

# Install the libraries and headers in the locations determined by
# GNUInstallDirs
install(
    TARGETS google_cloud_cpp_iam
    EXPORT google_cloud_cpp_iam-targets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            COMPONENT google_cloud_cpp_runtime
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_runtime
            NAMELINK_SKIP
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_development)
# With CMake-3.12 and higher we could avoid this separate command (and the
# duplication).
install(
    TARGETS google_cloud_cpp_iam
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_development
            NAMELINK_ONLY
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            COMPONENT google_cloud_cpp_development)

google_cloud_cpp_install_headers("google_cloud_cpp_iam"
                                 "include/google/cloud/iam")
google_cloud_cpp_install_headers("google_cloud_cpp_iam_mocks"
                                 "include/google/cloud/iam")

google_cloud_cpp_add_pkgconfig(
    iam
    "The Google Cloud IAM C++ Client Library"
    "Provides C++ APIs to access Google Cloud IAM."
    "google_cloud_cpp_grpc_utils"
    " google_cloud_cpp_common"
    " google_cloud_cpp_iam_protos")

# Create and install the CMake configuration files.
include(CMakePackageConfigHelpers)
configure_file("config.cmake.in" "google_cloud_cpp_iam-config.cmake" @ONLY)
write_basic_package_version_file(
    "google_cloud_cpp_iam-config-version.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY ExactVersion)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/google_cloud_cpp_iam-config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/google_cloud_cpp_iam-config-version.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/google_cloud_cpp_iam"
    COMPONENT google_cloud_cpp_development)
