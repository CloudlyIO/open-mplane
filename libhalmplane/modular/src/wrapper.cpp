#include <wrapper.h>
#include <hal_loader.h>
#include "libtinyxml2/tinyxml2.h"

using namespace tinyxml2;

const char* configured_libname = NULL;
Hal_Loader* hal_loader = NULL;


int halmplane_init(std::string path)
{
  std::cout <<"wrapper halmplane init for extraction" << std::endl;
  XMLDocument doc;
  const char* libname = NULL;
  if (doc.LoadFile(path.c_str()) != XML_SUCCESS) {
      std::cerr << "Failed to load XML file!" << std::endl;
      return -1;
  }
  // Navigate to the module-libhalmplane element
  XMLElement* module = doc.FirstChildElement("root")->FirstChildElement("modular");
  if (module) 
  {
      // Get the file element
    libname = module->FirstChildElement("file")->Attribute("value");
    if (!libname) 
    {
        std::cerr << "Filename attribute not found!" << std::endl;
    }
  } 
  else 
  {
    std::cerr <<  "modular element not found!" << std::endl;
  }
  
  if(configured_libname == NULL)
  {
    configured_libname = libname;
    hal_loader = new Hal_Loader(configured_libname);
  } 

  return 0;
}

int halmplane_exit()
{
  capture_source_as_str(int (*halmplane_exit)(), ftag);
  halmplane_exit = (int (*)()) hal_loader->get_function(ftag);
  if(halmplane_exit)
  {
    return halmplane_exit();
  }

  return 0;
}

halmplane_error_t halmplane_interface_update(interface_t* interface)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update)(interface_t*), ftag);
  halmplane_interface_update = (halmplane_error_t (*)(interface_t*)) hal_loader->get_function(ftag);
  if(halmplane_interface_update)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update(interface);
  }
  else 
  {
    std::cout << "halmplane_interface update does not exist" << std::endl;
  }
  return NONE;
}


halmplane_error_t halmplane_interface_update_description(
      const char* name, const char* description)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_description)(const char*, const char*), ftag);

  halmplane_interface_update_description = (halmplane_error_t (*)(const char*, const char*)) hal_loader->get_function(ftag);  
  
  if(halmplane_interface_update_description)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_description(name, description);
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_type(
      const char* name, const char* type)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_type)(const char*, const char*), ftag);

  halmplane_interface_update_type = (halmplane_error_t (*)(const char*, const char*)) hal_loader->get_function(ftag);  
  
  if(halmplane_interface_update_type)
  {
    std::cout << "wrapper  " ;
    return halmplane_interface_update_type(name, type);
  }
  else 
  {
    std::cout <<"function does not exist" << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_enabled(
  const char* name, bool enabled)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_enabled)(const char*, bool), ftag);

  halmplane_interface_update_enabled = (halmplane_error_t (*)(const char*, bool)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_enabled)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_enabled(name, enabled);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;

}

