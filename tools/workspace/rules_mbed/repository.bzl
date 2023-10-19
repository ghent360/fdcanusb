# -*- python -*-

# Copyright 2018-2022 Josh Pieper, jjp@pobox.com.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

load("//tools/workspace:github_archive.bzl", "github_archive")

def rules_mbed_repository():
    github_archive(
        name = "com_github_ghent360_rules_mbed",
        repo = "ghent360/rules_mbed",
        commit = "80a3d332c6d93c1cd24f0cc811e21f1bf189aaf6",
        sha256 = "28d24696dd6c26b48c8d58d4e7c42c5badf930e7da0a4a22b6a19f5ba26f5dd8",
    )
