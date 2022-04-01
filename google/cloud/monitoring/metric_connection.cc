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
// source: google/monitoring/v3/metric_service.proto

#include "google/cloud/monitoring/metric_connection.h"
#include "google/cloud/monitoring/internal/metric_connection_impl.h"
#include "google/cloud/monitoring/internal/metric_option_defaults.h"
#include "google/cloud/monitoring/internal/metric_stub_factory.h"
#include "google/cloud/monitoring/metric_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

MetricServiceConnection::~MetricServiceConnection() = default;

StreamRange<google::api::MonitoredResourceDescriptor>
MetricServiceConnection::ListMonitoredResourceDescriptors(
    google::monitoring::v3::
        ListMonitoredResourceDescriptorsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::api::MonitoredResourceDescriptor>>();
}

StatusOr<google::api::MonitoredResourceDescriptor>
MetricServiceConnection::GetMonitoredResourceDescriptor(
    google::monitoring::v3::GetMonitoredResourceDescriptorRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::api::MetricDescriptor>
MetricServiceConnection::ListMetricDescriptors(
    google::monitoring::v3::
        ListMetricDescriptorsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::api::MetricDescriptor>>();
}

StatusOr<google::api::MetricDescriptor>
MetricServiceConnection::GetMetricDescriptor(
    google::monitoring::v3::GetMetricDescriptorRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::api::MetricDescriptor>
MetricServiceConnection::CreateMetricDescriptor(
    google::monitoring::v3::CreateMetricDescriptorRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status MetricServiceConnection::DeleteMetricDescriptor(
    google::monitoring::v3::DeleteMetricDescriptorRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::monitoring::v3::TimeSeries>
MetricServiceConnection::ListTimeSeries(
    google::monitoring::v3::
        ListTimeSeriesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::monitoring::v3::TimeSeries>>();
}

Status MetricServiceConnection::CreateTimeSeries(
    google::monitoring::v3::CreateTimeSeriesRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status MetricServiceConnection::CreateServiceTimeSeries(
    google::monitoring::v3::CreateTimeSeriesRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<MetricServiceConnection> MakeMetricServiceConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 MetricServicePolicyOptionList>(options,
                                                                __func__);
  options =
      monitoring_internal::MetricServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = monitoring_internal::CreateDefaultMetricServiceStub(
      background->cq(), options);
  return std::make_shared<monitoring_internal::MetricServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<monitoring::MetricServiceConnection>
MakeMetricServiceConnection(std::shared_ptr<MetricServiceStub> stub,
                            Options options) {
  options = MetricServiceDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<monitoring_internal::MetricServiceConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google
