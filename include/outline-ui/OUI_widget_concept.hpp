#pragma once

#include <tuple>
#include <concepts>
#include <utility>

#include "OUI_types.hpp"

namespace outlineUI {
    template<class T, class coord_type>
    concept Widget = requires(T& w) {
        // 境界を返すbundary_area関数を要求する
        // const関数も定義する
        { w.boundary_area() } -> std::same_as<const boundary_t<coord_type>>;
        { std::as_const(w).boundary_area() } -> std::same_as<const boundary_t<coord_type>>;
        w.boundary_area(boundary_t<coord_type>{});
    };
}
