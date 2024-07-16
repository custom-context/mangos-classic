#include "EntryView.h"

namespace entry::view {

template<> auto SpellView::GetAttributesExtensions<1>() const noexcept {
    return GetRaw()->AttributesEx;
}

template<> auto SpellView::GetAttributesExtensions<2>() const noexcept {
    return GetRaw()->AttributesEx2;
}

template<> auto SpellView::GetAttributesExtensions<3>() const noexcept {
    return GetRaw()->AttributesEx3;
}

template<> auto SpellView::GetAttributesExtensions<4>() const noexcept {
    return GetRaw()->AttributesEx4;
}

} // namespace entry::view