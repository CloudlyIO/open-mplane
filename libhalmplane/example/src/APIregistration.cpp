#include <iostream> 
#include <map>
#include <string>
#include <memory>

#include <HalMplane.h>
#include <MplaneInterfaces.h> 
#include <MplaneUplaneConf.h>

extern "C"
{
  void *function_map()
  {
    std::map<std::string, void*> *registered_functions;
    registered_functions = new std::map<std::string, void*>();

    //Halmplane 
    (*registered_functions)["int (*halmplane_init)(std::string)"] = (void*) halmplane_init;
    (*registered_functions)["int (*halmplane_exit)()"] = (void*) halmplane_exit; 
    
    //MplaneInterface
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update)(interface_t*)"]
     = (void*)halmplane_interface_update;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_description)(const char*, const char*)"]
     = (void*)halmplane_interface_update_description;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_type)(const char*, const char*)"]
     = (void*)halmplane_interface_update_type;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_enabled)(const char*, bool)"]
     = (void*)halmplane_interface_update_enabled;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_l2_mtu)(const char*, int)"]
     = (void*)halmplane_interface_update_l2_mtu;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_vlan_tagging)(const char*, bool)"]
     = (void*)halmplane_interface_update_vlan_tagging;    
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_base_interface)(const char*, const char*)"]
     = (void*)halmplane_interface_update_base_interface;
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_vlan_id)(const char*, int)"]
     = (void*)halmplane_interface_update_vlan_id;    
    (*registered_functions)["halmplane_error_t (*halmplane_interface_update_mac_address)(const char*, const char*)"]
     = (void*)halmplane_interface_update_mac_address;    
    
    //MplaneProcessingElements
    (*registered_functions)["halmplane_error_t (*halmplane_update_ru_element)(ru_elements_t*)"]
     = (void*)halmplane_update_ru_element;
    
    //MplaneUplaneConf.h
    (*registered_functions)["int (*halmplane_get_tx_array)(const char*, tx_array_t*)"]
     = (void*)halmplane_get_tx_array; 
    (*registered_functions)["const char** (*halmplane_get_tx_array_names)()"]
     = (void*)halmplane_get_tx_array_names; 
    (*registered_functions)["int (*halmplane_get_low_level_tx_endpoint)(const char*, low_level_tx_endpoint_t*)"]
     = (void*)halmplane_get_low_level_tx_endpoint; 
    (*registered_functions)["int (*halmplane_get_low_level_tx_endpoints)(low_level_tx_endpoint_t**, int*)"]
     = (void*)halmplane_get_low_level_tx_endpoints;
    (*registered_functions)["int (*halmplane_get_rx_array)(const char*, rx_array_t*)"]
     = (void*)halmplane_get_rx_array;
    (*registered_functions)["const char** (*halmplane_get_rx_array_names)()"]
     = (void*)halmplane_get_rx_array_names;  
    (*registered_functions)["int (*halmplane_get_low_level_rx_endpoint)(const char*, low_level_rx_endpoint_t*)"]
     = (void*)halmplane_get_low_level_rx_endpoint; 
    (*registered_functions)["int (*halmplane_get_low_level_rx_endpoints)"
    "(low_level_rx_endpoint_t**, int*)"]
     = (void*)halmplane_get_low_level_rx_endpoints;
    (*registered_functions)["int (*halmplane_tx_carrier_state_change)"
    "(const char*, uint64_t, uint64_t, double, const char*, int)"]
     = (void*)halmplane_tx_carrier_state_change;
    (*registered_functions)["int (*halmplane_rx_carrier_state_change)"
    "(const char*, uint64_t, uint64_t, double, const char*, int)"]
     = (void*)halmplane_rx_carrier_state_change;
    (*registered_functions)["int (*halmplane_setUPlaneConfiguration)"
    "(user_plane_configuration_t*)"]
     = (void*)halmplane_setUPlaneConfiguration; 
    (*registered_functions)["int (*halmplane_update_tx_eaxc)"
    "(const char*, e_axcid_t*)"]
     = (void*)halmplane_update_tx_eaxc;
    (*registered_functions)["int (*halmplane_update_rx_eaxc)"
    "(const char*, e_axcid_t*)"]
     = (void*)halmplane_update_rx_eaxc; 
    (*registered_functions)["int (*halmplane_update_rx_endpoint_compression)"
    "(const char*, compression_t*)"]
     = (void*)halmplane_update_rx_endpoint_compression;  
    (*registered_functions)["int (*halmplane_update_tx_endpoint_compression)"
    "(const char*, compression_t*)"]
     = (void*)halmplane_update_tx_endpoint_compression;  
    (*registered_functions)["int (*halmplane_update_rx_endpoint_compression_dyn_config)"
    "(const char*, dynamic_compression_configuration_t*)"]
     = (void*)halmplane_update_rx_endpoint_compression_dyn_config; 
    (*registered_functions)["int (*halmplane_update_tx_endpoint_compression_dyn_config)"
    "(const char*, dynamic_compression_configuration_t*)"]
     = (void*)halmplane_update_tx_endpoint_compression_dyn_config;
    (*registered_functions)["int (*halmplane_register_rx_carrier_state_cb)"
    "(halmplane_carrier_state_cb_t)"]
     = (void*)halmplane_register_rx_carrier_state_cb; 
    (*registered_functions)["int (*halmplane_register_tx_carrier_state_cb)"
    "(halmplane_carrier_state_cb_t)"]
     = (void*)halmplane_register_tx_carrier_state_cb;
    return registered_functions;
  }
}