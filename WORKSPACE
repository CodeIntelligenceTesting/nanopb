workspace(name = "com_github_nanopb_nanopb")


# CI Fuzz dependencies

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_fuzzing",
    sha256 = "ff52ef4845ab00e95d29c02a9e32e9eff4e0a4c9c8a6bcf8407a2f19eb3f9190",
    strip_prefix = "rules_fuzzing-0.4.1",
    urls = ["https://github.com/bazelbuild/rules_fuzzing/releases/download/v0.4.1/rules_fuzzing-0.4.1.zip"],
)

load("@rules_fuzzing//fuzzing:repositories.bzl", "rules_fuzzing_dependencies")

rules_fuzzing_dependencies()

load("@rules_fuzzing//fuzzing:init.bzl", "rules_fuzzing_init")

rules_fuzzing_init()

load("@fuzzing_py_deps//:requirements.bzl", "install_deps")

install_deps()

git_repository(
    name = "cifuzz",
    commit = "b013aa0f90fe8ac60adfc6d9640a9cfa451dda9e",
    remote = "https://github.com/CodeIntelligenceTesting/cifuzz-bazel",
)


# nanopb

load("//extra/bazel:nanopb_deps.bzl", "nanopb_deps")

nanopb_deps()

load("@rules_python//python:repositories.bzl", "python_register_toolchains")

python_register_toolchains(
    name = "python3_9",
    python_version = "3.9",
)

load("//extra/bazel:python_deps.bzl", "nanopb_python_deps")

load("@python3_9//:defs.bzl", "interpreter")

nanopb_python_deps(interpreter)

load("//extra/bazel:nanopb_workspace.bzl", "nanopb_workspace")

nanopb_workspace()

