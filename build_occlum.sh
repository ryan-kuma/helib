#!/bin/bash
set -e

OCCLUM_WORKSPACE=occlum_workspace

make clean
make
rm -rf database
./generate

build_occlum() {
    rm -rf $OCCLUM_WORKSPACE && mkdir -p $OCCLUM_WORKSPACE
    pushd $OCCLUM_WORKSPACE

    occlum init
    # copy execute file 
    cp ../01_leastSquare image/bin
    cp ../02_cosineMeasure image/bin
    cp ../03_count image/bin
    cp ../04_extremum image/bin
    cp ../05_slotsmean image/bin 

    cp ../database image/

    #build and run occlum
    occlum build
    popd
}

build_occlum
make clean
