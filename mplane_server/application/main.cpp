/*!
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * \file      main.cpp
 * \brief     Mplane ORAN radio application
 *
 *
 * \details   Mplane ORAN radio application
 *
 */
#include <cstddef>
#include <dlfcn.h>
#include <memory>
#include <iostream>
#include "MplaneAlarms.h"



#include <signal.h>
#include <functional>


#include "Application.h"

using namespace Mplane;

typedef void (*halmplane_oran_alarm_cb_t)(
    const halmplane_oran_alarm_t* alarm, void* store);

// Example callback function
void myAlarmCallback(const halmplane_oran_alarm_t* alarm, void* store) {
    if (alarm) {
        // std::cout << "Alarm received with fault ID: " << alarm->fault_id << std::endl;
        // Additional handling code here
    }
}

namespace {
void sigintHandler(int signum) {
	std::shared_ptr<IApplication> app = IApplication::getInstance();
	app->quit();
}
} // namespace

void dynamicLib()
{
	// Register the callback function
    void *dlhandle = dlopen("/usr/lib/libhalmplane.so.0", RTLD_NOW);
    
    if (!dlhandle) {
        std::cerr << "Failed to load shared library: " << dlerror() << std::endl;
        return ;
    }

    void (*message_func)() = reinterpret_cast<void (*)()>(dlsym(dlhandle, "message"));
    if (!message_func) {
        std::cerr << "Failed to find 'message' function: " << dlerror() << std::endl;
        dlclose(dlhandle);
        return ;
    }

    // Call the 'message' function
    message_func();
    
    // call another function 

    // Load the callback function from the shared library
    int (*halmplane_registerOranAlarmCallback)(halmplane_oran_alarm_cb_t)  = reinterpret_cast<int (*)(halmplane_oran_alarm_cb_t)>(dlsym(dlhandle, "halmplane_registerOranAlarmCallback"));
    if (!halmplane_registerOranAlarmCallback) {
        std::cerr << "Failed to find 'halmplane_registerOranAlarmCallback' function: " << dlerror() << std::endl;
        
        return ;
    }

    halmplane_oran_alarm_cb_t alarm = myAlarmCallback;

    halmplane_registerOranAlarmCallback(alarm);
}

/*!
 * \brief The first start point for the program
 */
int main(int argc, const char** argv)
{
	dynamicLib();

	struct sigaction sa;

	// Create application
	std::shared_ptr<IApplication> app = IApplication::getInstance();

	// Go through full shutdown sequence when SIGINT is received
	sa.sa_handler = &sigintHandler;
	sigfillset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGINT, &sa, NULL);

	// Run the app
	return app->run("Mplane O-RAN M-Plane", argc, argv) ;
}
