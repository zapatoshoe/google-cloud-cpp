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
// source: google/monitoring/v3/uptime_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_UPTIME_CHECK_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_UPTIME_CHECK_STUB_H

#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/monitoring/v3/uptime_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class UptimeCheckServiceStub {
 public:
  virtual ~UptimeCheckServiceStub() = 0;

  virtual StatusOr<google::monitoring::v3::ListUptimeCheckConfigsResponse>
  ListUptimeCheckConfigs(
      grpc::ClientContext& context,
      google::monitoring::v3::ListUptimeCheckConfigsRequest const& request) = 0;

  virtual StatusOr<google::monitoring::v3::UptimeCheckConfig>
  GetUptimeCheckConfig(
      grpc::ClientContext& context,
      google::monitoring::v3::GetUptimeCheckConfigRequest const& request) = 0;

  virtual StatusOr<google::monitoring::v3::UptimeCheckConfig>
  CreateUptimeCheckConfig(
      grpc::ClientContext& context,
      google::monitoring::v3::CreateUptimeCheckConfigRequest const&
          request) = 0;

  virtual StatusOr<google::monitoring::v3::UptimeCheckConfig>
  UpdateUptimeCheckConfig(
      grpc::ClientContext& context,
      google::monitoring::v3::UpdateUptimeCheckConfigRequest const&
          request) = 0;

  virtual Status DeleteUptimeCheckConfig(
      grpc::ClientContext& context,
      google::monitoring::v3::DeleteUptimeCheckConfigRequest const&
          request) = 0;

  virtual StatusOr<google::monitoring::v3::ListUptimeCheckIpsResponse>
  ListUptimeCheckIps(
      grpc::ClientContext& context,
      google::monitoring::v3::ListUptimeCheckIpsRequest const& request) = 0;
};

class DefaultUptimeCheckServiceStub : public UptimeCheckServiceStub {
 public:
  explicit DefaultUptimeCheckServiceStub(
      std::unique_ptr<google::monitoring::v3::UptimeCheckService::StubInterface>
          grpc_stub)
      : grpc_stub_(std::move(grpc_stub)) {}

  StatusOr<google::monitoring::v3::ListUptimeCheckConfigsResponse>
  ListUptimeCheckConfigs(
      grpc::ClientContext& client_context,
      google::monitoring::v3::ListUptimeCheckConfigsRequest const& request)
      override;

  StatusOr<google::monitoring::v3::UptimeCheckConfig> GetUptimeCheckConfig(
      grpc::ClientContext& client_context,
      google::monitoring::v3::GetUptimeCheckConfigRequest const& request)
      override;

  StatusOr<google::monitoring::v3::UptimeCheckConfig> CreateUptimeCheckConfig(
      grpc::ClientContext& client_context,
      google::monitoring::v3::CreateUptimeCheckConfigRequest const& request)
      override;

  StatusOr<google::monitoring::v3::UptimeCheckConfig> UpdateUptimeCheckConfig(
      grpc::ClientContext& client_context,
      google::monitoring::v3::UpdateUptimeCheckConfigRequest const& request)
      override;

  Status DeleteUptimeCheckConfig(
      grpc::ClientContext& client_context,
      google::monitoring::v3::DeleteUptimeCheckConfigRequest const& request)
      override;

  StatusOr<google::monitoring::v3::ListUptimeCheckIpsResponse>
  ListUptimeCheckIps(grpc::ClientContext& client_context,
                     google::monitoring::v3::ListUptimeCheckIpsRequest const&
                         request) override;

 private:
  std::unique_ptr<google::monitoring::v3::UptimeCheckService::StubInterface>
      grpc_stub_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_UPTIME_CHECK_STUB_H
