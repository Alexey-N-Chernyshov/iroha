/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef IROHA_BLOCK_STORAGE_FACTORY_HPP
#define IROHA_BLOCK_STORAGE_FACTORY_HPP

#include <memory>

#include "ametsuchi/block_storage.hpp"

namespace iroha {
  namespace ametsuchi {
    /**
     * Creates a block storage
     */
    class BlockStorageFactory {
     public:
      virtual std::unique_ptr<BlockStorage> create() = 0;

      virtual ~BlockStorageFactory() = default;
    };

  }  // namespace ametsuchi
}  // namespace iroha

#endif  // IROHA_BLOCK_STORAGE_FACTORY_HPP
