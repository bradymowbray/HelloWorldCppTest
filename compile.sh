#!/usr/bin/env bash

rm -rf build run_test     \
	&& mkdir -p build \
	&& cd build       \
	&& cmake ..       \
	&& make           \
	&& make install

cd ..
