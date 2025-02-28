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
// source: google/cloud/webrisk/v1/webrisk.proto

#include "google/cloud/webrisk/web_risk_connection.h"
#include "google/cloud/webrisk/internal/web_risk_connection_impl.h"
#include "google/cloud/webrisk/internal/web_risk_option_defaults.h"
#include "google/cloud/webrisk/internal/web_risk_stub_factory.h"
#include "google/cloud/webrisk/web_risk_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/grpc_options.h"
#include <memory>

namespace google {
namespace cloud {
namespace webrisk {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

WebRiskServiceConnection::~WebRiskServiceConnection() = default;

StatusOr<google::cloud::webrisk::v1::ComputeThreatListDiffResponse>
WebRiskServiceConnection::ComputeThreatListDiff(
    google::cloud::webrisk::v1::ComputeThreatListDiffRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::webrisk::v1::SearchUrisResponse>
WebRiskServiceConnection::SearchUris(
    google::cloud::webrisk::v1::SearchUrisRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::webrisk::v1::SearchHashesResponse>
WebRiskServiceConnection::SearchHashes(
    google::cloud::webrisk::v1::SearchHashesRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::webrisk::v1::Submission>
WebRiskServiceConnection::CreateSubmission(
    google::cloud::webrisk::v1::CreateSubmissionRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<WebRiskServiceConnection> MakeWebRiskServiceConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 UnifiedCredentialsOptionList,
                                 WebRiskServicePolicyOptionList>(options,
                                                                 __func__);
  options = webrisk_internal::WebRiskServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = webrisk_internal::CreateDefaultWebRiskServiceStub(
      background->cq(), options);
  return std::make_shared<webrisk_internal::WebRiskServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace webrisk
}  // namespace cloud
}  // namespace google
