#!/usr/bin/env python
# Copyright 2017 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

from os import path as os_path
import platform
import subprocess
import sys
import os

def which(cmd):
    pathenv = os.getenv('PATH')
    for p in pathenv.split(os_path.pathsep):
        p = os_path.join(p, cmd)
        if os_path.exists(p) and os.access(p, os.X_OK):
            return p
    return None

def GetBinaryPath():
  if sys.platform == 'win32':
    nodejs = which('node.exe')
    if nodejs:
      return nodejs
  else:
    nodejs = which('nodejs')
    if nodejs:
      return nodejs
    nodejs = which('node')
    if nodejs:
      return nodejs

  darwin_name = ('node-darwin-arm64' if platform.machine() == 'arm64' else
                 'node-darwin-x64')
  return os_path.join(os_path.dirname(__file__), *{
    'Darwin': ('mac', darwin_name, 'bin', 'node'),
    'Linux': ('linux', 'node-linux-x64', 'bin', 'node'),
    'Windows': ('win', 'node.exe'),
  }[platform.system()])


def RunNode(cmd_parts, stdout=None):
  cmd = [GetBinaryPath()] + cmd_parts
  process = subprocess.Popen(
      cmd, cwd=os.getcwd(), stdout=subprocess.PIPE, stderr=subprocess.PIPE,
      universal_newlines=True)
  stdout, stderr = process.communicate()

  if process.returncode != 0:
    # Handle cases where stderr is empty, even though the command failed, for
    # example https://github.com/microsoft/TypeScript/issues/615
    err = stderr if len(stderr) > 0 else stdout
    raise RuntimeError('Command \'%s\' failed\n%s' % (' '.join(cmd), err))

  return stdout

if __name__ == '__main__':
  RunNode(sys.argv[1:])
