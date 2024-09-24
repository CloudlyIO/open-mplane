#ifndef WRAPPER_H_
#define WRAPPER_H_

#include <iostream>
#include <memory>
 
#include "MplaneInterfaces.h"
#include "MplaneProcessingElements.h"
#include "MplaneUplaneConf.h"
#include "HalMplane.h"
#include "MplaneAlarms.h"
#include "MplaneEcpri.h"
#include "MplaneExternalio.h"
#include "MplanePerformanceMgmt.h"
#include "MplaneHardware.h"
#include "MplaneFan.h"
#include "MplaneAntennaCalibration.h"
#include "MplaneAld.h"
#include "MplaneBeamforming.h"
#include "MplaneSync.h"
#include "MplaneDelayMgmt.h"
#include "MplaneModuleCapability.h"
#include "MplaneSupervision.h"
#include "MplaneTransceiver.h"

// 

class Wrapper
{
  public:
  ~Wrapper()
  {
    std::cout << "Wrapper destructor is running" << std::endl;
  }

};

extern "C"
{
  void* function_map();
};

// // //HalMplane
// int _halmplane_init();
// int _halmplane_exit();


// // //MplaneInterfaces
// halmplane_error_t _halmplane_interface_update(interface_t* interface)__attribute__((weak));
// halmplane_error_t _halmplane_interface_update_description(
//   const char* name, const char* description);
// halmplane_error_t _halmplane_interface_update_type(
//   const char* name, const char* type);
// halmplane_error_t _halmplane_interface_update_enabled(
//   const char* name, bool enabled);
// halmplane_error_t _halmplane_interface_update_l2_mtu(
//   const char* name, int l2Mtu);
// halmplane_error_t _halmplane_interface_update_vlan_tagging(
//   const char* name, bool vlanTagging);
// halmplane_error_t _halmplane_interface_update_base_interface(
//   const char* name, const char* baseInterface);
// halmplane_error_t _halmplane_interface_update_vlan_id(
//   const char* name, int vlanId);
// halmplane_error_t _halmplane_interface_update_mac_address(
//       const char* name, const char* macAddress);

// // //MplaneProcessingElement module api
// halmplane_error_t _halmplane_update_ru_element(ru_elements_t* ru_element);

// // //MplaneUplaneConf
// int _halmplane_get_tx_array(const char* name, tx_array_t* tx_array);
// const char** _halmplane_get_tx_array_names();


// int _halmplane_get_low_level_tx_endpoint(const char* name, low_level_tx_endpoint_t* tx_endpoint);
// int _halmplane_get_low_level_tx_endpoints(low_level_tx_endpoint_t** tx_endpoints, int* n_endpoints);
// int _halmplane_get_rx_array(const char* name, rx_array_t* rx_arrays);
// const char** _halmplane_get_rx_array_names();
// int _halmplane_get_low_level_rx_endpoint(
//     const char* name, low_level_rx_endpoint_t* rx_endpoint);
// int _halmplane_get_low_level_rx_endpoints(
//     low_level_rx_endpoint_t** rx_endpoints, int* n_endpoints);
// int _halmplane_tx_carrier_state_change(
//     const char* name,
//     uint64_t chbw,
//     uint64_t center,
//     double gain,
//     const char* new_state,
//     int do_apply);

// int _halmplane_rx_carrier_state_change(
//     const char* name,
//     uint64_t chbw,
//     uint64_t center,
//     double gain_correction,
//     const char* new_state,
//     int do_apply);

// int _halmplane_setUPlaneConfiguration(user_plane_configuration_t* uplane_cfg);
// int _halmplane_update_tx_eaxc(const char* endpoint_name, e_axcid_t* eaxc);
// int _halmplane_update_rx_eaxc(const char* endpoint_name, e_axcid_t* eaxc);
// int _halmplane_update_rx_endpoint_compression(
//     const char* endpoint_name, compression_t* compression);
// int _halmplane_update_tx_endpoint_compression(
//     const char* endpoint_name, compression_t* compression);
// int _halmplane_update_rx_endpoint_compression_dyn_config(
//     const char* endpoint_name, dynamic_compression_configuration_t* config);
// int _halmplane_update_tx_endpoint_compression_dyn_config(
//     const char* endpoint_name, dynamic_compression_configuration_t* config);
// int _halmplane_register_rx_carrier_state_cb(halmplane_carrier_state_cb_t cb);

// int _halmplane_register_tx_carrier_state_cb(halmplane_carrier_state_cb_t cb);

// // MplaneAlarms
// int _halmplane_registerOranAlarmCallback(halmplane_oran_alarm_cb_t callback);

// //MplaneEcpri
// bool _halmplane_message5Enabled(void);
// #if 0
// bool _halmplane_set_ietf_hardware (halmplane_oran_hardware_t hw);
// #endif

// //MplaneExternalio
// halmplane_error_t _halmplane_get_io_value(external_io_t* io);
// halmplane_error_t _halmplane_set_io_value(output_setting_t* out_setting);

