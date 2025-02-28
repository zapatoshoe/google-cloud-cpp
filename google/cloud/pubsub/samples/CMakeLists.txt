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

if (NOT BUILD_TESTING)
    return()
endif ()

add_library(pubsub_samples_common # cmake-format: sort
            pubsub_samples_common.cc pubsub_samples_common.h)
target_link_libraries(
    pubsub_samples_common
    pubsub_client_testing
    google-cloud-cpp::pubsub
    google-cloud-cpp::common
    google-cloud-cpp::grpc_utils
    gRPC::grpc++
    gRPC::grpc
    protobuf::libprotobuf)
google_cloud_cpp_add_common_options(pubsub_samples_common)
create_bazel_config(pubsub_samples_common YEAR 2020)

set(pubsub_samples_unit_tests # cmake-format: sort
                              pubsub_samples_common_test.cc)

foreach (fname ${pubsub_samples_unit_tests})
    google_cloud_cpp_add_executable(target "pubsub_samples" "${fname}")
    target_link_libraries(
        ${target}
        PRIVATE pubsub_samples_common
                google_cloud_cpp_testing
                google-cloud-cpp::pubsub
                google-cloud-cpp::common
                google-cloud-cpp::grpc_utils
                GTest::gmock_main
                GTest::gmock
                GTest::gtest
                gRPC::grpc++
                gRPC::grpc
                protobuf::libprotobuf)
    add_test(NAME ${target} COMMAND ${target})
    google_cloud_cpp_add_common_options(${target})
endforeach ()

export_list_to_bazel("pubsub_samples_unit_tests.bzl"
                     "pubsub_samples_unit_tests" YEAR "2020")

set(pubsub_client_integration_samples
    # cmake-format: sort
    blocking_samples.cc client_samples.cc samples.cc)
if (TARGET google-cloud-cpp::iam)
    list(APPEND pubsub_client_integration_samples iam_samples.cc)
endif ()
set(pubsub_client_unit_samples # cmake-format: sort
                               mock_publisher.cc mock_subscriber.cc)

# Export the list of unit tests to a .bzl file so we do not need to maintain the
# list in two places.
export_list_to_bazel("pubsub_client_integration_samples.bzl"
                     "pubsub_client_integration_samples" YEAR "2020")
export_list_to_bazel("pubsub_client_unit_samples.bzl"
                     "pubsub_client_unit_samples" YEAR "2020")

google_cloud_cpp_proto_library(
    pubsub_samples_protos samples.proto PROTO_PATH_DIRECTORIES
    ${CMAKE_CURRENT_SOURCE_DIR} LOCAL_INCLUDE)

# Generate a target for each integration test.
foreach (fname ${pubsub_client_integration_samples})
    google_cloud_cpp_add_executable(target "pubsub" "${fname}")
    add_test(NAME ${target} COMMAND ${target})
    target_link_libraries(
        ${target} PRIVATE pubsub_samples_protos pubsub_samples_common
                          google_cloud_cpp_testing google-cloud-cpp::pubsub)
    google_cloud_cpp_add_common_options(${target})
endforeach ()

# Generate a target for each unit test.
foreach (fname ${pubsub_client_unit_samples})
    google_cloud_cpp_add_executable(target "pubsub" "${fname}")
    add_test(NAME ${target} COMMAND ${target})
    target_link_libraries(
        ${target}
        PRIVATE pubsub_samples_protos
                pubsub_samples_common
                google_cloud_cpp_testing
                google-cloud-cpp::pubsub
                GTest::gmock_main
                GTest::gmock
                GTest::gtest)
    google_cloud_cpp_add_common_options(${target})
endforeach ()

foreach (fname ${pubsub_client_integration_samples})
    google_cloud_cpp_set_target_name(target "pubsub" "${fname}")
    set_tests_properties(
        ${target} PROPERTIES LABELS
                             "integration-test;integration-test-emulator")
endforeach ()

if (TARGET google-cloud-cpp::iam)
    target_link_libraries(pubsub_iam_samples PRIVATE google-cloud-cpp::iam)
endif ()
