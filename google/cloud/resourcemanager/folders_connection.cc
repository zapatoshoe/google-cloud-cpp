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
// source: google/cloud/resourcemanager/v3/folders.proto

#include "google/cloud/resourcemanager/folders_connection.h"
#include "google/cloud/resourcemanager/folders_options.h"
#include "google/cloud/resourcemanager/internal/folders_connection_impl.h"
#include "google/cloud/resourcemanager/internal/folders_option_defaults.h"
#include "google/cloud/resourcemanager/internal/folders_stub_factory.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace resourcemanager {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

FoldersConnection::~FoldersConnection() = default;

StatusOr<google::cloud::resourcemanager::v3::Folder>
FoldersConnection::GetFolder(
    google::cloud::resourcemanager::v3::GetFolderRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::resourcemanager::v3::Folder>
FoldersConnection::ListFolders(
    google::cloud::resourcemanager::v3::
        ListFoldersRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::resourcemanager::v3::Folder>>();
}

StreamRange<google::cloud::resourcemanager::v3::Folder>
FoldersConnection::SearchFolders(
    google::cloud::resourcemanager::v3::
        SearchFoldersRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::resourcemanager::v3::Folder>>();
}

future<StatusOr<google::cloud::resourcemanager::v3::Folder>>
FoldersConnection::CreateFolder(
    google::cloud::resourcemanager::v3::CreateFolderRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::resourcemanager::v3::Folder>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::resourcemanager::v3::Folder>>
FoldersConnection::UpdateFolder(
    google::cloud::resourcemanager::v3::UpdateFolderRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::resourcemanager::v3::Folder>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::resourcemanager::v3::Folder>>
FoldersConnection::MoveFolder(
    google::cloud::resourcemanager::v3::MoveFolderRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::resourcemanager::v3::Folder>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::resourcemanager::v3::Folder>>
FoldersConnection::DeleteFolder(
    google::cloud::resourcemanager::v3::DeleteFolderRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::resourcemanager::v3::Folder>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

future<StatusOr<google::cloud::resourcemanager::v3::Folder>>
FoldersConnection::UndeleteFolder(
    google::cloud::resourcemanager::v3::UndeleteFolderRequest const&) {
  return google::cloud::make_ready_future<
      StatusOr<google::cloud::resourcemanager::v3::Folder>>(
      Status(StatusCode::kUnimplemented, "not implemented"));
}

StatusOr<google::iam::v1::Policy> FoldersConnection::GetIamPolicy(
    google::iam::v1::GetIamPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::iam::v1::Policy> FoldersConnection::SetIamPolicy(
    google::iam::v1::SetIamPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
FoldersConnection::TestIamPermissions(
    google::iam::v1::TestIamPermissionsRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<FoldersConnection> MakeFoldersConnection(Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 FoldersPolicyOptionList>(options, __func__);
  options = resourcemanager_internal::FoldersDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = resourcemanager_internal::CreateDefaultFoldersStub(
      background->cq(), options);
  return std::make_shared<resourcemanager_internal::FoldersConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace resourcemanager
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace resourcemanager_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<resourcemanager::FoldersConnection> MakeFoldersConnection(
    std::shared_ptr<FoldersStub> stub, Options options) {
  options = FoldersDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<resourcemanager_internal::FoldersConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace resourcemanager_internal
}  // namespace cloud
}  // namespace google
