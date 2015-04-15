#pragma once
#ifndef BLOCKSTORE_IMPLEMENTATIONS_ENCRYPTED_ENCRYPTEDBLOCK_H_
#define BLOCKSTORE_IMPLEMENTATIONS_ENCRYPTED_ENCRYPTEDBLOCK_H_

#include "../../interface/Block.h"

#include "messmer/cpp-utils/macros.h"
#include <memory>

namespace blockstore {
namespace caching2 {
class Caching2BlockStore;

class CachedBlock: public Block {
public:
  //TODO Storing key twice (in parent class and in object pointed to). Once would be enough.
  CachedBlock(std::unique_ptr<Block> baseBlock, Caching2BlockStore *blockStore);
  virtual ~CachedBlock();

  const void *data() const override;
  void write(const void *source, uint64_t offset, uint64_t size) override;
  void flush() override;

  size_t size() const override;

private:
  Caching2BlockStore *_blockStore;
  std::unique_ptr<Block> _baseBlock;

  DISALLOW_COPY_AND_ASSIGN(CachedBlock);
};

}
}

#endif