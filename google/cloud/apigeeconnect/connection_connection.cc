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
// source: google/cloud/apigeeconnect/v1/connection.proto

#include "google/cloud/apigeeconnect/connection_connection.h"
#include "google/cloud/apigeeconnect/connection_options.h"
#include "google/cloud/apigeeconnect/internal/connection_connection_impl.h"
#include "google/cloud/apigeeconnect/internal/connection_option_defaults.h"
#include "google/cloud/apigeeconnect/internal/connection_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace apigeeconnect {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ConnectionServiceConnection::~ConnectionServiceConnection() = default;

StreamRange<google::cloud::apigeeconnect::v1::Connection>
ConnectionServiceConnection::ListConnections(
    google::cloud::apigeeconnect::v1::
        ListConnectionsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::apigeeconnect::v1::Connection>>();
}

std::shared_ptr<ConnectionServiceConnection> MakeConnectionServiceConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 ConnectionServicePolicyOptionList>(options,
                                                                    __func__);
  options = apigeeconnect_internal::ConnectionServiceDefaultOptions(
      std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = apigeeconnect_internal::CreateDefaultConnectionServiceStub(
      background->cq(), options);
  return std::make_shared<
      apigeeconnect_internal::ConnectionServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace apigeeconnect
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace apigeeconnect_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<apigeeconnect::ConnectionServiceConnection>
MakeConnectionServiceConnection(std::shared_ptr<ConnectionServiceStub> stub,
                                Options options) {
  options = ConnectionServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<
      apigeeconnect_internal::ConnectionServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace apigeeconnect_internal
}  // namespace cloud
}  // namespace google
