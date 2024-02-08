#pragma once

#include <string>
#include "../OUI_widget_concept.hpp"
#include "../OUI_types.hpp"

namespace outlineUI::widget {
    template <class coord_type>
    struct Button {
        using boundary_type = outlineUI::boundary_t<coord_type>;

        std::string text;
        boundary_type button_area;
        bool is_pressed;

        const boundary_type boundary_area() noexcept {
            return button_area;
        }

        const boundary_type boundary_area() const noexcept {
            return button_area;
        }

        void boundary_area(const boundary_type& area) noexcept {
            button_area = area;
        }

        const bool pressed() const {
            return is_pressed;
        }

        void push() {
            is_pressed = true;
        }

        void release() {
            is_pressed = false;
        }
    };
    
    static_assert(outlineUI::Widget<Button<int>, int>);
}