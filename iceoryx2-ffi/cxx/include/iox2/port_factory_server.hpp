// Copyright (c) 2025 Contributors to the Eclipse Foundation
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

#ifndef IOX2_PORTFACTORY_SERVER_HPP
#define IOX2_PORTFACTORY_SERVER_HPP

#include "iox/builder_addendum.hpp"
#include "iox/expected.hpp"
#include "iox2/server.hpp"
#include "iox2/server_error.hpp"
#include "iox2/service_type.hpp"
#include "iox2/unable_to_deliver_strategy.hpp"

namespace iox2 {
/// Factory to create a new [`Server`] port/endpoint for
/// [`MessagingPattern::RequestResponse`](crate::service::messaging_pattern::MessagingPattern::RequestResponse)
/// based communication.
template <ServiceType Service,
          typename RequestPayload,
          typename RequestHeader,
          typename ResponsePayload,
          typename ResponseHeader>
class PortFactoryServer {
    /// Sets the [`UnableToDeliverStrategy`] which defines how the [`Server`] shall behave
    /// when a [`Client`](crate::port::client::Client) cannot receive a
    /// [`Response`](crate::response::Response) since
    /// its internal buffer is full.
    IOX_BUILDER_OPTIONAL(UnableToDeliverStrategy, unable_to_deliver_strategy);

    /// Defines the maximum number of [`ResponseMut`](crate::response_mut::ResponseMut) that
    /// the [`Server`] can loan in parallel per
    /// [`ActiveRequest`](crate::active_request::ActiveRequest).
    IOX_BUILDER_OPTIONAL(uint64_t, max_loaned_responses_per_request);

  public:
    PortFactoryServer(const PortFactoryServer&) = delete;
    PortFactoryServer(PortFactoryServer&&) = default;
    auto operator=(const PortFactoryServer&) -> PortFactoryServer& = delete;
    auto operator=(PortFactoryServer&&) -> PortFactoryServer& = default;
    ~PortFactoryServer() = default;

    /// Creates a new [`Server`] or returns a [`ServerCreateError`] on failure.
    auto create() && -> iox::expected<Server<Service, RequestPayload, RequestHeader, ResponsePayload, ResponseHeader>,
                                      ServerCreateError>;

  private:
    template <ServiceType, typename, typename, typename, typename>
    friend class PortFactoryRequestResponse;

    explicit PortFactoryServer(/*iox2_port_factory_server_builder_h handle*/);

    // iox2_port_factory_server_builder_h m_handle = nullptr;
};

template <ServiceType Service,
          typename RequestPayload,
          typename RequestHeader,
          typename ResponsePayload,
          typename ResponseHeader>
inline auto
PortFactoryServer<Service, RequestPayload, RequestHeader, ResponsePayload, ResponseHeader>::create() && -> iox::
    expected<Server<Service, RequestPayload, RequestHeader, ResponsePayload, ResponseHeader>, ServerCreateError> {
    IOX_TODO();
}

template <ServiceType Service,
          typename RequestPayload,
          typename RequestHeader,
          typename ResponsePayload,
          typename ResponseHeader>
inline PortFactoryServer<Service, RequestPayload, RequestHeader, ResponsePayload, ResponseHeader>::PortFactoryServer(
    /*iox2_port_factory_server_builder_h handle*/) {
    IOX_TODO();
}
} // namespace iox2
#endif
