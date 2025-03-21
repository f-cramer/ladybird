/*
 * Copyright (c) 2022, Andreas Kling <andreas@ladybird.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibJS/Runtime/VM.h>
#include <LibWeb/Bindings/NodeFilterPrototype.h>
#include <LibWeb/DOM/NodeFilter.h>
#include <LibWeb/WebIDL/ExceptionOr.h>

namespace Web::DOM {

GC_DEFINE_ALLOCATOR(NodeFilter);

GC::Ref<NodeFilter> NodeFilter::create(JS::Realm& realm, WebIDL::CallbackType& callback)
{
    return realm.create<NodeFilter>(realm, callback);
}

NodeFilter::NodeFilter(JS::Realm& realm, WebIDL::CallbackType& callback)
    : PlatformObject(realm.intrinsics().object_prototype())
    , m_callback(callback)
{
}

void NodeFilter::visit_edges(Cell::Visitor& visitor)
{
    Base::visit_edges(visitor);
    visitor.visit(m_callback);
}

}
