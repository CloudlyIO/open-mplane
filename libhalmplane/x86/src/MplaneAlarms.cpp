/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */
#include <iostream>
#include <stdio.h>
#include "MplaneAlarms.h"

int halmplane_registerOranAlarmCallback(halmplane_oran_alarm_cb_t callback) {
    printf("Calling halmplane_registerOranAlarmCallback()...\n");
    return 0;
    // TODO
}

void message() {
    std::cout << "MplaneAlarms module loading..." << std::endl;
}
