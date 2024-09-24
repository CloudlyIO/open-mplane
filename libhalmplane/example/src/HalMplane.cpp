/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "HalMplane.h"
#include <iostream>


int halmplane_init(std::string path)
{
    std::cout << "Halmplane initializing...." <<std::endl;
    return 0;
}

int halmplane_exit()
{
    std::cout << "Halmplane exiting...." << std::endl;
    return 0;
}

