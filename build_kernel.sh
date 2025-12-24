#!/bin/bash

export PLATFORM_VERSION=11
export ANDROID_MAJOR_VERSION=r 
export ARCH=arm64
export SEC_BUILD_CONF_VENDOR_BUILD_OS=13
export CROSS_COMPILE=aarch64-linux-gnu-
make exynos9830_defconfig
make -j$(nproc)
