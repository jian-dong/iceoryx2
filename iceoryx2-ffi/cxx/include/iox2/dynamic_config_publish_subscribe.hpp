// Copyright (c) 2024 Contributors to the Eclipse Foundation
//
// See the NOTICE file(s) distributed with this work for additional
// information regarding copyright ownership.
//
// This program and the accompanying materials are made available under the
// terms of the Apache Software License 2.0 which is available at
// https://www.apache.org/licenses/LICENSE-2.0, or the MIT license
// which is available at https://opensource.org/licenses/MIT.
//
// SPDX-License-Identifier: Apache-2.0 OR MIT

#ifndef IOX2_DYNAMIC_CONFIG_PUBLISH_SUBSCRIBE_HPP
#define IOX2_DYNAMIC_CONFIG_PUBLISH_SUBSCRIBE_HPP

#include "iox2/internal/iceoryx2.hpp"

#include <cstdint>

namespace iox2 {

/// The dynamic configuration of an
/// [`MessagingPattern::PublishSubscribe`] based service. Contains dynamic
/// parameters like the connected endpoints etc..
class DynamicConfigPublishSubscribe {
  public:
    DynamicConfigPublishSubscribe(const DynamicConfigPublishSubscribe&) = delete;
    DynamicConfigPublishSubscribe(DynamicConfigPublishSubscribe&&) = delete;
    auto operator=(const DynamicConfigPublishSubscribe&) -> DynamicConfigPublishSubscribe& = delete;
    auto operator=(DynamicConfigPublishSubscribe&&) -> DynamicConfigPublishSubscribe& = delete;
    ~DynamicConfigPublishSubscribe() = default;

    /// Returns how many [`Publisher`] ports are currently connected.
    auto number_of_publishers() const -> uint64_t;

    /// Returns how many [`Subscriber`] ports are currently connected.
    auto number_of_subscribers() const -> uint64_t;

  private:
    template <ServiceType, typename, typename>
    friend class PortFactoryPublishSubscribe;

    explicit DynamicConfigPublishSubscribe(iox2_port_factory_pub_sub_h handle);

    iox2_port_factory_pub_sub_h m_handle = nullptr;
};
} // namespace iox2

#endif