// //MplanePerformanceMgmt
// // //The API defined in MplanePerformance.cpp have been regestered only
// // int _halmplane_activateEpeMeasObjects(
// //     epe_measurement_objects_t config, halmplane_epe_meas_cb_t cb);

// // int _halmplane_registerOranPerfMeasCallback(halmplane_oran_perf_meas_cb_t callback);
// // const halmplane_oran_perf_meas_cb_t _get_perf_meas_cb_ptr(void);
// // int _halmplane_getRssi(uint8_t interface, double* rssiValue);
// // int _halmplane_configPerfMeasurementParams(
// //     performance_measurement_params_t* config);
// // int _halmplane_activateTransceiverMeasObjects(
// //     transceiver_measurement_objects_t config,
// //     halmplane_transceiver_meas_cb_t cb);
// // int _halmplane_activateRxWindowMeasObjects(
// //     rx_window_measurement_objects_t config,
// //     halmplane_rx_window_meas_cb_t cb);
// // int _halmplane_activateTxMeasObjects(
// //     const tx_measurement_objects_t config,
// //     halmplane_tx_stats_meas_cb_t cb);
// // int _halmplane_activateEpeMeasObjects(
// //     int config, int cb);

// //MplaneHardware
// halmplane_error_t _halmplane_get_energysaving_state(hw_component_t *hw_comp);
// halmplane_error_t _halmplane_get_availability_type(hw_component_t* hw_comp);
// halmplane_error_t _halmplane_get_label_content(hw_component_t* hw_comp);
// halmplane_error_t _halmplane_get_product_code(hw_component_t* hw_comp);
// halmplane_error_t _halmplane_is_energy_saving_enabled(hw_component_t* hw_comp);
// halmplane_error_t _halmplane_get_dying_gasp_support(hw_component_t* hw_comp);
// halmplane_error_t _halmplane_get_last_service_date(hw_component_t* hw_comp);
// halmplane_error_t _halmplane_get_o_ran_name(hw_component_t* hw_comp);
// bool _halmplane_get_ietf_hardware(ietf_hardware_t* hw);
// int _halmplane_registerHwStateChange(
//     halmplane_notificationHwStateChange_cb_t cb);
// int _halmplane_registerHwStateOper(
//     halmplane_notificationHwStateOper_cb_t cb);

// //MplaneFan
// // halmplane_error_t _halmplane_get_fan_present_and_operating(
// //     fan_state_t* fan_state);
// // halmplane_error_t _halmplane_get_fan_name(
// //     fan_state_t* fan_state);
// // halmplane_error_t _halmplane_get_fan_location(
// //     fan_state_t* fan_state);
// // halmplane_error_t _halmplane_get_fan_vendor_code(
// //     fan_state_t* fan_state);
// // halmplane_error_t _halmplane_get_fan_speed(
// //     fan_state_t* fan_state);
// // halmplane_error_t _halmplane_get_fan_target_speed(
// //     fan_state_t* fan_state);

// //MplaneAntennaCalibration.h
// halmplane_error_t _halmplane_start_antenna_calibration(
//     const antenna_calibration_data_t* antenna_data);

// //MplaneAld
// halmplane_error_t _halmplane_ald_get_counters(
//     const halmplane_ald_communication_output_t* ald_status);
// halmplane_error_t _halmplane_ald_get_status(
//     const halmplane_ald_communication_output_t* ald_status);
// halmplane_error_t _halmplane_ald_response(
//     halmplane_ald_communication_input_s* ald_req, uint16_t msg_size);
// halmplane_error_t _halmplane_ald_set_receive_mode(
//     halmplane_ald_communication_input_s* ald_req, uint16_t msg_size);
// halmplane_error_t _halmplane_ald_request(
//     halmplane_ald_communication_input_t* ald_req, uint16_t msg_size);

// //MplaneBeamforming.h
// halmplane_error_t _halmplane_apply_beamforming_file(char* filepath);

// //MplaneSync
// halmplane_error_t _halmplane_set_ptp_config(const ptp_config_t ptp_config);
// halmplane_error_t _halmplane_get_ptp_status(ptp_status_t* ptp_status);
// halmplane_error_t _halmplane_set_synce_config(const synce_config_t synce_config);
// halmplane_error_t _halmplane_get_synce_status(synce_status_t* synce_status);
// halmplane_error_t _halmplane_set_gnss_config(const gnss_config_t gnss_config);
// halmplane_error_t _halmplane_get_gnss_status(gnss_status_t* gnss_status);

// //MplaneDeleyMgmt
// int _halmplane_setDUToRUDelayMgmnt(o_ru_delay_management_s* ru_delay_mgmt);

// //MplaneModuleCapability
// int _halmplane_setDUToRUModuleCapability(module_capability_t* mod_capability);

// //MplaneSupervision
// uint32_t _halmplane_get_cu_supervison_interval(void);
// uint32_t _halmplane_set_cu_supervison_interval(
//     uint32_t cu_monitoring_interval);

#define capture_source_as_str(src, strname) src; const static char* strname = #src;

#endif /* WRAPPER_H_ */