halmplane_error_t halmplane_interface_update_l2_mtu(
  const char* name, int l2Mtu)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_l2_mtu)(const char*, int), ftag);
  
  halmplane_interface_update_l2_mtu = (halmplane_error_t (*)(const char*, int)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_l2_mtu)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_l2_mtu(name, l2Mtu);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_vlan_tagging(
  const char* name, bool vlanTagging)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_vlan_tagging)(const char*, bool), ftag);
  
  halmplane_interface_update_vlan_tagging = (halmplane_error_t (*)(const char*, bool)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_vlan_tagging)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_vlan_tagging(name, vlanTagging);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_base_interface(
  const char* name, const char* baseInterface)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_base_interface)(const char*, const char*), ftag);
  
  halmplane_interface_update_base_interface = (halmplane_error_t (*)(const char*, const char*l)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_base_interface)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_base_interface(name, baseInterface);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_vlan_id(
  const char* name, int vlanId)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_vlan_id)(const char*, int), ftag);
  
  halmplane_interface_update_vlan_id = (halmplane_error_t (*)(const char*, int)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_vlan_id)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_vlan_id(name, vlanId);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_interface_update_mac_address(
  const char* name, const char* macAddress)
{
  capture_source_as_str(halmplane_error_t (*halmplane_interface_update_mac_address)(const char*, const char*), ftag);
  
  halmplane_interface_update_mac_address = (halmplane_error_t (*)(const char*, const char*)) hal_loader->get_function(ftag);

  if(halmplane_interface_update_mac_address)
  {
    std::cout << "wrapper " ;
    return halmplane_interface_update_mac_address(name, macAddress);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

// //MplaneProcessingElements module api
halmplane_error_t halmplane_update_ru_element(ru_elements_t* ru_element)
{
  capture_source_as_str(halmplane_error_t (*halmplane_update_ru_element)(ru_elements_t*), ftag);
  
  halmplane_update_ru_element = (halmplane_error_t (*)(ru_elements_t*)) hal_loader->get_function(ftag);

  if(halmplane_update_ru_element)
  {
    std::cout << "wrapper " ;
    return halmplane_update_ru_element(ru_element);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

// // MplaneUplaneConf 
int halmplane_get_tx_array(const char* name, tx_array_t* tx_array)
{
  capture_source_as_str(int (*halmplane_get_tx_array)(const char*, tx_array_t*), ftag);
  
  halmplane_get_tx_array = (int (*)(const char*, tx_array_t*)) hal_loader->get_function(ftag);

  if(halmplane_get_tx_array)
  {
    std::cout << "wrapper " ;
    return halmplane_get_tx_array(name, tx_array);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

const char** halmplane_get_tx_array_names()
{
  capture_source_as_str(const char** (*halmplane_get_tx_array_names)(), ftag);
  
  halmplane_get_tx_array_names = (const char** (*)()) hal_loader->get_function(ftag);

  if(halmplane_get_tx_array_names)
  {
    std::cout << "wrapper " ;
    return halmplane_get_tx_array_names();
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

int halmplane_get_low_level_tx_endpoint(const char* name, low_level_tx_endpoint_t* tx_endpoint)
{
  capture_source_as_str(int (*halmplane_get_low_level_tx_endpoint)(const char*, low_level_tx_endpoint_t*), ftag);
  
  halmplane_get_low_level_tx_endpoint = (int (*)(const char*, low_level_tx_endpoint_t*)) hal_loader->get_function(ftag);

  if(halmplane_get_low_level_tx_endpoint)
  {
    std::cout << "wrapper " ;
    return halmplane_get_low_level_tx_endpoint(name, tx_endpoint);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

int halmplane_get_low_level_tx_endpoints(low_level_tx_endpoint_t** tx_endpoints, int* n_endpoints)
{
  capture_source_as_str(int (*halmplane_get_low_level_tx_endpoints)(low_level_tx_endpoint_t**, int*), ftag);
  
  halmplane_get_low_level_tx_endpoints = (int (*)(low_level_tx_endpoint_t**, int*)) hal_loader->get_function(ftag);

  if(halmplane_get_low_level_tx_endpoints)
  {
    std::cout << "wrapper " ;
    return halmplane_get_low_level_tx_endpoints(tx_endpoints, n_endpoints);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;  
}

int halmplane_get_rx_array(const char* name, rx_array_t* rx_arrays)
{
  capture_source_as_str(int (*halmplane_get_rx_array)(const char*, rx_array_t*), ftag);
  
  halmplane_get_rx_array = (int (*)(const char*, rx_array_t*)) hal_loader->get_function(ftag);

  if(halmplane_get_rx_array)
  {
    std::cout << "wrapper " ;
    return halmplane_get_rx_array(name, rx_arrays);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

const char** halmplane_get_rx_array_names()
{
  capture_source_as_str(const char** (*halmplane_get_rx_array_names)(), ftag);
  
  halmplane_get_rx_array_names = (const char** (*)()) hal_loader->get_function(ftag);

  if(halmplane_get_rx_array_names)
  {
    std::cout << "wrapper " ;
    return halmplane_get_rx_array_names();
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;  
}

int halmplane_get_low_level_rx_endpoint(
    const char* name, low_level_rx_endpoint_t* rx_endpoint)
{
  capture_source_as_str(int (*halmplane_get_low_level_rx_endpoint)(const char*, low_level_rx_endpoint_t*), ftag);
  
  halmplane_get_low_level_rx_endpoint = (int (*)(const char*, low_level_rx_endpoint_t*)) hal_loader->get_function(ftag);

  if(halmplane_get_low_level_rx_endpoint)
  {
    std::cout << "wrapper " ;
    return halmplane_get_low_level_rx_endpoint(name, rx_endpoint);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;  
}

int halmplane_get_low_level_rx_endpoints(
    low_level_rx_endpoint_t** rx_endpoints, int* n_endpoints)
{
  capture_source_as_str(
      int (*halmplane_get_low_level_rx_endpoints)(low_level_rx_endpoint_t**, int*),
      ftag
  );
  
  halmplane_get_low_level_rx_endpoints = (int (*)(low_level_rx_endpoint_t**, int*)) hal_loader->get_function(ftag);

  if(halmplane_get_low_level_rx_endpoints)
  {
    std::cout << "wrapper " ;
    return halmplane_get_low_level_rx_endpoints(rx_endpoints, n_endpoints);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;   
}

int halmplane_tx_carrier_state_change(
    const char* name,
    uint64_t chbw,
    uint64_t center,
    double gain,
    const char* new_state,
    int do_apply)
{
  capture_source_as_str(
    int (*halmplane_tx_carrier_state_change)(const char*, uint64_t, uint64_t, double, const char*, int), ftag);
  
  halmplane_tx_carrier_state_change = (int (*)(const char*, uint64_t, uint64_t,
 double, const char*, int)) hal_loader->get_function(ftag);

  if(halmplane_tx_carrier_state_change)
  {
    std::cout << "wrapper " ;
    return halmplane_tx_carrier_state_change(
      name, chbw,
      center, gain, new_state, do_apply);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

int halmplane_rx_carrier_state_change(
    const char* name,
    uint64_t chbw,
    uint64_t center,
    double gain_correction,
    const char* new_state,
    int do_apply)
{
  capture_source_as_str(
    int (*halmplane_rx_carrier_state_change)(const char*, uint64_t, uint64_t, double, const char*, int), ftag);
  
  halmplane_rx_carrier_state_change = (int (*)(const char*, uint64_t, uint64_t,
 double, const char*, int)) hal_loader->get_function(ftag);

  if(halmplane_rx_carrier_state_change)
  {
    std::cout << "wrapper " ;
    return halmplane_rx_carrier_state_change(
      name, chbw,
      center, gain_correction, new_state, do_apply);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

int halmplane_setUPlaneConfiguration(user_plane_configuration_t* uplane_cfg)
{
  capture_source_as_str(
    int (*halmplane_setUPlaneConfiguration)(user_plane_configuration_t*), ftag);
  
  halmplane_setUPlaneConfiguration = (int (*)
  (user_plane_configuration_t*))hal_loader->get_function(ftag);

  if(halmplane_setUPlaneConfiguration)
  {
    std::cout << "wrapper " ;
    return halmplane_setUPlaneConfiguration(uplane_cfg);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;  
}

int halmplane_update_tx_eaxc(const char* endpoint_name, e_axcid_t* eaxc)
{
  capture_source_as_str(
    int (*halmplane_update_tx_eaxc)(const char*, e_axcid_t*), ftag);
  
  halmplane_update_tx_eaxc = (int (*)
  (const char*, e_axcid_t*))hal_loader->get_function(ftag);

  if(halmplane_update_tx_eaxc)
  {
    std::cout << "wrapper " ;
    return halmplane_update_tx_eaxc(endpoint_name, eaxc);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;   
}

int halmplane_update_rx_eaxc(const char* endpoint_name, e_axcid_t* eaxc)
{
  capture_source_as_str(
    int (*halmplane_update_rx_eaxc)(const char*, e_axcid_t*), ftag);
  
  halmplane_update_rx_eaxc = (int (*)
  (const char*, e_axcid_t*))hal_loader->get_function(ftag);

  if(halmplane_update_rx_eaxc)
  {
    std::cout << "wrapper " ;
    return halmplane_update_rx_eaxc(endpoint_name, eaxc);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0; 
}

int halmplane_update_rx_endpoint_compression(
    const char* endpoint_name, compression_t* compression)
{
  capture_source_as_str(
    int (*halmplane_update_rx_endpoint_compression)(const char*, compression_t*), ftag);
  
  halmplane_update_rx_endpoint_compression = (int (*)
  (const char*, compression_t*))hal_loader->get_function(ftag);

  if(halmplane_update_rx_endpoint_compression)
  {
    std::cout << "wrapper " ;
    return halmplane_update_rx_endpoint_compression(endpoint_name, compression);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

int halmplane_update_tx_endpoint_compression(
    const char* endpoint_name, compression_t* compression)
{
  capture_source_as_str(
    int (*halmplane_update_tx_endpoint_compression)(const char*, compression_t*), ftag);
  
  halmplane_update_tx_endpoint_compression = (int (*)
  (const char*, compression_t*))hal_loader->get_function(ftag);

  if(halmplane_update_tx_endpoint_compression)
  {
    std::cout << "wrapper " ;
    return halmplane_update_tx_endpoint_compression(endpoint_name, compression);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

int halmplane_update_rx_endpoint_compression_dyn_config(
    const char* endpoint_name, dynamic_compression_configuration_t* config)
{
  capture_source_as_str(
    int (*halmplane_update_rx_endpoint_compression_dyn_config)(const char*, dynamic_compression_configuration_t*), ftag);
  
  halmplane_update_rx_endpoint_compression_dyn_config = (int (*)
  (const char*, dynamic_compression_configuration_t*))hal_loader->get_function(ftag);

  if(halmplane_update_rx_endpoint_compression_dyn_config)
  {
    std::cout << "wrapper " ;
    return halmplane_update_rx_endpoint_compression_dyn_config(endpoint_name, config);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;  
}

int halmplane_update_tx_endpoint_compression_dyn_config(
    const char* endpoint_name, dynamic_compression_configuration_t* config)
{
  capture_source_as_str(
    int (*halmplane_update_tx_endpoint_compression_dyn_config)(const char*, dynamic_compression_configuration_t*), ftag);
  
  halmplane_update_tx_endpoint_compression_dyn_config = (int (*)
  (const char*, dynamic_compression_configuration_t*))hal_loader->get_function(ftag);

  if(halmplane_update_tx_endpoint_compression_dyn_config)
  {
    std::cout << "wrapper " ;
    return halmplane_update_tx_endpoint_compression_dyn_config(endpoint_name, config);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0; 
}

int halmplane_register_rx_carrier_state_cb(halmplane_carrier_state_cb_t cb)
{
  capture_source_as_str(
    int (*halmplane_register_rx_carrier_state_cb)(halmplane_carrier_state_cb_t), ftag);
  
  halmplane_register_rx_carrier_state_cb = (int (*)
  (halmplane_carrier_state_cb_t))hal_loader->get_function(ftag);

  if(halmplane_register_rx_carrier_state_cb)
  {
    std::cout << "wrapper " ;
    return halmplane_register_rx_carrier_state_cb(cb);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0; 
}

int halmplane_register_tx_carrier_state_cb(halmplane_carrier_state_cb_t cb)
{
  capture_source_as_str(
    int (*halmplane_register_tx_carrier_state_cb)(halmplane_carrier_state_cb_t), ftag);
  
  halmplane_register_tx_carrier_state_cb = (int (*)
  (halmplane_carrier_state_cb_t))hal_loader->get_function(ftag);

  if(halmplane_register_tx_carrier_state_cb)
  {
    std::cout << "wrapper " ;
    return halmplane_register_tx_carrier_state_cb(cb);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0; 
}

//MplaneAlarms

int halmplane_registerOranAlarmCallback(halmplane_oran_alarm_cb_t callback) 
{
  capture_source_as_str(
  int (*halmplane_registerOranAlarmCallback)(halmplane_oran_alarm_cb_t), ftag);
 
  halmplane_registerOranAlarmCallback = (int (*)
  (halmplane_oran_alarm_cb_t))hal_loader->get_function(ftag);

  if(halmplane_registerOranAlarmCallback)
  {
    std::cout << "wrapper " ;
    return halmplane_registerOranAlarmCallback(callback);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0; 
}

//MplaneEcpri

bool halmplane_message5Enabled(void)
{
  capture_source_as_str(
  bool (*halmplane_message5Enabled)(void), ftag);
  
  halmplane_message5Enabled = (bool (*)
  (void))hal_loader->get_function(ftag);

  if(halmplane_message5Enabled)
  {
    std::cout << "wrapper " ;
    return halmplane_message5Enabled();
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}
#if 0
bool halmplane_set_ietf_hardware (halmplane_oran_hardware_t hw)
{
  capture_source_as_str(
  bool (*halmplane_set_ietf_hardware)(halmplane_oran_hardware_t), ftag);
  halmplane_set_ietf_hardware = (bool (*)(halmplane_oran_hardware_t))hal_loader->get_function(ftag);
   if(halmplane_set_ietf_hardware)
  {
    std::cout << "wrapper " ;
    return halmplane_set_ietf_hardware(hw);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}
#endif 

//MplaneExternalio
halmplane_error_t halmplane_get_io_value(external_io_t* io)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_io_value)(external_io_t*), ftag);
  
  halmplane_get_io_value = (halmplane_error_t (*)
  (external_io_t*))hal_loader->get_function(ftag);

  if(halmplane_get_io_value)
  {
    std::cout << "wrapper " ;
    return halmplane_get_io_value(io);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

halmplane_error_t halmplane_set_io_value(output_setting_t* out_setting)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_set_io_value)(output_setting_t*), ftag);
  
  halmplane_set_io_value = (halmplane_error_t (*)
  (output_setting_t*))hal_loader->get_function(ftag);

  if(halmplane_set_io_value)
  {
    std::cout << "wrapper " ;
    return halmplane_set_io_value(out_setting);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

// //MplanePerformanceMgmt

int halmplane_activateEpeMeasObjects(
    epe_measurement_objects_t config, halmplane_epe_meas_cb_t cb)
{
  capture_source_as_str(
  int (*halmplane_activateEpeMeasObjects)(epe_measurement_objects_t, halmplane_epe_meas_cb_t), ftag);
  
  halmplane_activateEpeMeasObjects = (int (*)
  (epe_measurement_objects_t, halmplane_epe_meas_cb_t))hal_loader->get_function(ftag);

  if(halmplane_activateEpeMeasObjects)
  {
    std::cout << "wrapper " ;
    return halmplane_activateEpeMeasObjects(config, cb);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

int halmplane_registerOranPerfMeasCallback(halmplane_oran_perf_meas_cb_t callback)
{
capture_source_as_str(
  int (*halmplane_registerOranPerfMeasCallback)(halmplane_oran_perf_meas_cb_t), ftag);
  
  halmplane_registerOranPerfMeasCallback = (int (*)
  (halmplane_oran_perf_meas_cb_t))hal_loader->get_function(ftag);

  if(halmplane_registerOranPerfMeasCallback)
  {
    std::cout << "wrapper " ;
    return halmplane_registerOranPerfMeasCallback(callback);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;
}

const halmplane_oran_perf_meas_cb_t get_perf_meas_cb_ptr(void)
{
capture_source_as_str(
  const halmplane_oran_perf_meas_cb_t (*get_perf_meas_cb_ptr)(void), ftag);
  
  get_perf_meas_cb_ptr = (const halmplane_oran_perf_meas_cb_t (*)
  (void))hal_loader->get_function(ftag);

  if(get_perf_meas_cb_ptr)
  {
    std::cout << "wrapper " ;
    return get_perf_meas_cb_ptr();
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return 0;  
}

int halmplane_getRssi(uint8_t interface, double* rssiValue)
{
  capture_source_as_str(
    int (*halmplane_getRssi)(uint8_t, double*), ftag);
    
    halmplane_getRssi = (int (*)
    (uint8_t, double*))hal_loader->get_function(ftag);

    if(halmplane_getRssi)
    {
      std::cout << "wrapper " ;
      return halmplane_getRssi(interface, rssiValue);
    }
    else 
    {
      std::cout <<"function does not exist." << std::endl;
    }
    return 0;  
}

int halmplane_configPerfMeasurementParams(
    performance_measurement_params_t* config)
{
  capture_source_as_str(
    int (*halmplane_configPerfMeasurementParams)(performance_measurement_params_t*), ftag);
    
    halmplane_configPerfMeasurementParams = (int (*)
    (performance_measurement_params_t*))hal_loader->get_function(ftag);

    if(halmplane_configPerfMeasurementParams)
    {
      std::cout << "wrapper " ;
      return halmplane_configPerfMeasurementParams(config);
    }
    else 
    {
      std::cout <<"function does not exist." << std::endl;
    }
    return 0;
}

int halmplane_activateTransceiverMeasObjects(
    transceiver_measurement_objects_t config,
    halmplane_transceiver_meas_cb_t cb)
{
  capture_source_as_str(
    int (*halmplane_activateTransceiverMeasObjects)(transceiver_measurement_objects_t, halmplane_transceiver_meas_cb_t), ftag);
    
    halmplane_activateTransceiverMeasObjects = (int (*)
    (transceiver_measurement_objects_t, halmplane_transceiver_meas_cb_t))hal_loader->get_function(ftag);

    if(halmplane_activateTransceiverMeasObjects)
    {
      std::cout << "wrapper " ;
      return halmplane_activateTransceiverMeasObjects(config, cb);
    }
    else 
    {
      std::cout <<"function does not exist." << std::endl;
    }
    return 0;
}

int halmplane_activateRxWindowMeasObjects(
    rx_window_measurement_objects_t config,
    halmplane_rx_window_meas_cb_t cb)
{
  capture_source_as_str(
    int (*halmplane_activateRxWindowMeasObjects)(rx_window_measurement_objects_t, halmplane_rx_window_meas_cb_t), ftag);
    
    halmplane_activateRxWindowMeasObjects = (int (*)
    (rx_window_measurement_objects_t, halmplane_rx_window_meas_cb_t))hal_loader->get_function(ftag);

    if(halmplane_activateRxWindowMeasObjects)
    {
      std::cout << "wrapper " ;
      return halmplane_activateRxWindowMeasObjects(config, cb);
    }
    else 
    {
      std::cout <<"function does not exist." << std::endl;
    }
    return 0;
}

int halmplane_activateTxMeasObjects(
    const tx_measurement_objects_t config,
    halmplane_tx_stats_meas_cb_t cb)
{
  capture_source_as_str(
    int (*halmplane_activateTxMeasObjects)(tx_measurement_objects_t, halmplane_tx_stats_meas_cb_t), ftag);
    
    halmplane_activateTxMeasObjects = (int (*)
    (tx_measurement_objects_t, halmplane_tx_stats_meas_cb_t))hal_loader->get_function(ftag);

    if(halmplane_activateTxMeasObjects)
    {
      std::cout << "wrapper " ;
      return halmplane_activateTxMeasObjects(config, cb);
    }
    else 
    {
      std::cout <<"function does not exist." << std::endl;
    }
    return 0;  
}

//MplaneHardware

halmplane_error_t halmplane_get_energysaving_state(hw_component_t *hw_comp)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_energysaving_state)(hw_component_t*), ftag);
   
  halmplane_get_energysaving_state = (halmplane_error_t (*)
  (hw_component_t*))hal_loader->get_function(ftag);

  if(halmplane_get_energysaving_state)
  {
    std::cout << "wrapper " ;
    return halmplane_get_energysaving_state(hw_comp);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;   
}

halmplane_error_t halmplane_get_availability_type(hw_component_t* hw_comp)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_availability_type)(hw_component_t*), ftag);
  
  halmplane_get_availability_type = (halmplane_error_t (*)
  (hw_component_t*))hal_loader->get_function(ftag);
  if(halmplane_get_availability_type)
  {
    std::cout << "wrapper " ;
    return halmplane_get_availability_type(hw_comp);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

halmplane_error_t halmplane_get_label_content(hw_component_t* hw_comp)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_label_content)(hw_component_t*), ftag);
  
  halmplane_get_label_content = (halmplane_error_t (*)
  (hw_component_t*))hal_loader->get_function(ftag);
  if(halmplane_get_label_content)
  {
    std::cout << "wrapper " ;
    return halmplane_get_label_content(hw_comp);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;   
}

halmplane_error_t halmplane_get_product_code(hw_component_t* hw_comp)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_product_code)(hw_component_t*), ftag);
  
  halmplane_get_product_code = (halmplane_error_t (*)
  (hw_component_t*))hal_loader->get_function(ftag);
  if(halmplane_get_product_code)
  {
    std::cout << "wrapper " ;
    return halmplane_get_product_code(hw_comp);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_is_energy_saving_enabled(hw_component_t* hw_comp)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_is_energy_saving_enabled)(hw_component_t*), ftag);
  
  halmplane_is_energy_saving_enabled = (halmplane_error_t (*)
  (hw_component_t*))hal_loader->get_function(ftag);
  if(halmplane_is_energy_saving_enabled)
  {
    std::cout << "wrapper " ;
    return halmplane_is_energy_saving_enabled(hw_comp);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_get_dying_gasp_support(hw_component_t* hw_comp)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_dying_gasp_support)(hw_component_t*), ftag);
  
  halmplane_get_dying_gasp_support = (halmplane_error_t (*)
  (hw_component_t*))hal_loader->get_function(ftag);
  if(halmplane_get_dying_gasp_support)
  {
    std::cout << "wrapper " ;
    return halmplane_get_dying_gasp_support(hw_comp);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

halmplane_error_t halmplane_get_last_service_date(hw_component_t* hw_comp)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_last_service_date)(hw_component_t*), ftag);
  
  halmplane_get_last_service_date = (halmplane_error_t (*)
  (hw_component_t*))hal_loader->get_function(ftag);
  if(halmplane_get_last_service_date)
  {
    std::cout << "wrapper " ;
    return halmplane_get_last_service_date(hw_comp);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}
halmplane_error_t halmplane_get_o_ran_name(hw_component_t* hw_comp)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_o_ran_name)(hw_component_t*), ftag);
  
  halmplane_get_o_ran_name = (halmplane_error_t (*)
  (hw_component_t*))hal_loader->get_function(ftag);
  if(halmplane_get_o_ran_name)
  {
    std::cout << "wrapper " ;
    return halmplane_get_o_ran_name(hw_comp);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;
}

bool halmplane_get_ietf_hardware(ietf_hardware_t* hw)
{
  capture_source_as_str(
  bool (*halmplane_get_ietf_hardware)(ietf_hardware_t*), ftag);
  
  halmplane_get_ietf_hardware = (bool (*)
  (ietf_hardware_t*))hal_loader->get_function(ftag);
  if(halmplane_get_ietf_hardware)
  {
    std::cout << "wrapper " ;
    return halmplane_get_ietf_hardware(hw);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;

}

int halmplane_registerHwStateChange(
    halmplane_notificationHwStateChange_cb_t cb)
{
  capture_source_as_str(
  int (*halmplane_registerHwStateChange)(halmplane_notificationHwStateChange_cb_t), ftag);
  
  halmplane_registerHwStateChange = (int (*)
  (halmplane_notificationHwStateChange_cb_t))hal_loader->get_function(ftag);
  if(halmplane_registerHwStateChange)
  {
    std::cout << "wrapper " ;
    return halmplane_registerHwStateChange(cb);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

int halmplane_registerHwStateOper(
    halmplane_notificationHwStateOper_cb_t cb)
{
  capture_source_as_str(
  int (*halmplane_registerHwStateOper)(halmplane_notificationHwStateOper_cb_t), ftag);
  
  halmplane_registerHwStateOper = (int (*)
  (halmplane_notificationHwStateOper_cb_t))hal_loader->get_function(ftag);
  if(halmplane_registerHwStateOper)
  {
    std::cout << "wrapper " ;
    return halmplane_registerHwStateOper(cb);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

//MplaneFan 
halmplane_error_t halmplane_get_fan_present_and_operating(
    fan_state_t* fan_state)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_fan_present_and_operating)(fan_state_t*), ftag);
  
  halmplane_get_fan_present_and_operating = (halmplane_error_t (*)
  (fan_state_t*))hal_loader->get_function(ftag);
  if(halmplane_get_fan_present_and_operating)
  {
    std::cout << "wrapper " ;
    return halmplane_get_fan_present_and_operating(fan_state);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

halmplane_error_t halmplane_get_fan_name(
    fan_state_t* fan_state)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_fan_name)(fan_state_t*), ftag);
  
  halmplane_get_fan_name = (halmplane_error_t (*)
  (fan_state_t*))hal_loader->get_function(ftag);
  if(halmplane_get_fan_name)
  {
    std::cout << "wrapper " ;
    return halmplane_get_fan_name(fan_state);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

halmplane_error_t halmplane_get_fan_location(
    fan_state_t* fan_state)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_fan_location)(fan_state_t*), ftag);
  
  halmplane_get_fan_location = (halmplane_error_t (*)
  (fan_state_t*))hal_loader->get_function(ftag);
  if(halmplane_get_fan_location)
  {
    std::cout << "wrapper " ;
    return halmplane_get_fan_location(fan_state);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

halmplane_error_t halmplane_get_fan_vendor_code(
    fan_state_t* fan_state)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_fan_vendor_code)(fan_state_t*), ftag);
  
  halmplane_get_fan_vendor_code = (halmplane_error_t (*)
  (fan_state_t*))hal_loader->get_function(ftag);
  if(halmplane_get_fan_vendor_code)
  {
    std::cout << "wrapper " ;
    return halmplane_get_fan_vendor_code(fan_state);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

halmplane_error_t halmplane_get_fan_speed(
    fan_state_t* fan_state)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_fan_speed)(fan_state_t*), ftag);
  
  halmplane_get_fan_speed = (halmplane_error_t (*)
  (fan_state_t*))hal_loader->get_function(ftag);
  if(halmplane_get_fan_speed)
  {
    std::cout << "wrapper " ;
    return halmplane_get_fan_speed(fan_state);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

halmplane_error_t halmplane_get_fan_target_speed(
    fan_state_t* fan_state)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_fan_target_speed)(fan_state_t*), ftag);
  
  halmplane_get_fan_target_speed = (halmplane_error_t (*)
  (fan_state_t*))hal_loader->get_function(ftag);
  if(halmplane_get_fan_target_speed)
  {
    std::cout << "wrapper " ;
    return halmplane_get_fan_target_speed(fan_state);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

// MplaneAntennaCalibrtion
halmplane_error_t halmplane_start_antenna_calibration(
    const antenna_calibration_data_t* antenna_data)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_start_antenna_calibration)(const antenna_calibration_data_t*), ftag);
  
  halmplane_start_antenna_calibration = (halmplane_error_t (*)
  (const antenna_calibration_data_t*))hal_loader->get_function(ftag);
  if(halmplane_start_antenna_calibration)
  {
    std::cout << "wrapper " ;
    return halmplane_start_antenna_calibration(antenna_data);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;    
}

//MplaneAld

halmplane_error_t halmplane_ald_get_counters(
    halmplane_ald_communication_output_t* ald_status)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_ald_get_counters)(halmplane_ald_communication_output_t*), ftag);
  
  halmplane_ald_get_counters = (halmplane_error_t (*)
  (halmplane_ald_communication_output_t*))hal_loader->get_function(ftag);
  if(halmplane_ald_get_counters)
  {
    std::cout << "wrapper " ;
    return halmplane_ald_get_counters(ald_status);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;   
}

halmplane_error_t halmplane_ald_get_status(
    halmplane_ald_communication_output_t* ald_status)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_ald_get_status)(halmplane_ald_communication_output_t*), ftag);
  
  halmplane_ald_get_status = (halmplane_error_t (*)
  (halmplane_ald_communication_output_t*))hal_loader->get_function(ftag);
  if(halmplane_ald_get_status)
  {
    std::cout << "wrapper " ;
    return halmplane_ald_get_status(ald_status);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;   
}

halmplane_error_t halmplane_ald_response(
    halmplane_ald_communication_input_s* ald_req, uint16_t msg_size)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_ald_response)(halmplane_ald_communication_input_s*, uint16_t), ftag);
  
  halmplane_ald_response = (halmplane_error_t (*)
  (halmplane_ald_communication_input_s*, uint16_t))hal_loader->get_function(ftag);
  if(halmplane_ald_response)
  {
    std::cout << "wrapper " ;
    return halmplane_ald_response(ald_req, msg_size);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

halmplane_error_t halmplane_ald_set_receive_mode(
    halmplane_ald_communication_input_s* ald_req, uint16_t msg_size)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_ald_set_receive_mode)(halmplane_ald_communication_input_s*, uint16_t), ftag);
  
  halmplane_ald_set_receive_mode = (halmplane_error_t (*)
  (halmplane_ald_communication_input_s*, uint16_t))hal_loader->get_function(ftag);
  if(halmplane_ald_set_receive_mode)
  {
    std::cout << "wrapper " ;
    return halmplane_ald_set_receive_mode(ald_req, msg_size);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;   
}

halmplane_error_t halmplane_ald_request(
    halmplane_ald_communication_input_t* ald_req, uint16_t msg_size)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_ald_request)(halmplane_ald_communication_input_t*, uint16_t), ftag);
  
  halmplane_ald_request = (halmplane_error_t (*)
  (halmplane_ald_communication_input_t*, uint16_t))hal_loader->get_function(ftag);
  if(halmplane_ald_request)
  {
    std::cout << "wrapper " ;
    return halmplane_ald_request(ald_req, msg_size);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE; 
}

//MplaneBeamforming.h
halmplane_error_t halmplane_apply_beamforming_file(char* filepath)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_apply_beamforming_file)(char*), ftag);
  
  halmplane_apply_beamforming_file = (halmplane_error_t (*)
  (char*))hal_loader->get_function(ftag);

  if(halmplane_apply_beamforming_file)
  {
    std::cout << "wrapper " ;
    return halmplane_apply_beamforming_file(filepath);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE; 
}

halmplane_error_t halmplane_set_ptp_config(const ptp_config_t ptp_config)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_set_ptp_config)(const ptp_config_t), ftag);
  
  halmplane_set_ptp_config = (halmplane_error_t (*)
  (const ptp_config_t))hal_loader->get_function(ftag);

  if(halmplane_set_ptp_config)
  {
    std::cout << "wrapper " ;
    return halmplane_set_ptp_config(ptp_config);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE; 
}

halmplane_error_t halmplane_get_ptp_status(ptp_status_t* ptp_status)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_ptp_status)(ptp_status_t*), ftag);
  
  halmplane_get_ptp_status = (halmplane_error_t (*)
  (ptp_status_t*))hal_loader->get_function(ftag);

  if(halmplane_get_ptp_status)
  {
    std::cout << "wrapper " ;
    return halmplane_get_ptp_status(ptp_status);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE; 
}

halmplane_error_t halmplane_set_synce_config(const synce_config_t synce_config)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_set_synce_config)(const synce_config_t), ftag);
  
  halmplane_set_synce_config = (halmplane_error_t (*)
  (const synce_config_t))hal_loader->get_function(ftag);

  if(halmplane_set_synce_config)
  {
    std::cout << "wrapper " ;
    return halmplane_set_synce_config(synce_config);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;   
}

halmplane_error_t halmplane_get_synce_status(synce_status_t* synce_status)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_synce_status)(synce_status_t*), ftag);
  
  halmplane_get_synce_status = (halmplane_error_t (*)
  (synce_status_t*))hal_loader->get_function(ftag);

  if(halmplane_get_synce_status)
  {
    std::cout << "wrapper " ;
    return halmplane_get_synce_status(synce_status);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

halmplane_error_t halmplane_set_gnss_config(const gnss_config_t gnss_config)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_set_gnss_config)(const gnss_config_t), ftag);
  
  halmplane_set_gnss_config = (halmplane_error_t (*)
  (const gnss_config_t))hal_loader->get_function(ftag);

  if(halmplane_set_gnss_config)
  {
    std::cout << "wrapper " ;
    return halmplane_set_gnss_config(gnss_config);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;  
}

halmplane_error_t halmplane_get_gnss_status(gnss_status_t* gnss_status)
{
  capture_source_as_str(
  halmplane_error_t (*halmplane_get_gnss_status)(gnss_status_t*), ftag);
  
  halmplane_get_gnss_status = (halmplane_error_t (*)
  (gnss_status_t*))hal_loader->get_function(ftag);

  if(halmplane_get_gnss_status)
  {
    std::cout << "wrapper " ;
    return halmplane_get_gnss_status(gnss_status);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;    
}

//MplaneDelayMgmt

int halmplane_setDUToRUDelayMgmnt(o_ru_delay_management_s* ru_delay_mgmt)
{
  capture_source_as_str(
  int (*halmplane_setDUToRUDelayMgmnt)(o_ru_delay_management_s*), ftag);
  
  halmplane_setDUToRUDelayMgmnt = (int (*)
  (o_ru_delay_management_s*))hal_loader->get_function(ftag);

  if(halmplane_setDUToRUDelayMgmnt)
  {
    std::cout << "wrapper " ;
    return halmplane_setDUToRUDelayMgmnt(ru_delay_mgmt);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;    
}

//MplaneModuleCapability

int halmplane_setDUToRUModuleCapability(module_capability_t* mod_capability)
{
  capture_source_as_str(
  int (*halmplane_setDUToRUModuleCapability)(module_capability_t*), ftag);
  
  halmplane_setDUToRUModuleCapability = (int (*)
  (module_capability_t*))hal_loader->get_function(ftag);

  if(halmplane_setDUToRUModuleCapability)
  {
    std::cout << "wrapper " ;
    return halmplane_setDUToRUModuleCapability(mod_capability);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE;    
}

uint32_t halmplane_get_cu_supervison_interval(void)
{
  capture_source_as_str(
  uint32_t (*halmplane_get_cu_supervison_interval)(void), ftag);
  
  halmplane_get_cu_supervison_interval = (uint32_t (*)
  (void))hal_loader->get_function(ftag);

  if(halmplane_get_cu_supervison_interval)
  {
    std::cout << "wrapper " ;
    return halmplane_get_cu_supervison_interval();
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE; 
}

uint32_t halmplane_set_cu_supervison_interval(
    uint32_t cu_monitoring_interval)
{
  capture_source_as_str(
  uint32_t (*halmplane_set_cu_supervison_interval)(uint32_t), ftag);
  
  halmplane_set_cu_supervison_interval = (uint32_t (*)
  (uint32_t))hal_loader->get_function(ftag);

  if(halmplane_set_cu_supervison_interval)
  {
    std::cout << "wrapper " ;
    return halmplane_set_cu_supervison_interval(cu_monitoring_interval);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE; 
}

//MplaneTransceiver
int halmplane_get_port_transceivers(port_transceivers_t* transceivers)
{
  capture_source_as_str(
  int (*halmplane_get_port_transceivers)(port_transceivers_t*), ftag);
  
  halmplane_get_port_transceivers = (int (*)
  (port_transceivers_t*))hal_loader->get_function(ftag);

  if(halmplane_get_port_transceivers)
  {
    std::cout << "wrapper " ;
    return halmplane_get_port_transceivers(transceivers);
  }
  else 
  {
    std::cout <<"function does not exist." << std::endl;
  }
  return NONE; 
}
