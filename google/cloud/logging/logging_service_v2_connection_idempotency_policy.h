// Copyright 2021 Google LLC
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
// source: google/logging/v2/logging.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LOGGING_LOGGING_SERVICE_V2_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LOGGING_LOGGING_SERVICE_V2_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/logging/v2/logging.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace logging {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class LoggingServiceV2ConnectionIdempotencyPolicy {
 public:
  virtual ~LoggingServiceV2ConnectionIdempotencyPolicy();

  /// Create a new copy of this object.
  virtual std::unique_ptr<LoggingServiceV2ConnectionIdempotencyPolicy> clone()
      const;

  virtual google::cloud::Idempotency DeleteLog(
      google::logging::v2::DeleteLogRequest const& request);

  virtual google::cloud::Idempotency WriteLogEntries(
      google::logging::v2::WriteLogEntriesRequest const& request);

  virtual google::cloud::Idempotency ListLogEntries(
      google::logging::v2::ListLogEntriesRequest request);

  virtual google::cloud::Idempotency ListMonitoredResourceDescriptors(
      google::logging::v2::ListMonitoredResourceDescriptorsRequest request);

  virtual google::cloud::Idempotency ListLogs(
      google::logging::v2::ListLogsRequest request);
};

std::unique_ptr<LoggingServiceV2ConnectionIdempotencyPolicy>
MakeDefaultLoggingServiceV2ConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace logging
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_LOGGING_LOGGING_SERVICE_V2_CONNECTION_IDEMPOTENCY_POLICY_H
