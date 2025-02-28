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
// source: google/cloud/dataplex/v1/metadata.proto

#include "google/cloud/dataplex/internal/metadata_connection_impl.h"
#include "google/cloud/dataplex/internal/metadata_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace dataplex_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

MetadataServiceConnectionImpl::MetadataServiceConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<dataplex_internal::MetadataServiceStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(std::move(options),
                                      MetadataServiceConnection::options())) {}

StatusOr<google::cloud::dataplex::v1::Entity>
MetadataServiceConnectionImpl::CreateEntity(
    google::cloud::dataplex::v1::CreateEntityRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateEntity(request),
      [this](grpc::ClientContext& context,
             google::cloud::dataplex::v1::CreateEntityRequest const& request) {
        return stub_->CreateEntity(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dataplex::v1::Entity>
MetadataServiceConnectionImpl::UpdateEntity(
    google::cloud::dataplex::v1::UpdateEntityRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateEntity(request),
      [this](grpc::ClientContext& context,
             google::cloud::dataplex::v1::UpdateEntityRequest const& request) {
        return stub_->UpdateEntity(context, request);
      },
      request, __func__);
}

Status MetadataServiceConnectionImpl::DeleteEntity(
    google::cloud::dataplex::v1::DeleteEntityRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteEntity(request),
      [this](grpc::ClientContext& context,
             google::cloud::dataplex::v1::DeleteEntityRequest const& request) {
        return stub_->DeleteEntity(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dataplex::v1::Entity>
MetadataServiceConnectionImpl::GetEntity(
    google::cloud::dataplex::v1::GetEntityRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetEntity(request),
      [this](grpc::ClientContext& context,
             google::cloud::dataplex::v1::GetEntityRequest const& request) {
        return stub_->GetEntity(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::dataplex::v1::Entity>
MetadataServiceConnectionImpl::ListEntities(
    google::cloud::dataplex::v1::ListEntitiesRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry = std::shared_ptr<dataplex::MetadataServiceRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListEntities(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::dataplex::v1::Entity>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::dataplex::v1::ListEntitiesRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::dataplex::v1::ListEntitiesRequest const&
                       request) {
              return stub->ListEntities(context, request);
            },
            r, function_name);
      },
      [](google::cloud::dataplex::v1::ListEntitiesResponse r) {
        std::vector<google::cloud::dataplex::v1::Entity> result(
            r.entities().size());
        auto& messages = *r.mutable_entities();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::dataplex::v1::Partition>
MetadataServiceConnectionImpl::CreatePartition(
    google::cloud::dataplex::v1::CreatePartitionRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreatePartition(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::dataplex::v1::CreatePartitionRequest const& request) {
        return stub_->CreatePartition(context, request);
      },
      request, __func__);
}

Status MetadataServiceConnectionImpl::DeletePartition(
    google::cloud::dataplex::v1::DeletePartitionRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeletePartition(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::dataplex::v1::DeletePartitionRequest const& request) {
        return stub_->DeletePartition(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dataplex::v1::Partition>
MetadataServiceConnectionImpl::GetPartition(
    google::cloud::dataplex::v1::GetPartitionRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->GetPartition(request),
      [this](grpc::ClientContext& context,
             google::cloud::dataplex::v1::GetPartitionRequest const& request) {
        return stub_->GetPartition(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::dataplex::v1::Partition>
MetadataServiceConnectionImpl::ListPartitions(
    google::cloud::dataplex::v1::ListPartitionsRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry = std::shared_ptr<dataplex::MetadataServiceRetryPolicy const>(
      retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListPartitions(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::dataplex::v1::Partition>>(
      std::move(request),
      [stub, retry, backoff, idempotency, function_name](
          google::cloud::dataplex::v1::ListPartitionsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](grpc::ClientContext& context,
                   google::cloud::dataplex::v1::ListPartitionsRequest const&
                       request) {
              return stub->ListPartitions(context, request);
            },
            r, function_name);
      },
      [](google::cloud::dataplex::v1::ListPartitionsResponse r) {
        std::vector<google::cloud::dataplex::v1::Partition> result(
            r.partitions().size());
        auto& messages = *r.mutable_partitions();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataplex_internal
}  // namespace cloud
}  // namespace google
