/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "mlir/IR/OperationSupport.h"  // from @llvm-project
#include "mlir/Pass/Pass.h"  // from @llvm-project
#include "tensorflow/compiler/mlir/lite/ir/tfl_ops.h"

namespace mlir {
#include "tensorflow/compiler/mlir/lite/ir/tfl_ops_interface.h.inc"
namespace TFL {
namespace {

// This pass verifies that the TFL ops meet the TFL runtime constraints.
class RuntimeVerifyPass
    : public mlir::PassWrapper<RuntimeVerifyPass, OperationPass<FuncOp>> {
 public:
  MLIR_DEFINE_EXPLICIT_INTERNAL_INLINE_TYPE_ID(RuntimeVerifyPass)

  explicit RuntimeVerifyPass() {}

  StringRef getArgument() const final {
    // This is the argument used to refer to the pass in
    // the textual format (on the commandline for example).
    return "tfl-runtime-verify";
  }
  StringRef getDescription() const final {
    // This is a brief description of the pass.
    return "TFLite runtime verification";
  }

 private:
  void runOnOperation() override;
};

void RuntimeVerifyPass::runOnOperation() {
  getOperation().walk([&](TflRuntimeVerifyOpInterface op) {
    if (failed(op.VerifyTflRuntimeConstraints(
            op.getOperation(), /*emit_error_on_verify_fail=*/true)))
      signalPassFailure();
  });
}
}  // namespace

// Verifies TFL runtime constraints.
std::unique_ptr<OperationPass<FuncOp>> CreateRuntimeVerifyPass() {
  return std::make_unique<RuntimeVerifyPass>();
}

static PassRegistration<RuntimeVerifyPass> pass;

}  // namespace TFL
}  // namespace mlir
