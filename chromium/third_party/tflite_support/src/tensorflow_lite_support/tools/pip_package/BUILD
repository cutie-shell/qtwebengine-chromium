# Description:
#  Tools for building the TensorFlow pip package.

load("@local_config_syslibs//:build_defs.bzl", "if_not_system_lib")

package(default_visibility = ["//visibility:private"])

COMMON_PIP_DEPS = [
    ":licenses",
    "MANIFEST.in",
    "README",
    "setup.py",
    "//tensorflow_lite_support/codegen/python:codegen",
    "//tensorflow_lite_support/metadata/python:metadata",
    "//tensorflow_lite_support/metadata/python/metadata_writers:writer_utils",
    "//tensorflow_lite_support/metadata/python/metadata_writers:metadata_info",
    "//tensorflow_lite_support/metadata/python/metadata_writers:image_classifier",
    "//tensorflow_lite_support/metadata/python/metadata_writers:object_detector",
    "//tensorflow_lite_support/metadata/python/metadata_writers:image_segmenter",
    "//tensorflow_lite_support/metadata/python/metadata_writers:audio_classifier",
    "//tensorflow_lite_support/metadata/python/metadata_writers:nl_classifier",
]

filegroup(
    name = "licenses",
    data = [
        "//:LICENSE",
        "@org_tensorflow//:LICENSE",
    ] + if_not_system_lib(
        "absl_py",
        [
            "@absl_py//absl:LICENSE",
            "@absl_py//absl/logging:LICENSE",
            "@absl_py//absl/flags:LICENSE",
            "@absl_py//absl/testing:LICENSE",
            "@absl_py//absl/third_party/unittest3_backport:LICENSE",
        ],
    ),
)

sh_binary(
    name = "build_pip_package",
    srcs = ["build_pip_package.sh"],
    data = COMMON_PIP_DEPS +
           select({
               "@org_tensorflow//tensorflow:windows": [
                   ":simple_console_for_windows",
               ],
               "//conditions:default": [
               ],
           }),
)

# On Windows, python binary is a zip file of runfiles tree.
# Add everything to its data dependency for generating a runfiles tree
# for building the pip package on Windows.
py_binary(
    name = "simple_console_for_windows",
    srcs = ["simple_console_for_windows.py"],
    data = COMMON_PIP_DEPS,
    srcs_version = "PY2AND3",
)
