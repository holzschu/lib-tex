#!/bin/bash

IOS_SYSTEM_VER="2.4"
HHROOT="https://github.com/holzschu"

mkdir -p Frameworks
(cd "${BASH_SOURCE%/*}/Frameworks"
# ios_system
echo "Downloading the ios_system framework:"
curl -OL $HHROOT/ios_system/releases/download/v$IOS_SYSTEM_VER/smallRelease.tar.gz
( tar -xzf smallRelease.tar.gz --strip 1 && rm smallRelease.tar.gz ) || { echo "ios_system failed to download"; exit 1; }
)


