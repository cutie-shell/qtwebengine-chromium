// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/core/editing/visible_units.h"

#include "third_party/blink/renderer/core/editing/selection_template.h"
#include "third_party/blink/renderer/core/editing/testing/editing_test_base.h"
#include "third_party/blink/renderer/core/editing/visible_position.h"
#include "third_party/blink/renderer/platform/testing/runtime_enabled_features_test_helpers.h"

namespace blink {

class VisibleUnitsWordTest : public EditingTestBase {
 protected:
  std::string DoStartOfWord(
      const std::string& selection_text,
      WordSide word_side = WordSide::kNextWordIfOnBoundary) {
    const Position position = SetSelectionTextToBody(selection_text).Base();
    return GetCaretTextFromBody(StartOfWordPosition(position, word_side));
  }

  std::string DoEndOfWord(
      const std::string& selection_text,
      WordSide word_side = WordSide::kNextWordIfOnBoundary) {
    const Position position = SetSelectionTextToBody(selection_text).Base();
    return GetCaretTextFromBody(EndOfWordPosition(position, word_side));
  }

  std::string DoNextWord(const std::string& selection_text) {
    const Position position = SetSelectionTextToBody(selection_text).Base();
    const PlatformWordBehavior platform_word_behavior =
        PlatformWordBehavior::kWordDontSkipSpaces;
    return GetCaretTextFromBody(
        CreateVisiblePosition(
            NextWordPosition(position, platform_word_behavior))
            .DeepEquivalent());
  }

  std::string DoNextWordSkippingSpaces(const std::string& selection_text) {
    const Position position = SetSelectionTextToBody(selection_text).Base();
    const PlatformWordBehavior platform_word_behavior =
        PlatformWordBehavior::kWordSkipSpaces;
    return GetCaretTextFromBody(
        CreateVisiblePosition(
            NextWordPosition(position, platform_word_behavior))
            .DeepEquivalent());
  }

  std::string DoPreviousWord(const std::string& selection_text) {
    const Position position = SetSelectionTextToBody(selection_text).Base();
    const Position result =
        CreateVisiblePosition(PreviousWordPosition(position)).DeepEquivalent();
    if (result.IsNull())
      return GetSelectionTextFromBody(SelectionInDOMTree());
    return GetCaretTextFromBody(result);
  }

  // To avoid name conflict in jumbo build, following functions should be here.
  static VisiblePosition CreateVisiblePositionInDOMTree(
      Node& anchor,
      int offset,
      TextAffinity affinity = TextAffinity::kDownstream) {
    return CreateVisiblePosition(Position(&anchor, offset), affinity);
  }

