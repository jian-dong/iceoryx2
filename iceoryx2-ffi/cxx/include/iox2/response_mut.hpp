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

#ifndef IOX2_RESPONSE_MUT_HPP
#define IOX2_RESPONSE_MUT_HPP

#include "iox/assertions_addendum.hpp"
#include "iox/expected.hpp"
#include "iox2/header_request_response.hpp"
#include "iox2/port_error.hpp"
#include "iox2/service_type.hpp"

namespace iox2 {

/// Acquired by a [`ActiveRequest`](crate::active_request::ActiveRequest) with
///  * [`ActiveRequest::loan()`](crate::active_request::ActiveRequest::loan())
///
/// It stores the payload of the response that will be sent to the corresponding
/// [`PendingResponse`](crate::pending_response::PendingResponse) of the
/// [`Client`](crate::port::client::Client).
///
/// If the [`ResponseMut`] is not sent it will reelase the loaned memory when going out of
/// scope.
template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
class ResponseMut {
  public:
    ResponseMut(ResponseMut&& rhs) noexcept;
    auto operator=(ResponseMut&& rhs) noexcept -> ResponseMut&;
    ~ResponseMut() noexcept;

    ResponseMut(const ResponseMut&) = delete;
    auto operator=(const ResponseMut&) -> ResponseMut& = delete;

    auto operator*() const -> const ResponsePayload&;
    auto operator*() -> ResponsePayload&;
    auto operator->() const -> const ResponsePayload*;
    auto operator->() -> ResponsePayload*;

    /// Returns a reference to the
    /// [`ResponseHeader`](service::header::request_response::ResponseHeader).
    auto header() const -> ResponseHeaderRequestResponse&;

    /// Returns a reference to the user header of the response.
    template <typename T = ResponseHeader, typename = std::enable_if_t<!std::is_same_v<void, ResponseHeader>, T>>
    auto user_header() const -> const T&;

    /// Returns a mutable reference to the user header of the response.
    template <typename T = ResponseHeader, typename = std::enable_if_t<!std::is_same_v<void, ResponseHeader>, T>>
    auto user_header_mut() -> T&;

    /// Returns a reference to the payload of the response.
    auto payload() const -> const ResponsePayload&;

    /// Returns a mutable reference to the payload of the response.
    auto payload_mut() -> ResponsePayload&;

    /// Sends a [`ResponseMut`] to the corresponding
    /// [`PendingResponse`](crate::pending_response::PendingResponse) of the
    /// [`Client`](crate::port::client::Client).
    auto send() -> iox::expected<void, SendError>;

  private:
    template <ServiceType, typename, typename>
    friend class ResponseMutUninit;

    explicit ResponseMut();
    void drop();

    // iox2_response_mut_t m_response;
    // iox2_response_mut_h m_handle = nullptr;
};

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline ResponseMut<Service, ResponsePayload, ResponseHeader>::ResponseMut(ResponseMut&& rhs) noexcept {
    *this = std::move(rhs);
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline auto
ResponseMut<Service, ResponsePayload, ResponseHeader>::operator=([[maybe_unused]] ResponseMut&& rhs) noexcept
    -> ResponseMut& {
    IOX_TODO();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline ResponseMut<Service, ResponsePayload, ResponseHeader>::~ResponseMut() noexcept {
    drop();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline auto ResponseMut<Service, ResponsePayload, ResponseHeader>::operator*() const -> const ResponsePayload& {
    return payload();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline auto ResponseMut<Service, ResponsePayload, ResponseHeader>::operator*() -> ResponsePayload& {
    return payload_mut();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline auto ResponseMut<Service, ResponsePayload, ResponseHeader>::operator->() const -> const ResponsePayload* {
    return &payload();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline auto ResponseMut<Service, ResponsePayload, ResponseHeader>::operator->() -> ResponsePayload* {
    return &payload_mut();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline auto ResponseMut<Service, ResponsePayload, ResponseHeader>::header() const -> ResponseHeaderRequestResponse& {
    IOX_TODO();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
template <typename T, typename>
inline auto ResponseMut<Service, ResponsePayload, ResponseHeader>::user_header() const -> const T& {
    IOX_TODO();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
template <typename T, typename>
inline auto ResponseMut<Service, ResponsePayload, ResponseHeader>::user_header_mut() -> T& {
    IOX_TODO();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline auto ResponseMut<Service, ResponsePayload, ResponseHeader>::payload() const -> const ResponsePayload& {
    IOX_TODO();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline auto ResponseMut<Service, ResponsePayload, ResponseHeader>::payload_mut() -> ResponsePayload& {
    IOX_TODO();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline auto ResponseMut<Service, ResponsePayload, ResponseHeader>::send() -> iox::expected<void, SendError> {
    IOX_TODO();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline ResponseMut<Service, ResponsePayload, ResponseHeader>::ResponseMut() {
    IOX_TODO();
}

template <ServiceType Service, typename ResponsePayload, typename ResponseHeader>
inline void ResponseMut<Service, ResponsePayload, ResponseHeader>::drop() {
    IOX_TODO();
}

} // namespace iox2

#endif
