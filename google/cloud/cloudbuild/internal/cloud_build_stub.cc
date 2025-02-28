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
// source: google/devtools/cloudbuild/v1/cloudbuild.proto

#include "google/cloud/cloudbuild/internal/cloud_build_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/devtools/cloudbuild/v1/cloudbuild.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace cloudbuild_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudBuildStub::~CloudBuildStub() = default;

future<StatusOr<google::longrunning::Operation>>
DefaultCloudBuildStub::AsyncCreateBuild(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::devtools::cloudbuild::v1::CreateBuildRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](
          grpc::ClientContext* context,
          google::devtools::cloudbuild::v1::CreateBuildRequest const& request,
          grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCreateBuild(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::devtools::cloudbuild::v1::Build>
DefaultCloudBuildStub::GetBuild(
    grpc::ClientContext& client_context,
    google::devtools::cloudbuild::v1::GetBuildRequest const& request) {
  google::devtools::cloudbuild::v1::Build response;
  auto status = grpc_stub_->GetBuild(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::devtools::cloudbuild::v1::ListBuildsResponse>
DefaultCloudBuildStub::ListBuilds(
    grpc::ClientContext& client_context,
    google::devtools::cloudbuild::v1::ListBuildsRequest const& request) {
  google::devtools::cloudbuild::v1::ListBuildsResponse response;
  auto status = grpc_stub_->ListBuilds(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::devtools::cloudbuild::v1::Build>
DefaultCloudBuildStub::CancelBuild(
    grpc::ClientContext& client_context,
    google::devtools::cloudbuild::v1::CancelBuildRequest const& request) {
  google::devtools::cloudbuild::v1::Build response;
  auto status = grpc_stub_->CancelBuild(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudBuildStub::AsyncRetryBuild(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::devtools::cloudbuild::v1::RetryBuildRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::devtools::cloudbuild::v1::RetryBuildRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncRetryBuild(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudBuildStub::AsyncApproveBuild(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::devtools::cloudbuild::v1::ApproveBuildRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](
          grpc::ClientContext* context,
          google::devtools::cloudbuild::v1::ApproveBuildRequest const& request,
          grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncApproveBuild(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::devtools::cloudbuild::v1::BuildTrigger>
DefaultCloudBuildStub::CreateBuildTrigger(
    grpc::ClientContext& client_context,
    google::devtools::cloudbuild::v1::CreateBuildTriggerRequest const&
        request) {
  google::devtools::cloudbuild::v1::BuildTrigger response;
  auto status =
      grpc_stub_->CreateBuildTrigger(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::devtools::cloudbuild::v1::BuildTrigger>
DefaultCloudBuildStub::GetBuildTrigger(
    grpc::ClientContext& client_context,
    google::devtools::cloudbuild::v1::GetBuildTriggerRequest const& request) {
  google::devtools::cloudbuild::v1::BuildTrigger response;
  auto status =
      grpc_stub_->GetBuildTrigger(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::devtools::cloudbuild::v1::ListBuildTriggersResponse>
DefaultCloudBuildStub::ListBuildTriggers(
    grpc::ClientContext& client_context,
    google::devtools::cloudbuild::v1::ListBuildTriggersRequest const& request) {
  google::devtools::cloudbuild::v1::ListBuildTriggersResponse response;
  auto status =
      grpc_stub_->ListBuildTriggers(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

Status DefaultCloudBuildStub::DeleteBuildTrigger(
    grpc::ClientContext& client_context,
    google::devtools::cloudbuild::v1::DeleteBuildTriggerRequest const&
        request) {
  google::protobuf::Empty response;
  auto status =
      grpc_stub_->DeleteBuildTrigger(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

StatusOr<google::devtools::cloudbuild::v1::BuildTrigger>
DefaultCloudBuildStub::UpdateBuildTrigger(
    grpc::ClientContext& client_context,
    google::devtools::cloudbuild::v1::UpdateBuildTriggerRequest const&
        request) {
  google::devtools::cloudbuild::v1::BuildTrigger response;
  auto status =
      grpc_stub_->UpdateBuildTrigger(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudBuildStub::AsyncRunBuildTrigger(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::devtools::cloudbuild::v1::RunBuildTriggerRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::devtools::cloudbuild::v1::RunBuildTriggerRequest const&
                 request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncRunBuildTrigger(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::devtools::cloudbuild::v1::ReceiveTriggerWebhookResponse>
DefaultCloudBuildStub::ReceiveTriggerWebhook(
    grpc::ClientContext& client_context,
    google::devtools::cloudbuild::v1::ReceiveTriggerWebhookRequest const&
        request) {
  google::devtools::cloudbuild::v1::ReceiveTriggerWebhookResponse response;
  auto status =
      grpc_stub_->ReceiveTriggerWebhook(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudBuildStub::AsyncCreateWorkerPool(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::devtools::cloudbuild::v1::CreateWorkerPoolRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::devtools::cloudbuild::v1::CreateWorkerPoolRequest const&
                 request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCreateWorkerPool(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::devtools::cloudbuild::v1::WorkerPool>
DefaultCloudBuildStub::GetWorkerPool(
    grpc::ClientContext& client_context,
    google::devtools::cloudbuild::v1::GetWorkerPoolRequest const& request) {
  google::devtools::cloudbuild::v1::WorkerPool response;
  auto status = grpc_stub_->GetWorkerPool(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudBuildStub::AsyncDeleteWorkerPool(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::devtools::cloudbuild::v1::DeleteWorkerPoolRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::devtools::cloudbuild::v1::DeleteWorkerPoolRequest const&
                 request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncDeleteWorkerPool(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudBuildStub::AsyncUpdateWorkerPool(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::devtools::cloudbuild::v1::UpdateWorkerPoolRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::devtools::cloudbuild::v1::UpdateWorkerPoolRequest const&
                 request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncUpdateWorkerPool(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::devtools::cloudbuild::v1::ListWorkerPoolsResponse>
DefaultCloudBuildStub::ListWorkerPools(
    grpc::ClientContext& client_context,
    google::devtools::cloudbuild::v1::ListWorkerPoolsRequest const& request) {
  google::devtools::cloudbuild::v1::ListWorkerPoolsResponse response;
  auto status =
      grpc_stub_->ListWorkerPools(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudBuildStub::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::longrunning::GetOperationRequest const& request,
             grpc::CompletionQueue* cq) {
        return operations_->AsyncGetOperation(context, request, cq);
      },
      request, std::move(context));
}

future<Status> DefaultCloudBuildStub::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return cq
      .MakeUnaryRpc(
          [this](grpc::ClientContext* context,
                 google::longrunning::CancelOperationRequest const& request,
                 grpc::CompletionQueue* cq) {
            return operations_->AsyncCancelOperation(context, request, cq);
          },
          request, std::move(context))
      .then([](future<StatusOr<google::protobuf::Empty>> f) {
        return f.get().status();
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace cloudbuild_internal
}  // namespace cloud
}  // namespace google
