/*
 * OpenVMP, 2022
 *
 * Author: Roman Kuzmenko
 * Created: 2022-09-24
 *
 * Licensed under Apache License, Version 2.0.
 */

#include <functional>

#include "modbus/config.hpp"
#include "modbus/implementation.hpp"
#include "modbus/protocol.hpp"
#include "yaml-cpp/yaml.h"

namespace modbus {

void Implementation::get_com_event_log(
    const std::shared_ptr<modbus::srv::GetComEventLog::Request> request,
    std::shared_ptr<modbus::srv::GetComEventLog::Response> response) {
  auto ret = get_com_event_log_handler_real_(request, response);

  RCLCPP_DEBUG(node_->get_logger(), "Received GetComEventLog response");

  update_on_response_(request->leaf_id, MODBUS_FC_GET_COM_EVENT_LOG,
                      response->exception_code, ret);
}

void Implementation::read_device_id(
    const std::shared_ptr<modbus::srv::ReadDeviceId::Request> request,
    std::shared_ptr<modbus::srv::ReadDeviceId::Response> response) {
  auto ret = read_device_id_handler_real_(request, response);

  RCLCPP_DEBUG(node_->get_logger(), "Received ReadDeviceId response");

  update_on_response_(request->leaf_id, MODBUS_FC_READ_DEVICE_ID,
                      response->exception_code, ret);
}

}  // namespace modbus