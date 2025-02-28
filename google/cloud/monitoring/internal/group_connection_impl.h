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
// source: google/monitoring/v3/group_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_GROUP_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_GROUP_CONNECTION_IMPL_H

#include "google/cloud/monitoring/group_connection.h"
#include "google/cloud/monitoring/group_connection_idempotency_policy.h"
#include "google/cloud/monitoring/group_options.h"
#include "google/cloud/monitoring/internal/group_retry_traits.h"
#include "google/cloud/monitoring/internal/group_stub.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class GroupServiceConnectionImpl : public monitoring::GroupServiceConnection {
 public:
  ~GroupServiceConnectionImpl() override = default;

  GroupServiceConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<monitoring_internal::GroupServiceStub> stub,
      Options options);

  Options options() override { return options_; }

  StreamRange<google::monitoring::v3::Group> ListGroups(
      google::monitoring::v3::ListGroupsRequest request) override;

  StatusOr<google::monitoring::v3::Group> GetGroup(
      google::monitoring::v3::GetGroupRequest const& request) override;

  StatusOr<google::monitoring::v3::Group> CreateGroup(
      google::monitoring::v3::CreateGroupRequest const& request) override;

  StatusOr<google::monitoring::v3::Group> UpdateGroup(
      google::monitoring::v3::UpdateGroupRequest const& request) override;

  Status DeleteGroup(
      google::monitoring::v3::DeleteGroupRequest const& request) override;

  StreamRange<google::api::MonitoredResource> ListGroupMembers(
      google::monitoring::v3::ListGroupMembersRequest request) override;

 private:
  std::unique_ptr<monitoring::GroupServiceRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<monitoring::GroupServiceRetryPolicyOption>()) {
      return options.get<monitoring::GroupServiceRetryPolicyOption>()->clone();
    }
    return options_.get<monitoring::GroupServiceRetryPolicyOption>()->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<monitoring::GroupServiceBackoffPolicyOption>()) {
      return options.get<monitoring::GroupServiceBackoffPolicyOption>()
          ->clone();
    }
    return options_.get<monitoring::GroupServiceBackoffPolicyOption>()->clone();
  }

  std::unique_ptr<monitoring::GroupServiceConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options
            .has<monitoring::GroupServiceConnectionIdempotencyPolicyOption>()) {
      return options
          .get<monitoring::GroupServiceConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return options_
        .get<monitoring::GroupServiceConnectionIdempotencyPolicyOption>()
        ->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<monitoring_internal::GroupServiceStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_MONITORING_INTERNAL_GROUP_CONNECTION_IMPL_H
