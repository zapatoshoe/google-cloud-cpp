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
// source: google/cloud/dataproc/v1/workflow_templates.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPROC_WORKFLOW_TEMPLATE_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPROC_WORKFLOW_TEMPLATE_CONNECTION_H

#include "google/cloud/dataproc/internal/workflow_template_retry_traits.h"
#include "google/cloud/dataproc/internal/workflow_template_stub.h"
#include "google/cloud/dataproc/workflow_template_connection_idempotency_policy.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/future.h"
#include "google/cloud/options.h"
#include "google/cloud/polling_policy.h"
#include "google/cloud/status_or.h"
#include "google/cloud/stream_range.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace dataproc {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using WorkflowTemplateServiceRetryPolicy =
    ::google::cloud::internal::TraitBasedRetryPolicy<
        dataproc_internal::WorkflowTemplateServiceRetryTraits>;

using WorkflowTemplateServiceLimitedTimeRetryPolicy =
    ::google::cloud::internal::LimitedTimeRetryPolicy<
        dataproc_internal::WorkflowTemplateServiceRetryTraits>;

using WorkflowTemplateServiceLimitedErrorCountRetryPolicy =
    ::google::cloud::internal::LimitedErrorCountRetryPolicy<
        dataproc_internal::WorkflowTemplateServiceRetryTraits>;

/**
 * The `WorkflowTemplateServiceConnection` object for
 * `WorkflowTemplateServiceClient`.
 *
 * This interface defines virtual methods for each of the user-facing overload
 * sets in `WorkflowTemplateServiceClient`. This allows users to inject custom
 * behavior (e.g., with a Google Mock object) when writing tests that use
 * objects of type `WorkflowTemplateServiceClient`.
 *
 * To create a concrete instance, see `MakeWorkflowTemplateServiceConnection()`.
 *
 * For mocking, see `dataproc_mocks::MockWorkflowTemplateServiceConnection`.
 */
class WorkflowTemplateServiceConnection {
 public:
  virtual ~WorkflowTemplateServiceConnection() = 0;

  virtual Options options() { return Options{}; }

  virtual StatusOr<google::cloud::dataproc::v1::WorkflowTemplate>
  CreateWorkflowTemplate(
      google::cloud::dataproc::v1::CreateWorkflowTemplateRequest const&
          request);

  virtual StatusOr<google::cloud::dataproc::v1::WorkflowTemplate>
  GetWorkflowTemplate(
      google::cloud::dataproc::v1::GetWorkflowTemplateRequest const& request);

  virtual future<StatusOr<google::cloud::dataproc::v1::WorkflowMetadata>>
  InstantiateWorkflowTemplate(
      google::cloud::dataproc::v1::InstantiateWorkflowTemplateRequest const&
          request);

  virtual future<StatusOr<google::cloud::dataproc::v1::WorkflowMetadata>>
  InstantiateInlineWorkflowTemplate(
      google::cloud::dataproc::v1::
          InstantiateInlineWorkflowTemplateRequest const& request);

  virtual StatusOr<google::cloud::dataproc::v1::WorkflowTemplate>
  UpdateWorkflowTemplate(
      google::cloud::dataproc::v1::UpdateWorkflowTemplateRequest const&
          request);

  virtual StreamRange<google::cloud::dataproc::v1::WorkflowTemplate>
  ListWorkflowTemplates(
      google::cloud::dataproc::v1::ListWorkflowTemplatesRequest request);

  virtual Status DeleteWorkflowTemplate(
      google::cloud::dataproc::v1::DeleteWorkflowTemplateRequest const&
          request);
};

/**
 * A factory function to construct an object of type
 * `WorkflowTemplateServiceConnection`.
 *
 * The returned connection object should not be used directly; instead it
 * should be passed as an argument to the constructor of
 * WorkflowTemplateServiceClient.
 *
 * The optional @p options argument may be used to configure aspects of the
 * returned `WorkflowTemplateServiceConnection`. Expected options are any of the
 * types in the following option lists:
 *
 * - `google::cloud::CommonOptionList`
 * - `google::cloud::GrpcOptionList`
 * - `google::cloud::UnifiedCredentialsOptionList`
 * - `google::cloud::dataproc::WorkflowTemplateServicePolicyOptionList`
 *
 * @note Unexpected options will be ignored. To log unexpected options instead,
 *     set `GOOGLE_CLOUD_CPP_ENABLE_CLOG=yes` in the environment.
 *
 * @param location Sets the prefix for the default `EndpointOption` value.
 * @param options (optional) Configure the `WorkflowTemplateServiceConnection`
 * created by this function.
 */
std::shared_ptr<WorkflowTemplateServiceConnection>
MakeWorkflowTemplateServiceConnection(std::string const& location,
                                      Options options = {});

/**
 * A backwards-compatible version of the previous factory function.  Unless
 * the service also offers a global endpoint, the default value of the
 * `EndpointOption` may be useless, in which case it must be overridden.
 *
 * @deprecated Please use the `location` overload instead.
 */
std::shared_ptr<WorkflowTemplateServiceConnection>
MakeWorkflowTemplateServiceConnection(Options options = {});

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataproc
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DATAPROC_WORKFLOW_TEMPLATE_CONNECTION_H
