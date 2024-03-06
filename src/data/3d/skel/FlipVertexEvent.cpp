/**
 * @file   data/3d/skel/FlipVertexEvent.cpp
 * @author Gernot Walzl
 * @date   2012-11-22
 */

#include "data/3d/skel/FlipVertexEvent.h"

#include "debug.h"
#include "data/3d/Vertex.h"
#include "data/3d/skel/Node.h"
#include "data/3d/skel/SkelVertexData.h"

namespace data { namespace _3d { namespace skel {

FlipVertexEvent::FlipVertexEvent() {
    type_ = AbstractEvent::FLIP_VERTEX_EVENT;
}

FlipVertexEvent::~FlipVertexEvent() {
    node_.reset();
    vertex_1_.reset();
    vertex_2_.reset();
    facet_1_.reset();
    facet_2_.reset();
}

FlipVertexEventSPtr FlipVertexEvent::create() {
    FlipVertexEventSPtr result = FlipVertexEventSPtr(new FlipVertexEvent());
    return result;
}

NodeSPtr FlipVertexEvent::getNode() const {
    DEBUG_SPTR(node_);
    return node_;
}

void FlipVertexEvent::setNode(NodeSPtr node) {
    this->node_ = node;
}

double FlipVertexEvent::getOffset() const {
    double result = 0.0;
    if (node_) {
        result = node_->getOffset();
    }
    return result;
}

VertexSPtr FlipVertexEvent::getVertex1() const {
    DEBUG_SPTR(vertex_1_);
    return vertex_1_;
}

void FlipVertexEvent::setVertex1(VertexSPtr vertex_1) {
    this->vertex_1_ = vertex_1;
}

VertexSPtr FlipVertexEvent::getVertex2() const {
    DEBUG_SPTR(vertex_2_);
    return vertex_2_;
}

void FlipVertexEvent::setVertex2(VertexSPtr vertex_2) {
    this->vertex_2_ = vertex_2;
}

FacetSPtr FlipVertexEvent::getFacet1() const {
    DEBUG_SPTR(facet_1_);
    return facet_1_;
}

void FlipVertexEvent::setFacet1(FacetSPtr facet_1) {
    this->facet_1_ = facet_1;
}

FacetSPtr FlipVertexEvent::getFacet2() const {
    DEBUG_SPTR(facet_2_);
    return facet_2_;
}

void FlipVertexEvent::setFacet2(FacetSPtr facet_2) {
    this->facet_2_ = facet_2;
}

void FlipVertexEvent::setHighlight(bool highlight) {
    if (!vertex_1_->hasData()) {
        SkelVertexData::create(vertex_1_);
    }
    vertex_1_->getData()->setHighlight(highlight);
    if (!vertex_2_->hasData()) {
        SkelVertexData::create(vertex_2_);
    }
    vertex_2_->getData()->setHighlight(highlight);
}

} } }
