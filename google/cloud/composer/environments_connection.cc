// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/orchestration/airflow/service/v1/environments.proto

#include "google/cloud/composer/environments_connection.h"
#include "google/cloud/composer/environments_options.h"
#include "google/cloud/composer/internal/environments_connection_impl.h"
#include "google/cloud/composer/internal/environments_option_defaults.h"
#include "google/cloud/composer/internal/environments_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace composer {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

EnvironmentsConnection::~EnvironmentsConnection() = default;

future<
    StatusOr<google::cloud::orchestration::airflow::service::v1::Environment>>
EnvironmentsConnection::CreateEnvironment(
    google::cloud::orchestration::airflow::service::v1::
        CreateEnvironmentRequest const&) {
  return google::cloud::make_ready_future<StatusOr<
      google::cloud::orchestration::airflow::service::v1::Environment>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::cloud::orchestration::airflow::service::v1::Environment>
EnvironmentsConnection::GetEnvironment(
    google::cloud::orchestration::airflow::service::v1::
        GetEnvironmentRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::orchestration::airflow::service::v1::Environment>
EnvironmentsConnection::ListEnvironments(
    google::cloud::orchestration::airflow::service::v1::
        ListEnvironmentsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<StreamRange<
      google::cloud::orchestration::airflow::service::v1::Environment>>();
}

future<
    StatusOr<google::cloud::orchestration::airflow::service::v1::Environment>>
EnvironmentsConnection::UpdateEnvironment(
    google::cloud::orchestration::airflow::service::v1::
        UpdateEnvironmentRequest const&) {
  return google::cloud::make_ready_future<StatusOr<
      google::cloud::orchestration::airflow::service::v1::Environment>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<
    google::cloud::orchestration::airflow::service::v1::OperationMetadata>>
EnvironmentsConnection::DeleteEnvironment(
    google::cloud::orchestration::airflow::service::v1::
        DeleteEnvironmentRequest const&) {
  return google::cloud::make_ready_future<StatusOr<
      google::cloud::orchestration::airflow::service::v1::OperationMetadata>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

std::shared_ptr<EnvironmentsConnection> MakeEnvironmentsConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 EnvironmentsPolicyOptionList>(options,
                                                               __func__);
  options = composer_internal::EnvironmentsDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = composer_internal::CreateDefaultEnvironmentsStub(background->cq(),
                                                               options);
  return std::make_shared<composer_internal::EnvironmentsConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace composer
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace composer_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<composer::EnvironmentsConnection> MakeEnvironmentsConnection(
    std::shared_ptr<EnvironmentsStub> stub, Options options) {
  options = EnvironmentsDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<composer_internal::EnvironmentsConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace composer_internal
}  // namespace cloud
}  // namespace google
