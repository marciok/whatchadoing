#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/IR/IRBuilder.h"

using namespace llvm;

namespace {
  struct WhatchaDoinPass : public FunctionPass {
    static char ID;
    WhatchaDoinPass() : FunctionPass(ID) {}
    
    virtual bool runOnFunction(Function &F) {
      int len = F.getName().str().length();

      if (len <= 2) {
        errs() << "⚠️ WHATCHADOIN? The function `" << F.getName() << "` is too terse.\n";
      } else if (len >= 25){
        errs() << "⚠️ WHATCHADOIN? The function `" << F.getName() << "` is too long.\n";
      }

      return false;
    }
  };
}

char WhatchaDoinPass::ID = 0;

static void registerWhatchaDoinPass(const PassManagerBuilder &, legacy::PassManagerBase &PM){
  PM.add(new WhatchaDoinPass());
}

static RegisterStandardPasses RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible, registerWhatchaDoinPass);
