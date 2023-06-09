/* Copyright 2016 Google Inc. All Rights Reserved.

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

// Features that operate on Sentence objects. Most features are defined
// in this header so they may be re-used via composition into other more
// advanced feature classes.

#ifndef SENTENCE_FEATURES_H_
#define SENTENCE_FEATURES_H_

#include "feature_extractor.h"
#include "cld_3/protos/sentence.pb.h"

namespace chrome_lang_id {

// Feature function that extracts features for the full Sentence.
using WholeSentenceFeature = FeatureFunction<Sentence>;

using WholeSentenceExtractor = FeatureExtractor<Sentence>;

// Declare registry for the whole Sentence feature functions.  This is required
// for clang's -Wundefined-var-template.  However, MSVC has a bug which treats
// this declaration as a definition, leading to multiple definition errors, so
// omit this on MSVC.
#if !defined(_MSC_VER)
template <>
WholeSentenceFeature::Registry
    *RegisterableClass<WholeSentenceFeature>::registry_;
#endif

}  // namespace chrome_lang_id

#endif  // SENTENCE_FEATURES_H_