  static VisiblePositionInFlatTree CreateVisiblePositionInFlatTree(
      Node& anchor,
      int offset,
      TextAffinity affinity = TextAffinity::kDownstream) {
    return CreateVisiblePosition(PositionInFlatTree(&anchor, offset), affinity);
  }
};

class ParameterizedVisibleUnitsWordTest
    : public ::testing::WithParamInterface<bool>,
      private ScopedLayoutNGForTest,
      public VisibleUnitsWordTest {
 protected:
  ParameterizedVisibleUnitsWordTest() : ScopedLayoutNGForTest(GetParam()) {}

  bool LayoutNGEnabled() const {
    return RuntimeEnabledFeatures::LayoutNGEnabled();
  }
};

INSTANTIATE_TEST_SUITE_P(All,
                         ParameterizedVisibleUnitsWordTest,
                         ::testing::Bool());

TEST_P(ParameterizedVisibleUnitsWordTest, StartOfWordBasic) {
  EXPECT_EQ("<p> |(1) abc def</p>", DoStartOfWord("<p>| (1) abc def</p>"));
  EXPECT_EQ("<p> |(1) abc def</p>", DoStartOfWord("<p> |(1) abc def</p>"));
  EXPECT_EQ("<p> (|1) abc def</p>", DoStartOfWord("<p> (|1) abc def</p>"));
  EXPECT_EQ("<p> (1|) abc def</p>", DoStartOfWord("<p> (1|) abc def</p>"));
  EXPECT_EQ("<p> (1)| abc def</p>", DoStartOfWord("<p> (1)| abc def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>", DoStartOfWord("<p> (1) |abc def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>", DoStartOfWord("<p> (1) a|bc def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>", DoStartOfWord("<p> (1) ab|c def</p>"));
  EXPECT_EQ("<p> (1) abc| def</p>", DoStartOfWord("<p> (1) abc| def</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>", DoStartOfWord("<p> (1) abc |def</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>", DoStartOfWord("<p> (1) abc d|ef</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>", DoStartOfWord("<p> (1) abc de|f</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoStartOfWord("<p> (1) abc def|</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoStartOfWord("<p> (1) abc def</p>|"));
}

TEST_P(ParameterizedVisibleUnitsWordTest,
       StartOfWordPreviousWordIfOnBoundaryBasic) {
  EXPECT_EQ("<p> |(1) abc def</p>",
            DoStartOfWord("<p>| (1) abc def</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> |(1) abc def</p>",
            DoStartOfWord("<p> |(1) abc def</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> |(1) abc def</p>",
            DoStartOfWord("<p> (|1) abc def</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> (|1) abc def</p>",
            DoStartOfWord("<p> (1|) abc def</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> (1|) abc def</p>",
            DoStartOfWord("<p> (1)| abc def</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> (1)| abc def</p>",
            DoStartOfWord("<p> (1) |abc def</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> (1) |abc def</p>",
            DoStartOfWord("<p> (1) a|bc def</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> (1) |abc def</p>",
            DoStartOfWord("<p> (1) ab|c def</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> (1) |abc def</p>",
            DoStartOfWord("<p> (1) abc| def</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> (1) abc| def</p>",
            DoStartOfWord("<p> (1) abc |def</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> (1) abc |def</p>",
            DoStartOfWord("<p> (1) abc d|ef</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> (1) abc |def</p>",
            DoStartOfWord("<p> (1) abc de|f</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> (1) abc |def</p>",
            DoStartOfWord("<p> (1) abc def|</p>",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("<p> (1) abc |def</p>",
            DoStartOfWord("<p> (1) abc def</p>|",
                          WordSide::kPreviousWordIfOnBoundary));
}

TEST_P(ParameterizedVisibleUnitsWordTest, StartOfWordCrossing) {
  EXPECT_EQ("<b>|abc</b><i>def</i>", DoStartOfWord("<b>abc</b><i>|def</i>"));
  EXPECT_EQ("<b>abc</b><i>def|</i>", DoStartOfWord("<b>abc</b><i>def</i>|"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, StartOfWordFirstLetter) {
  InsertStyleElement("p::first-letter {font-size:200%;}");
  // Note: Expectations should match with |StartOfWordBasic|.
  EXPECT_EQ("<p> |(1) abc def</p>", DoStartOfWord("<p>| (1) abc def</p>"));
  EXPECT_EQ("<p> |(1) abc def</p>", DoStartOfWord("<p> |(1) abc def</p>"));
  EXPECT_EQ("<p> (|1) abc def</p>", DoStartOfWord("<p> (|1) abc def</p>"));
  EXPECT_EQ("<p> (1|) abc def</p>", DoStartOfWord("<p> (1|) abc def</p>"));
  EXPECT_EQ("<p> (1)| abc def</p>", DoStartOfWord("<p> (1)| abc def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>", DoStartOfWord("<p> (1) |abc def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>", DoStartOfWord("<p> (1) a|bc def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>", DoStartOfWord("<p> (1) ab|c def</p>"));
  EXPECT_EQ("<p> (1) abc| def</p>", DoStartOfWord("<p> (1) abc| def</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>", DoStartOfWord("<p> (1) abc |def</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>", DoStartOfWord("<p> (1) abc d|ef</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>", DoStartOfWord("<p> (1) abc de|f</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoStartOfWord("<p> (1) abc def|</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoStartOfWord("<p> (1) abc def</p>|"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, StartOfWordShadowDOM) {
  const char* body_content =
      "<span id=host><b slot='#one' id=one>1</b> <b slot='#two' "
      "id=two>22</b></span><i id=three>333</i>";
  const char* shadow_content =
      "<p><u id=four>44444</u><slot name=#two></slot><span id=space> "
      "</span><slot name=#one></slot><u id=five>55555</u></p>";
  SetBodyContent(body_content);
  ShadowRoot* shadow_root = SetShadowContent(shadow_content, "host");

  Node* one = GetDocument().getElementById("one")->firstChild();
  Node* two = GetDocument().getElementById("two")->firstChild();
  Node* three = GetDocument().getElementById("three")->firstChild();
  Node* four = shadow_root->getElementById("four")->firstChild();
  Node* five = shadow_root->getElementById("five")->firstChild();
  Node* space = shadow_root->getElementById("space")->firstChild();

  EXPECT_EQ(Position(one, 0),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInDOMTree(*one, 0).DeepEquivalent()))
                .DeepEquivalent());
  EXPECT_EQ(PositionInFlatTree(space, 1),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInFlatTree(*one, 0).DeepEquivalent()))
                .DeepEquivalent());
  EXPECT_EQ(Position(one, 0),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInDOMTree(*one, 1).DeepEquivalent()))
                .DeepEquivalent());

  EXPECT_EQ(PositionInFlatTree(space, 1),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInFlatTree(*one, 1).DeepEquivalent()))
                .DeepEquivalent());
  EXPECT_EQ(Position(four, 0),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInDOMTree(*two, 0).DeepEquivalent()))
                .DeepEquivalent());
  EXPECT_EQ(PositionInFlatTree(four, 0),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInFlatTree(*two, 0).DeepEquivalent()))
                .DeepEquivalent());
  EXPECT_EQ(Position(four, 0),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInDOMTree(*two, 1).DeepEquivalent()))
                .DeepEquivalent());
  EXPECT_EQ(PositionInFlatTree(four, 0),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInFlatTree(*two, 1).DeepEquivalent()))
                .DeepEquivalent());
  EXPECT_EQ(Position(three, 0),
            CreateVisiblePosition(
                StartOfWordPosition(CreateVisiblePositionInDOMTree(
                                        *three, 1, TextAffinity::kUpstream)
                                        .DeepEquivalent()))
                .DeepEquivalent());
  EXPECT_EQ(Position(three, 0),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInDOMTree(*three, 1).DeepEquivalent()))
                .DeepEquivalent());
  EXPECT_EQ(
      PositionInFlatTree(three, 0),
      CreateVisiblePosition(
          StartOfWordPosition(
              CreateVisiblePositionInFlatTree(*three, 1).DeepEquivalent()))
          .DeepEquivalent());
  EXPECT_EQ(Position(four, 0),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInDOMTree(*four, 1).DeepEquivalent()))
                .DeepEquivalent());
  EXPECT_EQ(PositionInFlatTree(four, 0),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInFlatTree(*four, 1).DeepEquivalent()))
                .DeepEquivalent());
  EXPECT_EQ(Position(one, 0),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInDOMTree(*five, 1).DeepEquivalent()))
                .DeepEquivalent());
  // Flat tree canonicalization moves result to downstream position
  EXPECT_EQ(PositionInFlatTree(space, 1),
            CreateVisiblePosition(
                StartOfWordPosition(
                    CreateVisiblePositionInFlatTree(*five, 1).DeepEquivalent()))
                .DeepEquivalent());
}

TEST_P(ParameterizedVisibleUnitsWordTest, StartOfWordTextSecurity) {
  // Note: |StartOfWordPosition()| considers security characters
  // as a sequence "x".
  InsertStyleElement("s {-webkit-text-security:disc;}");
  EXPECT_EQ("|abc<s>foo bar</s>baz", DoStartOfWord("|abc<s>foo bar</s>baz"));
  EXPECT_EQ("|abc<s>foo bar</s>baz", DoStartOfWord("abc|<s>foo bar</s>baz"));
  EXPECT_EQ("|abc<s>foo bar</s>baz", DoStartOfWord("abc<s>|foo bar</s>baz"));
  EXPECT_EQ("|abc<s>foo bar</s>baz", DoStartOfWord("abc<s>f|oo bar</s>baz"));
  EXPECT_EQ("|abc<s>foo bar</s>baz", DoStartOfWord("abc<s>foo| bar</s>baz"));
  EXPECT_EQ("|abc<s>foo bar</s>baz", DoStartOfWord("abc<s>foo |bar</s>baz"));
  EXPECT_EQ("|abc<s>foo bar</s>baz", DoStartOfWord("abc<s>foo bar|</s>baz"));
  EXPECT_EQ("|abc<s>foo bar</s>baz", DoStartOfWord("abc<s>foo bar</s>|baz"));
  EXPECT_EQ("|abc<s>foo bar</s>baz", DoStartOfWord("abc<s>foo bar</s>b|az"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, StartOfWordTextControl) {
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoStartOfWord("|foo<input value=\"bla\">bar"));
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoStartOfWord("f|oo<input value=\"bla\">bar"));
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoStartOfWord("fo|o<input value=\"bla\">bar"));
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoStartOfWord("foo|<input value=\"bla\">bar"));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoStartOfWord("foo<input value=\"bla\">|bar"));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoStartOfWord("foo<input value=\"bla\">b|ar"));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoStartOfWord("foo<input value=\"bla\">ba|r"));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoStartOfWord("foo<input value=\"bla\">bar|"));
}

TEST_P(ParameterizedVisibleUnitsWordTest,
       StartOfWordPreviousWordIfOnBoundaryTextControl) {
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoStartOfWord("|foo<input value=\"bla\">bar",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoStartOfWord("f|oo<input value=\"bla\">bar",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoStartOfWord("fo|o<input value=\"bla\">bar",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoStartOfWord("foo|<input value=\"bla\">bar",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoStartOfWord("foo<input value=\"bla\">|bar",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoStartOfWord("foo<input value=\"bla\">b|ar",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoStartOfWord("foo<input value=\"bla\">ba|r",
                          WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoStartOfWord("foo<input value=\"bla\">bar|",
                          WordSide::kPreviousWordIfOnBoundary));
}

TEST_P(ParameterizedVisibleUnitsWordTest, EndOfWordBasic) {
  EXPECT_EQ("<p> (|1) abc def</p>", DoEndOfWord("<p>| (1) abc def</p>"));
  EXPECT_EQ("<p> (|1) abc def</p>", DoEndOfWord("<p> |(1) abc def</p>"));
  EXPECT_EQ("<p> (1|) abc def</p>", DoEndOfWord("<p> (|1) abc def</p>"));
  EXPECT_EQ("<p> (1)| abc def</p>", DoEndOfWord("<p> (1|) abc def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>", DoEndOfWord("<p> (1)| abc def</p>"));
  EXPECT_EQ("<p> (1) abc| def</p>", DoEndOfWord("<p> (1) |abc def</p>"));
  EXPECT_EQ("<p> (1) abc| def</p>", DoEndOfWord("<p> (1) a|bc def</p>"));
  EXPECT_EQ("<p> (1) abc| def</p>", DoEndOfWord("<p> (1) ab|c def</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>", DoEndOfWord("<p> (1) abc| def</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoEndOfWord("<p> (1) abc |def</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoEndOfWord("<p> (1) abc d|ef</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoEndOfWord("<p> (1) abc de|f</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoEndOfWord("<p> (1) abc def|</p>"));
  EXPECT_EQ("<p> (1) abc def</p>|", DoEndOfWord("<p> (1) abc def</p>|"));
}

TEST_P(ParameterizedVisibleUnitsWordTest,
       EndOfWordPreviousWordIfOnBoundaryBasic) {
  EXPECT_EQ(
      "<p> |(1) abc def</p>",
      DoEndOfWord("<p>| (1) abc def</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> |(1) abc def</p>",
      DoEndOfWord("<p> |(1) abc def</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (|1) abc def</p>",
      DoEndOfWord("<p> (|1) abc def</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (1|) abc def</p>",
      DoEndOfWord("<p> (1|) abc def</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (1)| abc def</p>",
      DoEndOfWord("<p> (1)| abc def</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (1) |abc def</p>",
      DoEndOfWord("<p> (1) |abc def</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (1) abc| def</p>",
      DoEndOfWord("<p> (1) a|bc def</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (1) abc| def</p>",
      DoEndOfWord("<p> (1) ab|c def</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (1) abc| def</p>",
      DoEndOfWord("<p> (1) abc| def</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (1) abc |def</p>",
      DoEndOfWord("<p> (1) abc |def</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (1) abc def|</p>",
      DoEndOfWord("<p> (1) abc d|ef</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (1) abc def|</p>",
      DoEndOfWord("<p> (1) abc de|f</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (1) abc def|</p>",
      DoEndOfWord("<p> (1) abc def|</p>", WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ(
      "<p> (1) abc def</p>|",
      DoEndOfWord("<p> (1) abc def</p>|", WordSide::kPreviousWordIfOnBoundary));
}

TEST_P(ParameterizedVisibleUnitsWordTest, EndOfWordShadowDOM) {
  const char* body_content =
      "<span id=host><b slot='#one' id=one>1</b> <b slot='#two' "
      "id=two>22</b></span><i id=three>333</i>";
  const char* shadow_content =
      "<p><u id=four>44444</u><slot name=#two></slot><span id=space> "
      "</span><slot name=#one></slot><u id=five>55555</u></p>";
  SetBodyContent(body_content);
  ShadowRoot* shadow_root = SetShadowContent(shadow_content, "host");

  Node* one = GetDocument().getElementById("one")->firstChild();
  Node* two = GetDocument().getElementById("two")->firstChild();
  Node* three = GetDocument().getElementById("three")->firstChild();
  Node* four = shadow_root->getElementById("four")->firstChild();
  Node* five = shadow_root->getElementById("five")->firstChild();

  EXPECT_EQ(Position(five, 5), EndOfWordPosition(Position(*one, 0)));
  EXPECT_EQ(PositionInFlatTree(five, 5),
            EndOfWordPosition(PositionInFlatTree(*one, 0)));

  EXPECT_EQ(Position(five, 5), EndOfWordPosition(Position(*one, 1)));
  EXPECT_EQ(PositionInFlatTree(five, 5),
            EndOfWordPosition(PositionInFlatTree(*one, 1)));

  EXPECT_EQ(Position(two, 2), EndOfWordPosition(Position(*two, 0)));
  EXPECT_EQ(PositionInFlatTree(two, 2),
            EndOfWordPosition(PositionInFlatTree(*two, 0)));

  EXPECT_EQ(Position(two, 2), EndOfWordPosition(Position(*two, 1)));
  EXPECT_EQ(PositionInFlatTree(two, 2),
            EndOfWordPosition(PositionInFlatTree(*two, 1)));

  EXPECT_EQ(Position(three, 3), EndOfWordPosition(Position(*three, 1)));
  EXPECT_EQ(PositionInFlatTree(three, 3),
            EndOfWordPosition(PositionInFlatTree(*three, 1)));

  EXPECT_EQ(Position(two, 2), EndOfWordPosition(Position(*four, 1)));
  EXPECT_EQ(PositionInFlatTree(two, 2),
            EndOfWordPosition(PositionInFlatTree(*four, 1)));

  EXPECT_EQ(Position(five, 5), EndOfWordPosition(Position(*five, 1)));
  EXPECT_EQ(PositionInFlatTree(five, 5),
            EndOfWordPosition(PositionInFlatTree(*five, 1)));
}

TEST_P(ParameterizedVisibleUnitsWordTest, EndOfWordTextSecurity) {
  // Note: |EndOfWord()| considers security characters as a sequence "x".
  InsertStyleElement("s {-webkit-text-security:disc;}");
  EXPECT_EQ("abc<s>foo bar</s>baz|", DoEndOfWord("|abc<s>foo bar</s>baz"));
  EXPECT_EQ("abc<s>foo bar</s>baz|", DoEndOfWord("abc|<s>foo bar</s>baz"));
  EXPECT_EQ("abc<s>foo bar</s>baz|", DoEndOfWord("abc<s>|foo bar</s>baz"));
  EXPECT_EQ("abc<s>foo bar</s>baz|", DoEndOfWord("abc<s>f|oo bar</s>baz"));
  EXPECT_EQ("abc<s>foo bar</s>baz|", DoEndOfWord("abc<s>foo| bar</s>baz"));
  EXPECT_EQ("abc<s>foo bar</s>baz|", DoEndOfWord("abc<s>foo |bar</s>baz"));
  EXPECT_EQ("abc<s>foo bar</s>baz|", DoEndOfWord("abc<s>foo bar|</s>baz"));
  EXPECT_EQ("abc<s>foo bar</s>baz|", DoEndOfWord("abc<s>foo bar</s>|baz"));
  EXPECT_EQ("abc<s>foo bar</s>baz|", DoEndOfWord("abc<s>foo bar</s>b|az"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, EndOfWordTextControl) {
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoEndOfWord("|foo<input value=\"bla\">bar"));
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoEndOfWord("f|oo<input value=\"bla\">bar"));
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoEndOfWord("fo|o<input value=\"bla\">bar"));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoEndOfWord("foo|<input value=\"bla\">bar"));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoEndOfWord("foo<input value=\"bla\">|bar"));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoEndOfWord("foo<input value=\"bla\">b|ar"));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoEndOfWord("foo<input value=\"bla\">ba|r"));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoEndOfWord("foo<input value=\"bla\">bar|"));
}

TEST_P(ParameterizedVisibleUnitsWordTest,
       EndOfWordPreviousWordIfOnBoundaryTextControl) {
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoEndOfWord("|foo<input value=\"bla\">bar",
                        WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoEndOfWord("f|oo<input value=\"bla\">bar",
                        WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoEndOfWord("fo|o<input value=\"bla\">bar",
                        WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoEndOfWord("foo|<input value=\"bla\">bar",
                        WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoEndOfWord("foo<input value=\"bla\">|bar",
                        WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoEndOfWord("foo<input value=\"bla\">b|ar",
                        WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoEndOfWord("foo<input value=\"bla\">ba|r",
                        WordSide::kPreviousWordIfOnBoundary));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoEndOfWord("foo<input value=\"bla\">bar|",
                        WordSide::kPreviousWordIfOnBoundary));
}

TEST_P(ParameterizedVisibleUnitsWordTest, NextWordSkipSpacesBasic) {
  EXPECT_EQ("<p> (|1) abc def</p>",
            DoNextWordSkippingSpaces("<p>| (1) abc def</p>"));
  EXPECT_EQ("<p> (|1) abc def</p>",
            DoNextWordSkippingSpaces("<p> |(1) abc def</p>"));
  EXPECT_EQ("<p> (1|) abc def</p>",
            DoNextWordSkippingSpaces("<p> (|1) abc def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>",
            DoNextWordSkippingSpaces("<p> (1|) abc def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>",
            DoNextWordSkippingSpaces("<p> (1)| abc def</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>",
            DoNextWordSkippingSpaces("<p> (1) |abc def</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>",
            DoNextWordSkippingSpaces("<p> (1) a|bc def</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>",
            DoNextWordSkippingSpaces("<p> (1) ab|c def</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>",
            DoNextWordSkippingSpaces("<p> (1) abc| def</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>",
            DoNextWordSkippingSpaces("<p> (1) abc |def</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>",
            DoNextWordSkippingSpaces("<p> (1) abc d|ef</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>",
            DoNextWordSkippingSpaces("<p> (1) abc de|f</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>",
            DoNextWordSkippingSpaces("<p> (1) abc def|</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>",
            DoNextWordSkippingSpaces("<p> (1) abc def</p>|"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, NextWordBasic) {
  EXPECT_EQ("<p> (|1) abc def</p>", DoNextWord("<p>| (1) abc def</p>"));
  EXPECT_EQ("<p> (|1) abc def</p>", DoNextWord("<p> |(1) abc def</p>"));
  EXPECT_EQ("<p> (1|) abc def</p>", DoNextWord("<p> (|1) abc def</p>"));
  EXPECT_EQ("<p> (1)| abc def</p>", DoNextWord("<p> (1|) abc def</p>"));
  EXPECT_EQ("<p> (1) abc| def</p>", DoNextWord("<p> (1)| abc def</p>"));
  EXPECT_EQ("<p> (1) abc| def</p>", DoNextWord("<p> (1) |abc def</p>"));
  EXPECT_EQ("<p> (1) abc| def</p>", DoNextWord("<p> (1) a|bc def</p>"));
  EXPECT_EQ("<p> (1) abc| def</p>", DoNextWord("<p> (1) ab|c def</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoNextWord("<p> (1) abc| def</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoNextWord("<p> (1) abc |def</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoNextWord("<p> (1) abc d|ef</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoNextWord("<p> (1) abc de|f</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoNextWord("<p> (1) abc def|</p>"));
  EXPECT_EQ("<p> (1) abc def|</p>", DoNextWord("<p> (1) abc def</p>|"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, NextWordCrossingBlock) {
  EXPECT_EQ("<p>abc|</p><p>def</p>", DoNextWord("<p>|abc</p><p>def</p>"));
  EXPECT_EQ("<p>abc</p><p>|def</p>", DoNextWord("<p>abc|</p><p>def</p>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, NextWordCrossingPlaceholderBR) {
  EXPECT_EQ("<p><br></p><p>|abc</p>", DoNextWord("<p>|<br></p><p>abc</p>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, NextWordMixedEditability) {
  EXPECT_EQ(
      "<p contenteditable>"
      "abc<b contenteditable=\"false\">def ghi</b>|jkl mno</p>",
      DoNextWord("<p contenteditable>"
                 "|abc<b contenteditable=false>def ghi</b>jkl mno</p>"));
  EXPECT_EQ(
      "<p contenteditable>"
      "abc<b contenteditable=\"false\">def| ghi</b>jkl mno</p>",
      DoNextWord("<p contenteditable>"
                 "abc<b contenteditable=false>|def ghi</b>jkl mno</p>"));
  EXPECT_EQ(
      "<p contenteditable>"
      "abc<b contenteditable=\"false\">def ghi|</b>jkl mno</p>",
      DoNextWord("<p contenteditable>"
                 "abc<b contenteditable=false>def |ghi</b>jkl mno</p>"));
  EXPECT_EQ(
      "<p contenteditable>"
      "abc<b contenteditable=\"false\">def ghi|</b>jkl mno</p>",
      DoNextWord("<p contenteditable>"
                 "abc<b contenteditable=false>def ghi|</b>jkl mno</p>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, NextWordPunctuation) {
  EXPECT_EQ("abc|.def", DoNextWord("|abc.def"));
  EXPECT_EQ("abc|.def", DoNextWord("a|bc.def"));
  EXPECT_EQ("abc|.def", DoNextWord("ab|c.def"));
  EXPECT_EQ("abc.|def", DoNextWord("abc|.def"));
  EXPECT_EQ("abc.def|", DoNextWord("abc.|def"));

  EXPECT_EQ("abc|...def", DoNextWord("|abc...def"));
  EXPECT_EQ("abc|...def", DoNextWord("a|bc...def"));
  EXPECT_EQ("abc|...def", DoNextWord("ab|c...def"));
  EXPECT_EQ("abc...|def", DoNextWord("abc|...def"));
  EXPECT_EQ("abc...|def", DoNextWord("abc.|..def"));
  EXPECT_EQ("abc...|def", DoNextWord("abc..|.def"));
  EXPECT_EQ("abc...def|", DoNextWord("abc...|def"));

  EXPECT_EQ("abc| ((())) def", DoNextWord("|abc ((())) def"));
  EXPECT_EQ("abc ((()))| def", DoNextWord("abc |((())) def"));
  EXPECT_EQ("abc| 32.3 def", DoNextWord("|abc 32.3 def"));
  EXPECT_EQ("abc 32.3| def", DoNextWord("abc |32.3 def"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, NextWordSkipTab) {
  InsertStyleElement("s { white-space: pre }");
  EXPECT_EQ("<p><s>\t</s>foo|</p>", DoNextWord("<p><s>\t|</s>foo</p>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, NextWordSkipTextControl) {
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoNextWord("|foo<input value=\"bla\">bar"));
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoNextWord("f|oo<input value=\"bla\">bar"));
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoNextWord("fo|o<input value=\"bla\">bar"));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoNextWord("foo|<input value=\"bla\">bar"));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoNextWord("foo<input value=\"bla\">|bar"));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoNextWord("foo<input value=\"bla\">b|ar"));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoNextWord("foo<input value=\"bla\">ba|r"));
  EXPECT_EQ("foo<input value=\"bla\">bar|",
            DoNextWord("foo<input value=\"bla\">bar|"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, NextWordSkipSpacesEmoji) {
  EXPECT_EQ("<p> abc |😂 def</p>",
            DoNextWordSkippingSpaces("<p> |abc &#x1F602; def</p>"));
  EXPECT_EQ("<p> abc 😂 |def</p>",
            DoNextWordSkippingSpaces("<p> abc |&#x1F602; def</p>"));
  EXPECT_EQ("<p> abc 😂 def|</p>",
            DoNextWordSkippingSpaces("<p> abc &#x1F602; |def</p>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, NextWordEmoji) {
  EXPECT_EQ("<p> abc| 😂 def</p>", DoNextWord("<p> |abc &#x1F602; def</p>"));
  EXPECT_EQ("<p> abc 😂| def</p>", DoNextWord("<p> abc |&#x1F602; def</p>"));
  EXPECT_EQ("<p> abc 😂 def|</p>", DoNextWord("<p> abc &#x1F602; |def</p>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, NextWordEmojiSequence) {
  EXPECT_EQ("<p> abc| 😂😂 def</p>",
            DoNextWord("<p> |abc &#x1F602;&#x1F602; def</p>"));
  EXPECT_EQ("<p> abc 😂😂| def</p>",
            DoNextWord("<p> abc |&#x1F602;&#x1F602; def</p>"));
  EXPECT_EQ("<p> abc 😂😂 def|</p>",
            DoNextWord("<p> abc &#x1F602;&#x1F602; |def</p>"));
}

//----

TEST_P(ParameterizedVisibleUnitsWordTest, PreviousWordBasic) {
  EXPECT_EQ("<p> |(1) abc def</p>", DoPreviousWord("<p>| (1) abc def</p>"));
  EXPECT_EQ("<p> |(1) abc def</p>", DoPreviousWord("<p> |(1) abc def</p>"));
  EXPECT_EQ("<p> |(1) abc def</p>", DoPreviousWord("<p> (|1) abc def</p>"));
  EXPECT_EQ("<p> (|1) abc def</p>", DoPreviousWord("<p> (1|) abc def</p>"));
  EXPECT_EQ("<p> (1|) abc def</p>", DoPreviousWord("<p> (1)| abc def</p>"));
  EXPECT_EQ("<p> (1|) abc def</p>", DoPreviousWord("<p> (1) |abc def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>", DoPreviousWord("<p> (1) a|bc def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>", DoPreviousWord("<p> (1) ab|c def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>", DoPreviousWord("<p> (1) abc| def</p>"));
  EXPECT_EQ("<p> (1) |abc def</p>", DoPreviousWord("<p> (1) abc |def</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>", DoPreviousWord("<p> (1) abc d|ef</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>", DoPreviousWord("<p> (1) abc de|f</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>", DoPreviousWord("<p> (1) abc def|</p>"));
  EXPECT_EQ("<p> (1) abc |def</p>", DoPreviousWord("<p> (1) abc def</p>|"));
  EXPECT_EQ("<p> |abc ((())) def</p>",
            DoPreviousWord("<p> abc |((())) def</p>"));
  EXPECT_EQ("<p> abc |((())) def</p>",
            DoPreviousWord("<p> abc ((())) |def</p>"));
  EXPECT_EQ("<p> |abc 32.3 def</p>", DoPreviousWord("<p> abc |32.3 def</p>"));
  EXPECT_EQ("<p> abc |32.3 def</p>", DoPreviousWord("<p> abc 32.3 |def</p>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, PreviousWordCrossingBlock) {
  EXPECT_EQ("<p>abc|</p><p>def</p>", DoPreviousWord("<p>abc</p><p>|def</p>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, PreviousWordCrossingPlaceholderBR) {
  EXPECT_EQ("<p>|<br></p><p>abc</p>", DoPreviousWord("<p><br></p><p>|abc</p>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, PreviousWordInFloat) {
  InsertStyleElement(
      "c { display: block; float: right; }"
      "e { display: block; }");

  // To "|abc"
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>|abc def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>a|bc def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>ab|c def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>abc| def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>abc |def ghi</e></c>"));
  // To "|def"
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc d|ef ghi</e></c>"));
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc de|f ghi</e></c>"));
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc def| ghi</e></c>"));
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc def |ghi</e></c>"));
  // To "|ghi"
  EXPECT_EQ("<c><e>abc def |ghi</e></c>",
            DoPreviousWord("<c><e>abc def g|hi</e></c>"));
  EXPECT_EQ("<c><e>abc def |ghi</e></c>",
            DoPreviousWord("<c><e>abc def gh|i</e></c>"));
  EXPECT_EQ("<c><e>abc def |ghi</e></c>",
            DoPreviousWord("<c><e>abc def ghi|</e></c>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, PreviousWordInInlineBlock) {
  InsertStyleElement(
      "c { display: inline-block; }"
      "e { display: block; }");

  // To "|abc"
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>|abc def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>a|bc def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>ab|c def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>abc| def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>abc |def ghi</e></c>"));
  // To "|def"
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc d|ef ghi</e></c>"));
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc de|f ghi</e></c>"));
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc def| ghi</e></c>"));
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc def |ghi</e></c>"));
  // To "|ghi"
  EXPECT_EQ("<c><e>abc def |ghi</e></c>",
            DoPreviousWord("<c><e>abc def g|hi</e></c>"));
  EXPECT_EQ("<c><e>abc def |ghi</e></c>",
            DoPreviousWord("<c><e>abc def gh|i</e></c>"));
  EXPECT_EQ("<c><e>abc def |ghi</e></c>",
            DoPreviousWord("<c><e>abc def ghi|</e></c>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, PreviousWordInPositionAbsolute) {
  InsertStyleElement(
      "c { display: block; position: absolute; }"
      "e { display: block; }");

  // To "|abc"
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>|abc def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>a|bc def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>ab|c def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>abc| def ghi</e></c>"));
  EXPECT_EQ("<c><e>|abc def ghi</e></c>",
            DoPreviousWord("<c><e>abc |def ghi</e></c>"));
  // To "|def"
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc d|ef ghi</e></c>"));
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc de|f ghi</e></c>"));
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc def| ghi</e></c>"));
  EXPECT_EQ("<c><e>abc |def ghi</e></c>",
            DoPreviousWord("<c><e>abc def |ghi</e></c>"));
  // To "|ghi"
  EXPECT_EQ("<c><e>abc def |ghi</e></c>",
            DoPreviousWord("<c><e>abc def g|hi</e></c>"));
  EXPECT_EQ("<c><e>abc def |ghi</e></c>",
            DoPreviousWord("<c><e>abc def gh|i</e></c>"));
  EXPECT_EQ("<c><e>abc def |ghi</e></c>",
            DoPreviousWord("<c><e>abc def ghi|</e></c>"));
}

TEST_P(ParameterizedVisibleUnitsWordTest, PreviousWordSkipTextControl) {
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoPreviousWord("|foo<input value=\"bla\">bar"));
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoPreviousWord("f|oo<input value=\"bla\">bar"));
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoPreviousWord("fo|o<input value=\"bla\">bar"));
  EXPECT_EQ("|foo<input value=\"bla\">bar",
            DoPreviousWord("foo|<input value=\"bla\">bar"));
  EXPECT_EQ("foo|<input value=\"bla\">bar",
            DoPreviousWord("foo<input value=\"bla\">|bar"));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoPreviousWord("foo<input value=\"bla\">b|ar"));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoPreviousWord("foo<input value=\"bla\">ba|r"));
  EXPECT_EQ("foo<input value=\"bla\">|bar",
            DoPreviousWord("foo<input value=\"bla\">bar|"));
}

}  // namespace blink
