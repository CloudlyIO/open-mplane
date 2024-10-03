#include <testModular.h>
#include <iostream>
#include "YangConfigParser.h"
#include <memory>

void test_Halmplane()
{
    // std::cout << "test_Halmplane testing..." << std::endl;

    // std::shared_ptr<IConfigLoad> cfgData = std::make_shared<YangConfigParser>();

    // std::cout << "111111" << std::endl;
    // tinyxml2::XMLDocument doc;
    // std::cout << "00000" << std::endl;
    // std::string filePath = cfgData->getPath();
    // std::cout << "222222" << std::endl;
   
    // if (doc.LoadFile(filePath.c_str()) == tinyxml2::XML_NO_ERROR)
    // {
    // halmplane_init(&doc);
    // }
    // else
    // {
    // halmplane_init(NULL);
    // }
}

void test_MplaneInterfaces()
{
    std::cout << "test_MplaneInterface loading..." << std::endl;
    
    interface_t* interface;
    
    // Test 1
    //
    if( halmplane_interface_update(interface) == NONE)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_interface_update returns NONE "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_interface_update call failed "<<std::endl;
    }

    // Test 2
    //
    if( halmplane_interface_update_description("name", "description") == NONE)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_interface_update_description returns NONE "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_interface_update_description call failed "<<std::endl;
    }

    // Test 3
    //
    if( halmplane_interface_update_type("name", "type") == NONE)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_interface_update_type returns NONE "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_interface_update_type call failed "<<std::endl;
    }

    // Test 4
    //
    if( halmplane_interface_update_enabled("name", "enabled") == NONE)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_interface_update_enabled returns NONE "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_interface_update_enabled call failed "<<std::endl;
    }
    
    // Test 5
    //
    if( halmplane_interface_update_l2_mtu("name", 12) == NONE)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_interface_update_l2_mtu returns NONE "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_interface_update_l2_mtu call failed "<<std::endl;
    }
    
    // Test 6
    //
    if( halmplane_interface_update_vlan_tagging("name",1) == NONE)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_interface_update_vlan_tagging returns NONE "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_interface_update_vlan_tagging call failed  "<<std::endl;
    }
    
    // Test 7
    //
    if( halmplane_interface_update_base_interface("name", "baseInterface") == NONE)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_interface_update_base_interface returns NONE  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_interface_update_base_interface call failed "<<std::endl;
    }
    
    // Test 8
    //
    if( halmplane_interface_update_mac_address("name", "macAddress") == NONE)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_interface_update_mac_address returns NONE "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_interface_update_mac_address call failed "<<std::endl;
    }

    // Test 9
    //
    if( halmplane_interface_update_vlan_id("name", 12) == NONE)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_interface_update_vlan_id returns NONE "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_interface_update_vlan_id call failed "<<std::endl;
    }
    
}

void test_MplaneProcessingElement()
{
    std::cout << std::endl << "test_MplaneProcessingElement is loading..." << std::endl;
    
    eth_flow_t example_eth_flow = {
    .ru_mac_address = "00:11:22:33:44:55",
    .vlan_id = 100,
    .o_du_mac_address = "66:77:88:99:AA:BB"
    };

    aliasmac_flow_t example_aliasmac_flow = {
    // Initialize fields as necessary
    };

    udpip_flow_t example_udpip_flow = {
    // Initialize fields as necessary
    };

    transport_flow_t example_transport_flow = {
    .interface_name = "eth0",
    .amac_flow = example_aliasmac_flow,
    .e_flow = example_eth_flow,
    .u_flow = example_udpip_flow
    };

    ru_elements_t example_ru_element = {
    .name = "RU1",
    .t_flow = example_transport_flow
    };

    
    // Test 1
    //
    if( halmplane_update_ru_element(&example_ru_element) == NONE)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_update_ru_element returns NONE "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_update_ru_element call failed "<<std::endl;
    }
}

