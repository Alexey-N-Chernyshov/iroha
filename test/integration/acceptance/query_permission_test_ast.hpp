/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef QUERY_PERMISSION_TEST_AST_HPP_
#define QUERY_PERMISSION_TEST_AST_HPP_

#include "backend/protobuf/common_objects/account_asset.hpp"
#include "integration/acceptance/query_permission_test_base.hpp"

using namespace shared_model;
using namespace integration_framework;
using namespace shared_model::interface::permissions;

class QueryPermissionAssets final : public QueryPermissionTestBase {
 public:
  QueryPermissionAssets();

  /**
   * Prepare state of ledger:
   * - create accounts of target user, close and remote spectators (close
   *   spectator - another user from the same domain as the domain of target
   *   user account, remote - a user from domain different to domain of target
   *   user account).
   * - create some assets
   * - execute transfers of assets from admin to target account
   *
   * @param spectator_permissions - set of query permisisons for target user's
   * and spectators' accounts
   * @return reference to ITF
   */
  IntegrationTestFramework &prepareState(
      AcceptanceFixture &fixture,
      const interface::RolePermissionSet &spectator_permissions);

  shared_model::proto::Query makeQuery(
      AcceptanceFixture &fixture,
      const interface::types::AccountIdType &target,
      const interface::types::AccountIdType &spectator,
      const crypto::Keypair &spectator_keypair) override;

  /**
   * @return a functor that verifies that query response contains all the hashes
   * of transactions related to the tested pair of account id and asset id
   */
  std::function<void(const proto::QueryResponse &response)>
  getGeneralResponseChecker() override;

  std::vector<std::pair<shared_model::interface::types::AssetIdType,
                        shared_model::interface::Amount>>
      account_assets_;
};

#endif /* QUERY_PERMISSION_TEST_AST_HPP_ */