void test_MplaneUplaneConf()
{

    std::cout << std::endl << "test_MplaneUplaneConf loading..." << std::endl;
    
    tx_array_t tx_array;
    rx_array_t rx_arrays;

    low_level_tx_endpoint_t tx_endpoint;
    low_level_tx_endpoint_t* tx_endpoints;

    low_level_rx_endpoint_t rx_endpoint;
    low_level_rx_endpoint_t* rx_endpoints;
    int n_endpoints;
    user_plane_configuration_t uplane_cfg;
    const char *endpoint_name = "endpoint_name";
    e_axcid_t eaxc;
    compression_t compression;
    dynamic_compression_configuration_t config;
    halmplane_carrier_state_cb_t cb;
    // int* n_endpoints
    

    // Test 1
    //
    if( halmplane_setUPlaneConfiguration(&uplane_cfg) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_setUPlaneConfiguration returns 0 "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_setUPlaneConfiguration call failed  "<<std::endl;
    }


    // Test 2
    //
    if( halmplane_update_rx_eaxc(endpoint_name, &eaxc) == 0)
    {
        std::cout<<" Test passed  "; 
        std::cout<<" halmplane_update_rx_eaxc returns 0 "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_update_rx_eaxc call failed  "<<std::endl;
    }
    
    // Test 3
    //
    if( halmplane_update_tx_eaxc(endpoint_name, &eaxc) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_update_tx_eaxc returns 0  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_update_tx_eaxc call failed  "<<std::endl;
    }
        
    // Test 4
    //
    if( halmplane_update_rx_endpoint_compression(endpoint_name, &compression) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_update_rx_endpoint_compression returns 0  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_update_rx_endpoint_compression call failed "<<std::endl;
    }
    

    // Test 5
    //
    if( halmplane_update_tx_endpoint_compression(endpoint_name, &compression) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_update_tx_endpoint_compression returns 0  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_update_tx_endpoint_compression call failed "<<std::endl;
    }
    
    // Test 6
    //
    if( halmplane_update_rx_endpoint_compression_dyn_config(endpoint_name, &config) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_update_rx_endpoint_compression_dyn_config returns 0  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_update_rx_endpoint_compression_dyn_config call failed "<<std::endl;
    }
    
    
    // Test 7
    //
    if( halmplane_update_tx_endpoint_compression_dyn_config(endpoint_name, &config) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_update_tx_endpoint_compression_dyn_config returns 0  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_update_tx_endpoint_compression_dyn_config call failed  "<<std::endl;
    }
    
    
    // Test 8
    //
    if( halmplane_register_rx_carrier_state_cb(cb) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_register_rx_carrier_state_cb returns 0 "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_register_rx_carrier_state_cb call failed "<<std::endl;
    }
    
    // Test 9
    //
    if( halmplane_register_tx_carrier_state_cb(cb) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_register_tx_carrier_state_cb returns 0  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" Test failed halmplane_register_tx_carrier_state_cb call failed "<<std::endl;
    }

    /*
    *end of test
    */
    

    // Test 10
    //
    if( halmplane_get_tx_array("name", &tx_array) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_get_tx_array returns 0 "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_get_tx_array call failed "<<std::endl;
    }
    
    // Test 11
    //
    if( halmplane_get_tx_array_names() == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_get_tx_array_names returns 0  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_get_tx_array_names call failed "<<std::endl;
    }

    // Test 12
    //
    if( halmplane_get_low_level_tx_endpoint("name", &tx_endpoint) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_get_low_level_tx_endpoint returns 0  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_get_low_level_tx_endpoint call failed  "<<std::endl;
    }
    
    // Test 13
    //
    if( halmplane_get_low_level_tx_endpoints(&tx_endpoints, &n_endpoints) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_get_low_level_tx_endpoints returns 0  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_get_low_level_tx_endpoints call failed "<<std::endl;
    }
    
    // Test 14
    //
    if( halmplane_get_rx_array("name", &rx_arrays) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_get_rx_array returns 0 "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_get_rx_array call failed "<<std::endl;
    }
    
    // Test 15
    //
    if( halmplane_get_rx_array_names() == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_get_rx_array_names returns 0  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_get_rx_array_names call failed  "<<std::endl;
    }
    
    // Test 16
    //
    if( halmplane_get_low_level_rx_endpoint("name", &rx_endpoint) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_get_low_level_rx_endpoint returns 0 "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_get_low_level_rx_endpoint call failed  "<<std::endl;
    }
    
    // Test 17
    //
    if( halmplane_get_low_level_rx_endpoints(&rx_endpoints, &n_endpoints) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_get_low_level_rx_endpoints returns 0 "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed  "; 
        std::cout<<" halmplane_get_low_level_rx_endpoints call failed "<<std::endl;
    }

    // Test 18
    //
    if( halmplane_tx_carrier_state_change("name", 0, 1, 2, "new_state", 1) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_tx_carrier_state_change returns 0  "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_tx_carrier_state_change call failed "<<std::endl;
    }

    // Test 19
    //
    if( halmplane_rx_carrier_state_change("name", 0, 1, 2, "new_state", 1) == 0)
    {
        std::cout<<" Test passed "; 
        std::cout<<" halmplane_rx_carrier_state_change returns 0 "<<std::endl;
    }
    else 
    {
        std::cout<<" Test failed "; 
        std::cout<<" halmplane_rx_carrier_state_change call failed "<<std::endl;
    }
    
    
    
}

void runTests()
{
    //test_Halmplane();
    test_MplaneInterfaces();
    test_MplaneProcessingElement();
    test_MplaneUplaneConf();
}